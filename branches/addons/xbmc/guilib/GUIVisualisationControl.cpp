#include "include.h"
#include "GUIVisualisationControl.h"
#include "GUIWindowManager.h"
#include "GUIUserMessages.h"
#include "Application.h"
#include "addons/AddonManager.h"

using namespace std;
using namespace ADDON;

#define LABEL_ROW1 10
#define LABEL_ROW2 11
#define LABEL_ROW3 12

CGUIVisualisationControl::CGUIVisualisationControl(int parentID, int controlID, float posX, float posY, float width, float height)
    : CGUIRenderingControl(parentID, controlID, posX, posY, width, height), m_bAttemptedLoad(false)
{
  ControlType = GUICONTROL_VISUALISATION;
}

CGUIVisualisationControl::CGUIVisualisationControl(const CGUIVisualisationControl &from)
: CGUIRenderingControl(from)
{
  ControlType = GUICONTROL_VISUALISATION;
}

void CGUIVisualisationControl::Render()
{
  if (!m_addon && g_application.IsPlayingAudio() && !m_bAttemptedLoad)
  {
    AddonPtr viz;
    if (ADDON::CAddonMgr::Get().GetDefault(ADDON_VIZ, viz))
      LoadAddon(viz);

    m_bAttemptedLoad = true;
  }
  else
    CGUIRenderingControl::Render();
}

void CGUIVisualisationControl::FreeResources(bool immediately)
{
  m_bAttemptedLoad = false;
  // tell our app that we're going
  if (!m_addon)
    return;

  CGUIMessage msg(GUI_MSG_VISUALISATION_UNLOADING, m_controlID, 0);
  g_windowManager.SendMessage(msg);
  CLog::Log(LOGDEBUG, "FreeVisualisation() started");
  CGUIRenderingControl::FreeResources();
  CLog::Log(LOGDEBUG, "FreeVisualisation() done");
}