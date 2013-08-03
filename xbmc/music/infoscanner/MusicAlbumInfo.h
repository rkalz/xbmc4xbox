#pragma once

/*
 *      Copyright (C) 2005-2013 Team XBMC
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

#include "music/Song.h"
#include "music/Album.h"
#include "Scraper.h"
#include "ScraperParser.h"

class TiXmlDocument;
class CScraperUrl;

namespace XFILE { class CCurlFile; }

namespace MUSIC_GRABBER
{
class CMusicAlbumInfo
{
public:
  CMusicAlbumInfo(void);
  CMusicAlbumInfo(const CStdString& strAlbumInfo, const CScraperUrl& strAlbumURL);
  CMusicAlbumInfo(const CStdString& strAlbum, const CStdString& strArtist, const CStdString& strAlbumInfo, const CScraperUrl& strAlbumURL);
  virtual ~CMusicAlbumInfo(void);
  bool Loaded() const;
  void SetLoaded(bool bOnOff);
  void SetAlbum(CAlbum& album);
  const CAlbum &GetAlbum() const;
  CAlbum& GetAlbum();
  void SetSongs(VECSONGS &songs);
  const VECSONGS &GetSongs() const;
  const CStdString& GetTitle2() const;
  const CStdString& GetDateOfRelease() const;
  const CScraperUrl& GetAlbumURL() const;
  float GetRelevance() const { return m_relevance; }
  void SetTitle(const CStdString& strTitle);
  void SetRelevance(float relevance) { m_relevance = relevance; }
  bool Load(XFILE::CCurlFile& http, const ADDON::ScraperPtr& scraper, const CStdString& strFunction="GetAlbumDetails", const CScraperUrl* url=NULL);
  bool Parse(const TiXmlElement* album, bool bChained=false);
protected:
  CAlbum m_album;
  float m_relevance;
  CStdString m_strTitle2;
  CScraperUrl m_albumURL;
  CScraperParser m_parser;
  bool m_bLoaded;
};
}
