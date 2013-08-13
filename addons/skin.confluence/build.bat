@echo off
ECHO ----------------------------------------
echo Creating Confluence Build Folder
rmdir ..\..\BUILDTMP /S /Q
md ..\..\BUILDTMP\skin.confluence\media\

Echo .svn>exclude.txt
Echo Thumbs.db>>exclude.txt
Echo Desktop.ini>>exclude.txt
Echo dsstdfx.bin>>exclude.txt
Echo BUILD>>exclude.txt
Echo \skin.confluence\media\>>exclude.txt
Echo exclude.txt>>exclude.txt

ECHO ----------------------------------------
ECHO Creating XPR File...
START /B /WAIT ..\..\Tools\XBMCTex\XBMCTex -input media -output ..\..\BUILDTMP\skin.confluence\media -noprotect

ECHO ----------------------------------------
ECHO XBT Texture Files Created...
ECHO Building Skin Directory...
xcopy "..\skin.confluence" "..\..\BUILDTMP\skin.confluence" /E /Q /I /Y /EXCLUDE:exclude.txt

del exclude.txt