FATE_TESTS += fate-4xm-1
fate-4xm-1: CMD = framecrc -i $(SAMPLES)/4xm/version1.4xm -pix_fmt rgb24 -an
FATE_TESTS += fate-4xm-2
fate-4xm-2: CMD = framecrc -i $(SAMPLES)/4xm/version2.4xm -pix_fmt rgb24 -an
FATE_TESTS += fate-8bps
fate-8bps: CMD = framecrc  -i $(SAMPLES)/8bps/full9iron-partial.mov -pix_fmt rgb24
FATE_TESTS += fate-aasc
fate-aasc: CMD = framecrc  -i $(SAMPLES)/aasc/AASC-1.5MB.AVI -pix_fmt rgb24
FATE_TESTS += fate-adpcm-ea-r2
fate-adpcm-ea-r2: CMD = crc  -i $(SAMPLES)/ea-mpc/THX_logo.mpc -vn
FATE_TESTS += fate-adpcm-ea-r3
fate-adpcm-ea-r3: CMD = crc  -i $(SAMPLES)/ea-vp6/THX_logo.vp6 -vn
FATE_TESTS += fate-adts-demux
fate-adts-demux: CMD = crc  -i $(SAMPLES)/aac/ct_faac-adts.aac -acodec copy
FATE_TESTS += fate-aea-demux
fate-aea-demux: CMD = crc  -i $(SAMPLES)/aea/chirp.aea -acodec copy
FATE_TESTS += fate-alg-mm
fate-alg-mm: CMD = framecrc  -i $(SAMPLES)/alg-mm/ibmlogo.mm -an -pix_fmt rgb24
FATE_TESTS += fate-amv
fate-amv: CMD = framecrc  -idct simple -i $(SAMPLES)/amv/MTV_high_res_320x240_sample_Penguin_Joke_MTV_from_WMV.amv -t 10
FATE_TESTS += fate-armovie-escape124
fate-armovie-escape124: CMD = framecrc  -i $(SAMPLES)/rpl/ESCAPE.RPL -pix_fmt rgb24
FATE_TESTS += fate-auravision
fate-auravision: CMD = framecrc  -i $(SAMPLES)/auravision/SOUVIDEO.AVI -an
FATE_TESTS += fate-auravision-v2
fate-auravision-v2: CMD = framecrc  -i $(SAMPLES)/auravision/salma-hayek-in-ugly-betty-partial-avi -an
FATE_TESTS += fate-bethsoft-vid
fate-bethsoft-vid: CMD = framecrc  -i $(SAMPLES)/bethsoft-vid/ANIM0001.VID -vsync 0 -t 5 -pix_fmt rgb24
FATE_TESTS += fate-bfi
fate-bfi: CMD = framecrc  -i $(SAMPLES)/bfi/2287.bfi -pix_fmt rgb24
FATE_TESTS += fate-bink-demux
fate-bink-demux: CMD = crc  -i $(SAMPLES)/bink/Snd0a7d9b58.dee -vn -acodec copy
FATE_TESTS += fate-bink-demux-video
fate-bink-demux-video: CMD = framecrc  -i $(SAMPLES)/bink/hol2br.bik
FATE_TESTS += fate-caf
fate-caf: CMD = crc  -i $(SAMPLES)/caf/caf-pcm16.caf
FATE_TESTS += fate-cdgraphics
fate-cdgraphics: CMD = framecrc  -i $(SAMPLES)/cdgraphics/BrotherJohn.cdg -pix_fmt rgb24 -t 1
FATE_TESTS += fate-cljr
fate-cljr: CMD = framecrc  -i $(SAMPLES)/cljr/testcljr-partial.avi
FATE_TESTS += fate-corepng
fate-corepng: CMD = framecrc  -i $(SAMPLES)/png1/corepng-partial.avi
FATE_TESTS += fate-creative-adpcm
fate-creative-adpcm: CMD = md5  -i $(SAMPLES)/creative/intro-partial.wav -f s16le
FATE_TESTS += fate-creative-adpcm-8-2.6bit
fate-creative-adpcm-8-2.6bit: CMD = md5  -i $(SAMPLES)/creative/BBC_3BIT.VOC -f s16le
FATE_TESTS += fate-creative-adpcm-8-2bit
fate-creative-adpcm-8-2bit: CMD = md5  -i $(SAMPLES)/creative/BBC_2BIT.VOC -f s16le
FATE_TESTS += fate-creative-adpcm-8-4bit
fate-creative-adpcm-8-4bit: CMD = md5  -i $(SAMPLES)/creative/BBC_4BIT.VOC -f s16le
FATE_TESTS += fate-creatureshock-avs
fate-creatureshock-avs: CMD = framecrc  -i $(SAMPLES)/creatureshock-avs/OUTATIME.AVS -pix_fmt rgb24
FATE_TESTS += fate-cryo-apc
fate-cryo-apc: CMD = md5  -i $(SAMPLES)/cryo-apc/cine007.APC -f s16le
FATE_TESTS += fate-cvid
fate-cvid: CMD = framecrc  -i $(SAMPLES)/cvid/laracroft-cinepak-partial.avi -an
FATE_TESTS += fate-cvid-palette
fate-cvid-palette: CMD = framecrc  -i $(SAMPLES)/cvid/catfight-cvid-pal8-partial.mov -pix_fmt rgb24 -an
FATE_TESTS += fate-cyberia-c93
fate-cyberia-c93: CMD = framecrc  -i $(SAMPLES)/cyberia-c93/intro1.c93 -t 3 -pix_fmt rgb24
FATE_TESTS += fate-cyuv
fate-cyuv: CMD = framecrc  -i $(SAMPLES)/cyuv/cyuv.avi
FATE_TESTS += fate-d-cinema-demux
fate-d-cinema-demux: CMD = framecrc  -i $(SAMPLES)/d-cinema/THX_Science_FLT_1920-partial.302 -acodec copy -pix_fmt rgb24
FATE_TESTS += fate-delphine-cin
fate-delphine-cin: CMD = framecrc  -i $(SAMPLES)/delphine-cin/LOGO-partial.CIN -pix_fmt rgb24 -vsync 0
FATE_TESTS += fate-deluxepaint-anm
fate-deluxepaint-anm: CMD = framecrc  -i $(SAMPLES)/deluxepaint-anm/INTRO1.ANM -pix_fmt rgb24
FATE_TESTS += fate-duck-dk3
fate-duck-dk3: CMD = md5  -i $(SAMPLES)/duck/sop-audio-only.avi -f s16le
FATE_TESTS += fate-duck-dk4
fate-duck-dk4: CMD = md5  -i $(SAMPLES)/duck/salsa-audio-only.avi -f s16le
FATE_TESTS += fate-duck-tm2
fate-duck-tm2: CMD = framecrc  -i $(SAMPLES)/duck/tm20.avi
FATE_TESTS += fate-ea-cdata
fate-ea-cdata: CMD = md5  -i $(SAMPLES)/ea-cdata/166b084d.46410f77.0009b440.24be960c.cdata -f s16le
FATE_TESTS += fate-ea-cmv
fate-ea-cmv: CMD = framecrc  -i $(SAMPLES)/ea-cmv/TITLE.CMV -vsync 0 -pix_fmt rgb24
FATE_TESTS += fate-ea-dct
fate-ea-dct: CMD = framecrc  -idct simple -i $(SAMPLES)/ea-dct/NFS2Esprit-partial.dct
FATE_TESTS += fate-ea-mad-adpcm-ea-r1
fate-ea-mad-adpcm-ea-r1: CMD = framecrc  -i $(SAMPLES)/ea-mad/NFS6LogoE.mad
FATE_TESTS += fate-ea-mad-pcm-planar
fate-ea-mad-pcm-planar: CMD = framecrc  -i $(SAMPLES)/ea-mad/xeasport.mad
FATE_TESTS += fate-ea-tgq
fate-ea-tgq: CMD = framecrc  -i $(SAMPLES)/ea-tgq/v27.tgq -an
FATE_TESTS += fate-ea-tgv-ima-ea-eacs
fate-ea-tgv-ima-ea-eacs: CMD = framecrc  -i $(SAMPLES)/ea-tgv/INTRO8K-partial.TGV -pix_fmt rgb24
FATE_TESTS += fate-ea-tgv-ima-ea-sead
fate-ea-tgv-ima-ea-sead: CMD = framecrc  -i $(SAMPLES)/ea-tgv/INTEL_S.TGV -pix_fmt rgb24
FATE_TESTS += fate-ea-tqi-adpcm
fate-ea-tqi-adpcm: CMD = framecrc  -i $(SAMPLES)/ea-wve/networkBackbone-partial.wve -frames:v 26
FATE_TESTS += fate-feeble-dxa
fate-feeble-dxa: CMD = framecrc  -i $(SAMPLES)/dxa/meetsquid.dxa -t 2 -pix_fmt rgb24
FATE_TESTS += fate-film-cvid-pcm-stereo-8bit
fate-film-cvid-pcm-stereo-8bit: CMD = framecrc  -i $(SAMPLES)/film/logo-capcom.cpk
FATE_TESTS += fate-flic-af11-palette-change
fate-flic-af11-palette-change: CMD = framecrc  -i $(SAMPLES)/fli/fli-engines.fli -t 3.3 -pix_fmt rgb24
FATE_TESTS += fate-flic-af12
fate-flic-af12: CMD = framecrc  -i $(SAMPLES)/fli/jj00c2.fli -pix_fmt rgb24
FATE_TESTS += fate-flic-magiccarpet
fate-flic-magiccarpet: CMD = framecrc  -i $(SAMPLES)/fli/intel.dat -pix_fmt rgb24
FATE_TESTS += fate-frwu
fate-frwu: CMD = framecrc  -i $(SAMPLES)/frwu/frwu.avi
FATE_TESTS += fate-funcom-iss
fate-funcom-iss: CMD = md5  -i $(SAMPLES)/funcom-iss/0004010100.iss -f s16le
FATE_TESTS += fate-g729-0
fate-g729-0: CMD = framecrc  -i $(SAMPLES)/act/REC03.act -t 10
FATE_TESTS += fate-g729-1
fate-g729-1: CMD = framecrc  -i $(SAMPLES)/act/REC05.act -t 10
FATE_TESTS += fate-id-cin-video
fate-id-cin-video: CMD = framecrc  -i $(SAMPLES)/idcin/idlog-2MB.cin -pix_fmt rgb24
FATE_TESTS += fate-idroq-video-dpcm
fate-idroq-video-dpcm: CMD = framecrc  -i $(SAMPLES)/idroq/idlogo.roq
FATE_TESTS-$(CONFIG_AVFILTER) += fate-idroq-video-encode
fate-idroq-video-encode: CMD = md5  -f image2 -vcodec pgmyuv -i $(SAMPLES)/ffmpeg-synthetic/vsynth1/%02d.pgm -sws_flags +bitexact -vf pad=512:512:80:112 -f RoQ -t 0.2
FATE_TESTS += fate-iff-byterun1
fate-iff-byterun1: CMD = framecrc  -i $(SAMPLES)/iff/ASH.LBM -pix_fmt rgb24
FATE_TESTS += fate-iff-fibonacci
fate-iff-fibonacci: CMD = md5  -i $(SAMPLES)/iff/dasboot-in-compressed -f s16le
FATE_TESTS += fate-iff-ilbm
fate-iff-ilbm: CMD = framecrc  -i $(SAMPLES)/iff/lms-matriks.ilbm -pix_fmt rgb24
FATE_TESTS += fate-iff-pcm
fate-iff-pcm: CMD = md5  -i $(SAMPLES)/iff/Bells -f s16le
FATE_TESTS += fate-interplay-mve-16bit
fate-interplay-mve-16bit: CMD = framecrc  -i $(SAMPLES)/interplay-mve/descent3-level5-16bit-partial.mve -pix_fmt rgb24
FATE_TESTS += fate-interplay-mve-8bit
fate-interplay-mve-8bit: CMD = framecrc  -i $(SAMPLES)/interplay-mve/interplay-logo-2MB.mve -pix_fmt rgb24
FATE_TESTS += fate-iv8-demux
fate-iv8-demux: CMD = framecrc  -i $(SAMPLES)/iv8/zzz-partial.mpg -vsync 0 -vcodec copy
FATE_TESTS += fate-kmvc
fate-kmvc: CMD = framecrc  -i $(SAMPLES)/KMVC/LOGO1.AVI -an -t 3 -pix_fmt rgb24
FATE_TESTS += fate-lmlm4-demux
fate-lmlm4-demux: CMD = framecrc  -i $(SAMPLES)/lmlm4/LMLM4_CIFat30fps.divx -t 3 -acodec copy -vcodec copy
FATE_TESTS += fate-maxis-xa
fate-maxis-xa: CMD = md5  -i $(SAMPLES)/maxis-xa/SC2KBUG.XA -f s16le
FATE_TESTS += fate-mimic
fate-mimic: CMD = framecrc  -idct simple -i $(SAMPLES)/mimic/mimic2-womanloveffmpeg.cam -vsync 0
FATE_TESTS += fate-motionpixels
fate-motionpixels: CMD = framecrc  -i $(SAMPLES)/motion-pixels/INTRO-partial.MVI -an -pix_fmt rgb24 -vframes 111
FATE_TESTS += fate-mtv
fate-mtv: CMD = framecrc  -i $(SAMPLES)/mtv/comedian_auto-partial.mtv -acodec copy -pix_fmt rgb24
FATE_TESTS += fate-mxf-demux
fate-mxf-demux: CMD = framecrc  -i $(SAMPLES)/mxf/C0023S01.mxf -acodec copy -vcodec copy
FATE_TESTS += fate-nc-demux
fate-nc-demux: CMD = framecrc  -i $(SAMPLES)/nc-camera/nc-sample-partial -vcodec copy
FATE_TESTS += fate-nsv-demux
fate-nsv-demux: CMD = framecrc  -i $(SAMPLES)/nsv/witchblade-51kbps.nsv -t 6 -vcodec copy -acodec copy
FATE_TESTS += fate-nuv
fate-nuv: CMD = framecrc  -idct simple -i $(SAMPLES)/nuv/Today.nuv -vsync 0
FATE_TESTS += fate-oma-demux
fate-oma-demux: CMD = crc  -i $(SAMPLES)/oma/01-Untitled-partial.oma -acodec copy
FATE_TESTS += fate-pcm_dvd
fate-pcm_dvd: CMD = framecrc  -i $(SAMPLES)/pcm-dvd/coolitnow-partial.vob -vn
FATE_TESTS += fate-psx-str
fate-psx-str: CMD = framecrc  -i $(SAMPLES)/psx-str/descent-partial.str
FATE_TESTS += fate-psx-str-v3-mdec
fate-psx-str-v3-mdec: CMD = framecrc  -i $(SAMPLES)/psx-str/abc000_cut.str -an
FATE_TESTS += fate-psx-str-v3-adpcm_xa
fate-psx-str-v3-adpcm_xa: CMD = framecrc  -i $(SAMPLES)/psx-str/abc000_cut.str -vn
FATE_TESTS += fate-pva-demux
fate-pva-demux: CMD = framecrc  -idct simple -i $(SAMPLES)/pva/PVA_test-partial.pva -t 0.6 -acodec copy
FATE_TESTS += fate-qcp-demux
fate-qcp-demux: CMD = crc  -i $(SAMPLES)/qcp/0036580847.QCP -acodec copy
FATE_TESTS += fate-qpeg
fate-qpeg: CMD = framecrc  -i $(SAMPLES)/qpeg/Clock.avi -an -pix_fmt rgb24
FATE_TESTS += fate-qt-alaw-mono
fate-qt-alaw-mono: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-1-16-B-alaw.mov -f s16le
FATE_TESTS += fate-qt-alaw-stereo
fate-qt-alaw-stereo: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-16-B-alaw.mov -f s16le
FATE_TESTS += fate-qt-ima4-mono
fate-qt-ima4-mono: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-1-16-B-ima4.mov -f s16le
FATE_TESTS += fate-qt-ima4-stereo
fate-qt-ima4-stereo: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-16-B-ima4.mov -f s16le
FATE_TESTS += fate-qt-mac3-mono
fate-qt-mac3-mono: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-1-8-MAC3.mov -f s16le
FATE_TESTS += fate-qt-mac3-stereo
fate-qt-mac3-stereo: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-8-MAC3.mov -f s16le
FATE_TESTS += fate-qt-mac6-mono
fate-qt-mac6-mono: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-1-8-MAC6.mov -f s16le
FATE_TESTS += fate-qt-mac6-stereo
fate-qt-mac6-stereo: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-8-MAC6.mov -f s16le
FATE_TESTS += fate-qt-msadpcm-stereo
fate-qt-msadpcm-stereo: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-16-L-ms02.mov -f s16le
FATE_TESTS += fate-qt-msimaadpcm-stereo
fate-qt-msimaadpcm-stereo: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-16-L-ms11.mov -f s16le
FATE_TESTS += fate-qt-rawpcm-16bit-stereo-signed-be
fate-qt-rawpcm-16bit-stereo-signed-be: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-16-B-twos.mov -f s16le
FATE_TESTS += fate-qt-rawpcm-16bit-stereo-signed-le
fate-qt-rawpcm-16bit-stereo-signed-le: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-16-L-sowt.mov -f s16le
FATE_TESTS += fate-qt-rawpcm-8bit-mono-unsigned
fate-qt-rawpcm-8bit-mono-unsigned: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-1-8-raw.mov -f s16le
FATE_TESTS += fate-qt-rawpcm-8bit-stereo-unsigned
fate-qt-rawpcm-8bit-stereo-unsigned: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-8-raw.mov -f s16le
FATE_TESTS += fate-qt-ulaw-mono
fate-qt-ulaw-mono: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-1-16-B-ulaw.mov -f s16le
FATE_TESTS += fate-qt-ulaw-stereo
fate-qt-ulaw-stereo: CMD = md5  -i $(SAMPLES)/qt-surge-suite/surge-2-16-B-ulaw.mov -f s16le
FATE_TESTS += fate-quickdraw
fate-quickdraw: CMD = framecrc  -i $(SAMPLES)/quickdraw/Airplane.mov -pix_fmt rgb24
FATE_TESTS += fate-redcode-demux
fate-redcode-demux: CMD = framecrc  -i $(SAMPLES)/r3d/4MB-sample.r3d -vcodec copy -acodec copy
FATE_TESTS += fate-rl2
fate-rl2: CMD = framecrc  -i $(SAMPLES)/rl2/Z4915300.RL2 -pix_fmt rgb24 -an -vsync 0
FATE_TESTS += fate-rpza
fate-rpza: CMD = framecrc  -i $(SAMPLES)/rpza/rpza2.mov -t 2 -pix_fmt rgb24
FATE_TESTS += fate-sierra-audio
fate-sierra-audio: CMD = md5  -i $(SAMPLES)/sol/lsl7sample.sol -f s16le
FATE_TESTS += fate-sierra-vmd
fate-sierra-vmd: CMD = framecrc  -i $(SAMPLES)/vmd/12.vmd -vsync 0 -pix_fmt rgb24
FATE_TESTS += fate-siff
fate-siff: CMD = framecrc  -i $(SAMPLES)/SIFF/INTRO_B.VB -t 3 -pix_fmt rgb24
FATE_TESTS += fate-smacker
fate-smacker: CMD = framecrc  -i $(SAMPLES)/smacker/wetlogo.smk -pix_fmt rgb24
FATE_TESTS += fate-smc
fate-smc: CMD = framecrc  -i $(SAMPLES)/smc/cass_schi.qt -vsync 0 -pix_fmt rgb24
FATE_TESTS += fate-sp5x
fate-sp5x: CMD = framecrc  -idct simple -i $(SAMPLES)/sp5x/sp5x_problem.avi
FATE_TESTS += fate-sub-srt
fate-sub-srt: CMD = md5  -i $(SAMPLES)/sub/SubRip_capability_tester.srt -f ass
FATE_TESTS += fate-svq1
fate-svq1: CMD = framecrc  -i $(SAMPLES)/svq1/marymary-shackles.mov -an -t 10
FATE_TESTS += fate-svq3
fate-svq3: CMD = framecrc  -i $(SAMPLES)/svq3/Vertical400kbit.sorenson3.mov -t 6 -an
FATE_TESTS += fate-thp-mjpeg-adpcm
fate-thp-mjpeg-adpcm: CMD = framecrc  -idct simple -i $(SAMPLES)/thp/pikmin2-opening1-partial.thp
FATE_TESTS += fate-tiertex-seq
fate-tiertex-seq: CMD = framecrc  -i $(SAMPLES)/tiertex-seq/Gameover.seq -pix_fmt rgb24
FATE_TESTS += fate-tmv
fate-tmv: CMD = framecrc  -i $(SAMPLES)/tmv/pop-partial.tmv -pix_fmt rgb24
FATE_TESTS += fate-truemotion1-15
fate-truemotion1-15: CMD = framecrc -i $(SAMPLES)/duck/phant2-940.duk -pix_fmt rgb24
FATE_TESTS += fate-truemotion1-24
fate-truemotion1-24: CMD = framecrc -i $(SAMPLES)/duck/sonic3dblast_intro-partial.avi -pix_fmt rgb24
FATE_TESTS += fate-ulti
fate-ulti: CMD = framecrc  -i $(SAMPLES)/ulti/hit12w.avi -an
FATE_TESTS += fate-v210
fate-v210: CMD = framecrc  -i $(SAMPLES)/v210/v210_720p-partial.avi -pix_fmt yuv422p16be -an
FATE_TESTS += fate-vcr1
fate-vcr1: CMD = framecrc  -i $(SAMPLES)/vcr1/VCR1test.avi -an
FATE_TESTS += fate-video-xl
fate-video-xl: CMD = framecrc  -i $(SAMPLES)/vixl/pig-vixl.avi
FATE_TESTS += fate-vqa-cc
fate-vqa-cc: CMD = framecrc  -i $(SAMPLES)/vqa/cc-demo1-partial.vqa -pix_fmt rgb24
FATE_TESTS += fate-w64
fate-w64: CMD = crc  -i $(SAMPLES)/w64/w64-pcm16.w64
FATE_TESTS += fate-wc3movie-xan
fate-wc3movie-xan: CMD = framecrc  -i $(SAMPLES)/wc3movie/SC_32-part.MVE -pix_fmt rgb24
FATE_TESTS += fate-westwood-aud
fate-westwood-aud: CMD = md5  -i $(SAMPLES)/westwood-aud/excellent.aud -f s16le
FATE_TESTS += fate-wnv1
fate-wnv1: CMD = framecrc  -i $(SAMPLES)/wnv1/wnv1-codec.avi -an
FATE_TESTS += fate-xan-dpcm
fate-xan-dpcm: CMD = md5  -i $(SAMPLES)/wc4-xan/wc4_2.avi -vn -f s16le
