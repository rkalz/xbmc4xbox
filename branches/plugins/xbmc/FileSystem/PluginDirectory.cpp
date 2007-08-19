/*
 *      Copyright (C) 2005-2007 Team XboxMediaCenter
 *      http://www.xboxmediacenter.com
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
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */
#include "stdafx.h"
#include "PluginDirectory.h"
#include "util.h"
#include "lib/libPython/XBPython.h"
 
using namespace DIRECTORY;

vector<CPluginDirectory *> CPluginDirectory::globalHandles;

CPluginDirectory::CPluginDirectory(void)
{
  m_directoryFetched = CreateEvent(NULL, false, false, NULL);
}

CPluginDirectory::~CPluginDirectory(void)
{
  CloseHandle(m_directoryFetched);
}

int CPluginDirectory::getNewHandle(CPluginDirectory *cp)
{
  int handle = (int)globalHandles.size();
  globalHandles.push_back(cp);
  return handle;
}

void CPluginDirectory::removeHandle(int handle)
{
  if (handle > 0 && handle < (int)globalHandles.size())
    globalHandles.erase(globalHandles.begin() + handle);
}

bool CPluginDirectory::AddItem(int handle, const CFileItem *item)
{
  if (handle < 0 || handle >= (int)globalHandles.size())
  {
    CLog::Log(LOGERROR, __FUNCTION__" called with an invalid handle.");
    return false;
  }
  CPluginDirectory *dir = globalHandles[handle];
  CFileItem *pItem = new CFileItem(*item);
  dir->m_listItems.Add(pItem);

  return !dir->m_cancelled;
}

void CPluginDirectory::EndOfDirectory(int handle, bool success)
{
  if (handle < 0 || handle >= (int)globalHandles.size())
  {
    CLog::Log(LOGERROR, __FUNCTION__" called with an invalid handle.");
    return;
  }
  CPluginDirectory *dir = globalHandles[handle];
  dir->m_success = success;

  // set the event to mark that we're done
  SetEvent(dir->m_directoryFetched);
}

