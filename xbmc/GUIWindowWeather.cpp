/*
 *      Copyright (C) 2005-2008 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "stdafx.h"
#include "GUIWindowWeather.h"
#include "GUIImage.h"
#include "utils/Weather.h"
#include "GUISettings.h"
#include "GUIWindowManager.h"
#include "Util.h"
#include "lib/libPython/XBPython.h"
#include "GUIDialogOK.h"

#define CONTROL_BTNREFRESH             2
#define CONTROL_SELECTLOCATION         3
#define CONTROL_LABELUPDATED          11
#define CONTROL_IMAGELOGO            101

#define CONTROL_STATICTEMP           223
#define CONTROL_STATICFEEL           224
#define CONTROL_STATICUVID           225
#define CONTROL_STATICWIND           226
#define CONTROL_STATICDEWP           227
#define CONTROL_STATICHUMI           228

#define CONTROL_LABELD0DAY            31
#define CONTROL_LABELD0HI             32
#define CONTROL_LABELD0LOW            33
#define CONTROL_LABELD0GEN            34
#define CONTROL_IMAGED0IMG            35

#define PARTNER_ID          "1004124588"   //weather.com partner id
#define PARTNER_KEY   "079f24145f208494"  //weather.com partner key

#define MAX_LOCATION                   3
#define LOCALIZED_TOKEN_FIRSTID      370
#define LOCALIZED_TOKEN_LASTID       395

DWORD timeToCallPlugin = 1000;
bool forceRefresh = false;

/*
FIXME'S
>strings are not centered
>weather.com dev account is mine not a general xbmc one
*/

CGUIWindowWeather::CGUIWindowWeather(void)
    : CGUIWindow(WINDOW_WEATHER, "MyWeather.xml")
{
  m_iCurWeather = 0;
#ifdef _USE_ZIP_


#endif
}

CGUIWindowWeather::~CGUIWindowWeather(void)
{}

bool CGUIWindowWeather::OnAction(const CAction &action)
{
  if (action.id == ACTION_PREVIOUS_MENU || action.id == ACTION_PARENT_DIR)
  {
    g_windowManager.PreviousWindow();
    return true;
  }
  return CGUIWindow::OnAction(action);
}

bool CGUIWindowWeather::OnMessage(CGUIMessage& message)
{
  switch ( message.GetMessage() )
  {
  case GUI_MSG_CLICKED:
    {
      int iControl = message.GetSenderId();
      if (iControl == CONTROL_BTNREFRESH)
      {
        forceRefresh = true;
        CallPlugin();
      }
      else if (iControl == CONTROL_SELECTLOCATION)
      {
        // stop the plugin timer here, so the user has a full second
        if (m_pluginTimer.IsRunning())
          m_pluginTimer.Stop();

        CGUIMessage msg(GUI_MSG_ITEM_SELECTED,GetID(),CONTROL_SELECTLOCATION);
        g_windowManager.SendMessage(msg);
        m_iCurWeather = msg.GetParam1();

        CStdString strLabel=g_weatherManager.GetLocation(m_iCurWeather);
        int iPos = strLabel.ReverseFind(", ");
        if (iPos)
        {
          CStdString strLabel2(strLabel);
          strLabel = strLabel2.substr(0,iPos);
        }

        SET_CONTROL_LABEL(CONTROL_SELECTLOCATION,strLabel);
        Refresh();
      }
    }
    break;
  case GUI_MSG_NOTIFY_ALL:
    if (message.GetParam1() == GUI_MSG_WINDOW_RESET)
    {
      g_weatherManager.Reset();
      return true;
    }
    else if (message.GetParam1() == GUI_MSG_WEATHER_FETCHED)
    {
      UpdateLocations();
      SetProperties();
      if (IsActive())
        m_pluginTimer.StartZero();
      else
        CallPlugin();
    }
    break;
  case GUI_MSG_WINDOW_INIT:
    {
      if (g_guiSettings.GetString("weather.plugin").IsEmpty())
      {
        CGUIDialogOK::ShowAndGetInput(8,24023,20022,20022);
        g_windowManager.PreviousWindow();
        return true;
      }
    }
    break;
  default:
    break;
  }

  return CGUIWindow::OnMessage(message);
}

