#!/bin/bash

svn export https://projectm.svn.sourceforge.net/svnroot/projectm/trunk/src/projectM-engine libprojectM
cd libprojectM/
rm fonts 
rm presets 
svn export https://projectm.svn.sourceforge.net/svnroot/projectm/trunk/fonts fonts
svn export https://projectm.svn.sourceforge.net/svnroot/projectm/trunk/presets presets