void CPluginDirectory::AddSortMethod(int handle, SORT_METHOD sortMethod)
{
  if (handle < 0 || handle >= (int)globalHandles.size())
  {
    CLog::Log(LOGERROR, __FUNCTION__" called with an invalid handle.");
    return;
  }

  CPluginDirectory *dir = globalHandles[handle];

  // TODO: Add all sort methods
  if (sortMethod == SORT_METHOD_LABEL_IGNORE_THE || sortMethod == SORT_METHOD_LABEL)
  {
    if (g_guiSettings.GetBool("filelists.ignorethewhensorting"))
      dir->m_listItems.AddSortMethod(SORT_METHOD_LABEL_IGNORE_THE, 551, LABEL_MASKS("%T", "%D"));  // Filename, Duration | Foldername, empty
    else
      dir->m_listItems.AddSortMethod(SORT_METHOD_LABEL, 551, LABEL_MASKS("%T", "%D"));  // Filename, Duration | Foldername, empty
  }
  else if (sortMethod == SORT_METHOD_TITLE_IGNORE_THE || sortMethod == SORT_METHOD_TITLE)
  {
    if (g_guiSettings.GetBool("filelists.ignorethewhensorting"))
      dir->m_listItems.AddSortMethod(SORT_METHOD_TITLE_IGNORE_THE, 556, LABEL_MASKS("%T", "%D"));  // Filename, Duration | Foldername, empty
    else
      dir->m_listItems.AddSortMethod(SORT_METHOD_TITLE, 556, LABEL_MASKS("%T", "%D"));  // Filename, Duration | Foldername, empty
  }
  else if (sortMethod == SORT_METHOD_ARTIST_IGNORE_THE || sortMethod == SORT_METHOD_ARTIST)
  {
    if (g_guiSettings.GetBool("filelists.ignorethewhensorting"))
      dir->m_listItems.AddSortMethod(SORT_METHOD_ARTIST_IGNORE_THE, 557, LABEL_MASKS("%A", "%D"));  // Filename, Duration | Foldername, empty
    else
      dir->m_listItems.AddSortMethod(SORT_METHOD_ARTIST, 557, LABEL_MASKS("%A", "%D"));  // Filename, Duration | Foldername, empty
  }
  else if (sortMethod == SORT_METHOD_ALBUM_IGNORE_THE || sortMethod == SORT_METHOD_ALBUM)
  {
    if (g_guiSettings.GetBool("filelists.ignorethewhensorting"))
      dir->m_listItems.AddSortMethod(SORT_METHOD_ALBUM_IGNORE_THE, 558, LABEL_MASKS("%B", "%A"));  // Filename, Duration | Foldername, empty
    else
      dir->m_listItems.AddSortMethod(SORT_METHOD_ALBUM, 558, LABEL_MASKS("%B", "%A"));  // Filename, Duration | Foldername, empty
  }
  else if (sortMethod == SORT_METHOD_DATE)
    dir->m_listItems.AddSortMethod(SORT_METHOD_DATE, 552, LABEL_MASKS("%T", "%J"));  // Filename, Duration | Foldername, empty
  else if (sortMethod == SORT_METHOD_SIZE)
    dir->m_listItems.AddSortMethod(SORT_METHOD_DATE, 553, LABEL_MASKS("%T", "%I"));  // Filename, Duration | Foldername, empty
  else if (sortMethod == SORT_METHOD_FILE)
    dir->m_listItems.AddSortMethod(SORT_METHOD_FILE, 561, LABEL_MASKS("%T", "%F"));  // Filename, Duration | Foldername, empty
  else if (sortMethod == SORT_METHOD_TRACKNUM)
    dir->m_listItems.AddSortMethod(SORT_METHOD_TRACKNUM, 554, LABEL_MASKS("%T", "%N"));  // Filename, Duration | Foldername, empty
  else if (sortMethod == SORT_METHOD_DURATION)
    dir->m_listItems.AddSortMethod(SORT_METHOD_DURATION, 555, LABEL_MASKS("%T", "%D"));  // Filename, Duration | Foldername, empty
  else if (sortMethod == SORT_METHOD_VIDEO_RATING)
    dir->m_listItems.AddSortMethod(SORT_METHOD_VIDEO_RATING, 563, LABEL_MASKS("%T", "%R"));  // Filename, Duration | Foldername, empty
  else if (sortMethod == SORT_METHOD_VIDEO_YEAR)
    dir->m_listItems.AddSortMethod(SORT_METHOD_VIDEO_YEAR, 345, LABEL_MASKS("%T", "%Y"));
  else if (sortMethod == SORT_METHOD_SONG_RATING)
    dir->m_listItems.AddSortMethod(SORT_METHOD_SONG_RATING, 563, LABEL_MASKS("%T", "%R"));
  else if (sortMethod == SORT_METHOD_GENRE)
    dir->m_listItems.AddSortMethod(SORT_METHOD_GENRE, 515, LABEL_MASKS("%T", "%G"));
  else if (sortMethod == SORT_METHOD_VIDEO_TITLE)
    dir->m_listItems.AddSortMethod(SORT_METHOD_VIDEO_TITLE, 515, LABEL_MASKS("%T", "%D"));
}

bool CPluginDirectory::GetDirectory(const CStdString& strPath, CFileItemList& items)
{
  CURL url(strPath);
  if (url.GetFileName().IsEmpty())
  { // called with no script - should never happen
    return GetPluginsDirectory(url.GetHostName(), items);
  }

  CStdString fileName;
  CUtil::AddFileToFolder(url.GetFileName(), "default.py", fileName);

  // path is Q:\plugins\<path from here>
  CStdString pathToScript = "Q:\\plugins\\";
  CUtil::AddFileToFolder(pathToScript, url.GetHostName(), pathToScript);
  CUtil::AddFileToFolder(pathToScript, fileName, pathToScript);
  pathToScript.Replace("/", "\\");

  // base path
  CStdString basePath = "plugin://";
  CUtil::AddFileToFolder(basePath, url.GetHostName(), basePath);
  CUtil::AddFileToFolder(basePath, url.GetFileName(), basePath);

  // options
  CStdString options = url.GetOptions();
  CUtil::RemoveSlashAtEnd(options); // This MAY kill some scripts (eg though with a URL ending with a slash), but
                                    // is needed for all others, as XBMC adds slashes to "folders"

  // reset our wait event, and grab a new handle
  ResetEvent(m_directoryFetched);
  int handle = getNewHandle(this);

  // clear out our status variables
  m_listItems.Clear();
  m_listItems.m_strPath = strPath;
  m_cancelled = false;
  m_success = false;

  // setup our parameters to send the script
  CStdString strHandle;
  strHandle.Format("%i", handle);
  const char *argv[3];
  argv[0] = basePath.c_str();
  argv[1] = strHandle.c_str();
  argv[2] = options.c_str();

  // run the script
  CLog::Log(LOGDEBUG, __FUNCTION__" - calling plugin %s('%s','%s','%s')", pathToScript.c_str(), argv[0], argv[1], argv[2]);
  bool success = false;
  if (g_pythonParser.evalFile(pathToScript.c_str(), 3, (const char**)argv) >= 0)
  { // wait for our script to finish
    CStdString scriptName = url.GetFileName();
    CUtil::RemoveSlashAtEnd(scriptName);
    success = WaitOnScriptResult(pathToScript, scriptName);
  }
  else
    CLog::Log(LOGERROR, "Unable to run plugin %s", pathToScript.c_str());

  // free our handle
  removeHandle(handle);

  // append the items to the list, and return true
  items.AssignPointer(m_listItems);
  m_listItems.ClearKeepPointer();
  return success;
}

