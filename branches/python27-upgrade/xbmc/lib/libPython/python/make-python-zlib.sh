#!/bin/sh
cd Lib/
rm ../python27.zlib
zip ../python27.zlib \
  -r . \
  -i \*.py \
  -x \
    plat-\* \
    distutils/\* \
    curses/\* \
    lib-tk/\* \
    idlelib/\* \
    test/\* \
    unittest/\* \
    multiprocessing/\* \
    \*/tests/\* \
    \*/test/\*