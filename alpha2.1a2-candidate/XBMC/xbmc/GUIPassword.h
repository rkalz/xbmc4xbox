#pragma once

class CFileItem;
class CMediaSource;

#include <vector>
#include <map>

typedef std::vector<CMediaSource> VECSOURCES;

typedef std::map<CStdString, CStdString> MAPPASSWORDS;
typedef std::map<CStdString, CStdString>::iterator IMAPPASSWORDS;

typedef enum
{
  LOCK_MODE_UNKNOWN            = -1,
  LOCK_MODE_EVERYONE           =  0,
  LOCK_MODE_NUMERIC            =  1,
  LOCK_MODE_GAMEPAD            =  2,
  LOCK_MODE_QWERTY             =  3,
  LOCK_MODE_SAMBA              =  4,
  LOCK_MODE_EEPROM_PARENTAL    =  5
} LockType;

class CGUIPassword
{
public:
  CGUIPassword(void);
  virtual ~CGUIPassword(void);
  bool IsItemUnlocked(CFileItem* pItem, const CStdString &strType);
  bool IsItemUnlocked(CMediaSource* pItem, const CStdString &strType);
  bool CheckLock(LockType btnType, const CStdString& strPassword, int iHeading);
  bool CheckLock(LockType btnType, const CStdString& strPassword, int iHeading, bool& bCanceled);
  bool IsProfileLockUnlocked(int iProfile=-1);
  bool IsProfileLockUnlocked(int iProfile, bool& bCanceled);
  bool IsMasterLockUnlocked(bool bPromptUser);
  bool IsMasterLockUnlocked(bool bPromptUser, bool& bCanceled);
  
  void UpdateMasterLockRetryCount(bool bResetCount);
  bool GetSMBShareUserPassword();
  void SetSMBShare(const CStdString &strShare);
  CStdString GetSMBShare();
  bool CheckStartUpLock();
  bool CheckMenuLock(int iWindowID);
  bool SetMasterLockMode(bool bDetails=true);
  CStdString GetSMBAuthFilename(const CStdString& strAuth);
  bool LockSource(const CStdString& strType, const CStdString& strName, bool bState);
  void LockSources(bool lock);
  void RemoveSourceLocks();
  bool IsDatabasePathUnlocked(const CStdString& strPath, VECSOURCES& vecSources);

  MAPPASSWORDS  m_mapSMBPasswordCache; // SMB share password cache

  bool bMasterUser;
  int iMasterLockRetriesLeft;
protected:
  CStdString m_SMBShare;
private:
  int VerifyPassword(LockType btnType, const CStdString& strPassword, const CStdString& strHeading);
};

extern CGUIPassword g_passwordManager;

