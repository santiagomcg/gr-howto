#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/santiago/gr-howto/python
export PATH=/home/santiago/gr-howto/build/python:$PATH
export LD_LIBRARY_PATH=/home/santiago/gr-howto/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/santiago/gr-howto/build/swig:$PYTHONPATH
/usr/bin/python2 /home/santiago/gr-howto/python/qa_suma_ff.py 
