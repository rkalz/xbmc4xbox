// XboxMediaCenter
//
// todo for demo 8:
//   test:
//		- fopen... in dllloader for subtitles
//		- iso9660 doesnt work?
//		- memory leak?
//   fix:
//		- .fli , the animatrix & sweet home alabama files dont work
//
//   check:
//		- startup of video takes couple of seconds, why?
//		- check bobbin007 autodetect on .it
//
//   todo:
//		- version info on mplayer.dll?
//		- movie/stretch : change for subtitles
//		- flickering screen settings?
//
// libraries: 
//			- CDRipX			: doesnt support section loading yet			
//			- xbfilezilla : doesnt support section loading yet
//			
// bugs: 
//			- reboot button blinks 1/2 speed???
//		  - reboot doesnt work on some biosses
//			- in debug mode CSMBDirectory gives a stack corruption
//
// general:
//			- different skins for 4:3 / 16:9
//			- python scripts GUI (darki)
//			- CDDB query : show progress dialogs
//			- keep groups together when sorting (hd, shares, dirs, files, ...)
//			-	add an ftp server
//		  - thumbnail: render text with disolving alpha
//			- skinnable key mapping for controls
//			- center text in dialog boxes
//			- autodetect dvd/iso/cdda
//		  - goom
//			- tvguide
//			- screensaver
//			- webserver
//
// My Programs:
//
// My Files:
//
// My Pictures:
//      - use analog thumbsticks voor zoom en move
//      - FF/RW l/r trigger   : speed/slow down slideshow time
//      - show selected image in file browser
//			- cancel for create thumbs
//
// my music:
//			- shoutcast
//			- overlay 
//					-show playtime using large font
//					-FFT
//			    - status of FF/RWND
//			- ff/rwnd
//			- cancel search 
//			- cancel scan.
//
// my videos:
//		  - control panel like in xbmp
//		  - back 7 sec, forward 30 sec buttons
//			- when playing : show video info in leftbottom corner 
//			- bookmarks
//			- OSD
//			- subtitles (positioning also)
//			- file stacking
//
// Settings:
//			- general:
//					- CDDB on/off?
//          - restore to default settings
//			- audio:
//          - output 2 all speakers
//			- Slideshow
//					- specify mypics transition time/slideshow time
//		  - screen:
//

#include "stdafx.h"
#include "application.h"


CApplication g_application;
void main()
{
	g_application.Create();
  while (1)
  {
    g_application.Run();
  }
}

extern "C" 
{

	void mp_msg( int x, int lev,const char *format, ... )
	{
		va_list va;
		static char tmp[2048];
		va_start(va, format);
		_vsnprintf(tmp, 2048, format, va);
		va_end(va);
		tmp[2048-1] = 0;

		OutputDebugString(tmp);
	}
}