void CGUIWindowWeather::OnInitWindow()
{
  // call UpdateButtons() so that we start with our initial stuff already present
  UpdateButtons();
  UpdateLocations();
  CGUIWindow::OnInitWindow();
}

void CGUIWindowWeather::UpdateLocations()
{
  if (!IsActive()) return;

  CGUIMessage msg(GUI_MSG_LABEL_RESET,GetID(),CONTROL_SELECTLOCATION);
  g_windowManager.SendMessage(msg);
  CGUIMessage msg2(GUI_MSG_LABEL_ADD,GetID(),CONTROL_SELECTLOCATION);

  unsigned int maxLocations = g_weatherManager.GetMaxLocations();
  for (unsigned int i = 0; i < maxLocations; i++)
  {
    char *szLocation = g_weatherManager.GetLocation(i);
    if (!szLocation) continue;
    CStdString strLabel(szLocation);
    if (strlen(szLocation) > 1) //got the location string yet?
    {
      int iPos = strLabel.ReverseFind(", ");
      if (iPos)
      {
        CStdString strLabel2(strLabel);
        strLabel = strLabel2.substr(0,iPos);
      }
      msg2.SetParam1(i);
      msg2.SetLabel(strLabel);
      g_windowManager.SendMessage(msg2);
    }
    else
    {
      strLabel.Format("AreaCode %i", i + 1);

      msg2.SetLabel(strLabel);
      msg2.SetParam1(i);
      g_windowManager.SendMessage(msg2);
    }
    if (i==m_iCurWeather)
      SET_CONTROL_LABEL(CONTROL_SELECTLOCATION,strLabel);
  }

  CONTROL_SELECT_ITEM(CONTROL_SELECTLOCATION, m_iCurWeather);
}

void CGUIWindowWeather::UpdateButtons()
{
    CONTROL_ENABLE(CONTROL_BTNREFRESH);

  SET_CONTROL_LABEL(CONTROL_BTNREFRESH, 184);   //Refresh

}

void CGUIWindowWeather::FrameMove()
{
  // update our controls
  UpdateButtons();

  // call weather plugin
  if (m_pluginTimer.IsRunning() && m_pluginTimer.GetElapsedMilliseconds() > timeToCallPlugin)
  {
    m_pluginTimer.Stop();
    CallPlugin();
  }

  CGUIWindow::FrameMove();
}

//Do a complete download, parse and update
void CGUIWindowWeather::Refresh()
{
  g_weatherManager.SetArea(m_iCurWeather);
  g_weatherManager.Refresh();
}

void CGUIWindowWeather::SetProperties()
{
  // Current weather
  SetProperty("Location", g_weatherManager.GetLocation(m_iCurWeather));
  SetProperty("Location.Index", int(m_iCurWeather + 1));
}

void CGUIWindowWeather::CallPlugin()
{
  SetProperty("Weather.IsFetched", false);

  if (g_guiSettings.GetString("weather.plugin").IsEmpty()) return;

  // create the full path to the plugin
  CStdString plugin = "special://home/plugins/weather/" + g_guiSettings.GetString("weather.plugin") + "/default.py";

  // initialize our sys.argv variables
  unsigned int argc = 3;
  char ** argv = new char*[argc];
  argv[0] = (char*)plugin.c_str();

  // if plugin is running we wait for another timeout only when in weather window
  if (g_windowManager.GetActiveWindow() == WINDOW_WEATHER)
  {
    int id = g_pythonParser.getScriptId(argv[0]);
    if (id != -1 && g_pythonParser.isRunning(id))
    {
      m_pluginTimer.StartZero();
      return;
    }
  }

  // get the current locations area code
  CStdString strSetting;
  strSetting.Format("%i", m_iCurWeather + 1);
  argv[1] = (char*)strSetting.c_str();
  argv[2] = (char*)(forceRefresh ? "1" : "0");


  // call our plugin, passing the areacode
  g_pythonParser.evalFile(argv[0], argc, (const char**)argv);

  CLog::Log(LOGDEBUG, "%s - Weather plugin called: %s (%s)", __FUNCTION__, argv[0], argv[1]);

  forceRefresh = false;
}
