#!/bin/bash 
rm -r .libs
make distclean

./configure \
--extra-cflags="-D_XBOX -fno-common -mtune=pentium3 -msse -mfpmath=sse -pipe -Wno-unused-function" \
--cpu=pentium3 \
--enable-gpl \
--enable-shared \
--disable-static \
--enable-w32threads \
--enable-memalign-hack \
--enable-small \
--enable-zlib \
--disable-debug \
\
--disable-doc \
--disable-ffmpeg \
--disable-ffplay \
--disable-ffprobe \
--disable-ffserver \
\
--disable-muxers \
--disable-encoders \
\
--enable-postproc \
\
--disable-filters \
--enable-filter=buffer \
\
--disable-decoders \
--enable-decoder=mpeg4,msmpeg4v1,msmpeg4v2,msmpeg4v3 \
--enable-decoder=vp5,vp6,vp6a,vp6f \
--enable-decoder=mp1,mp2,mp3,mpegvideo,mpeg1video,mpeg2video \
--enable-decoder=aac,ac3,dca,dvbsub,dvdsub,flv,h263,h264,rtp,svq1,svq3,vorbis,wmv1,wmv2,wmv3 \
\
--disable-demuxers \
--enable-demuxer=aac,ac3,dts,asf,avi,flv,h263,h264,ogg,matroska,mp1,mp2,mp3,mpegps,mpegts,mpegtsraw,mpegvideo,mov \
--enable-demuxer=sdp,rtsp \
\
--disable-protocols \
--enable-protocol=file,pipe,gopher,mmst,rtp,tcp,udp,http \
\
--disable-bsfs \
--disable-indevs \
--disable-vdpau \
--disable-vaapi \
--disable-dxva2 \
\
--disable-altivec \
--disable-amd3dnow \
--disable-amd3dnowext \
--disable-ssse3 \
--disable-armv5te \
--disable-armv6 \
--disable-armv6t2 \
--disable-armvfp \
--disable-iwmmxt \
--disable-neon \
--disable-vis \

make -j3
mkdir .libs
cp lib*/*.dll .libs/
mv .libs/swscale-0.dll .libs/swscale-0.6.1.dll
cp .libs/avcodec-52.dll ../../../../../system/players/dvdplayer/
cp .libs/avformat-52.dll ../../../../../system/players/dvdplayer/
cp .libs/avutil-50.dll ../../../../../system/players/dvdplayer/
cp .libs/postproc-51.dll ../../../../../system/players/dvdplayer/
cp .libs/swscale-0.6.1.dll ../../../../../system/players/dvdplayer/