bool CPluginDirectory::HasPlugins(const CStdString &type)
{
  CStdString path = "Q:\\plugins\\";
  CUtil::AddFileToFolder(path, type, path);
  CFileItemList items;
  if (CDirectory::GetDirectory(path, items, "/", false))
  {
    for (int i = 0; i < items.Size(); i++)
    {
      CFileItem *item = items[i];
      if (item->m_bIsFolder && !item->IsParentFolder() && !item->m_bIsShareOrDrive)
      {
        CStdString defaultPY;
        CUtil::AddFileToFolder(item->m_strPath, "default.py", defaultPY);
        if (XFILE::CFile::Exists(defaultPY))
          return true;
      }
    }
  }
  return false;
}

bool CPluginDirectory::GetPluginsDirectory(const CStdString &type, CFileItemList &items)
{
  // retrieve our folder
  CStdString pluginsFolder = "Q:\\plugins";
  CUtil::AddFileToFolder(pluginsFolder, type, pluginsFolder);

  if (!CDirectory::GetDirectory(pluginsFolder, items, "*.py", false))
    return false;

  // flatten any folders - TODO: Assigning of thumbs
  for (int i = 0; i < items.Size(); i++)
  {
    CFileItem *item = items[i];
    item->m_strPath.Replace("Q:\\plugins\\", "plugin://");
    item->m_strPath.Replace("\\", "/");
  }
  return true;
}

bool CPluginDirectory::WaitOnScriptResult(const CStdString &scriptPath, const CStdString &scriptName)
{
  const unsigned int timeBeforeProgressBar = 1500;
  const unsigned int timeToKillScript = 1000;

  DWORD startTime = timeGetTime();
  CGUIDialogProgress *progressBar = NULL;

  CLog::Log(LOGDEBUG, __FUNCTION__" - waiting on the %s plugin...", scriptName.c_str());
  while (true)
  {
    // check if the python script is finished
    if (WaitForSingleObject(m_directoryFetched, 20) == WAIT_OBJECT_0)
    { // python has returned
      CLog::Log(LOGDEBUG, __FUNCTION__" plugin returned %s", m_success ? "successfully" : "failure");
      break;
    }

    // check whether we should pop up the progress dialog
    if (!progressBar && timeGetTime() - startTime > timeBeforeProgressBar)
    { // loading takes more then 1.5 secs, show a progress dialog
      progressBar = (CGUIDialogProgress *)m_gWindowManager.GetWindow(WINDOW_DIALOG_PROGRESS);
      if (progressBar)
      {
        progressBar->SetHeading(scriptName);
        progressBar->SetLine(0, 1040);
        progressBar->SetLine(1, "");
        progressBar->SetLine(2, "");
        progressBar->StartModal();
      }
    }

    if (progressBar)
    { // update the progress bar and check for user cancel
      CStdString label;
      label.Format(g_localizeStrings.Get(1041).c_str(), m_listItems.Size());
      progressBar->SetLine(2, label);
      progressBar->Progress();
      if (progressBar->IsCanceled())
      { // user has cancelled our process - cancel our process
        if (!m_cancelled)
        {
          m_cancelled = true;
          startTime = timeGetTime();
        }
        if (m_cancelled && timeGetTime() - startTime > timeToKillScript)
        { // cancel our script
          int id = g_pythonParser.getScriptId(scriptPath.c_str());
          if (id != -1 && g_pythonParser.isRunning(id))
          {
            CLog::Log(LOGDEBUG, __FUNCTION__" cancelling plugin %s", scriptName.c_str());
            g_pythonParser.stopScript(id);
            break;
          }
        }
      }
    }
  }
  if (progressBar)
    progressBar->Close();

  return !m_cancelled && m_success;
}
