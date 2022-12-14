#!/bin/bash

if [ `uname` = "Darwin" ]; then
    LDPATHPREFIX="DYLD_LIBRARY_PATH=/home/docker/MPLAPACK/lib"
else
    LDPATHPREFIX="LD_LIBRARY_PATH=/home/docker/MPLAPACK/lib:$LD_LIBRARY_PATH"
fi

####
MPLIBS="_Float64x dd double _Float128"

for _mplib in $MPLIBS; do
env $LDPATHPREFIX ./Rsyrk.${_mplib}_opt -NOCHECK    >& log.Rsyrk.${_mplib}_opt
env $LDPATHPREFIX ./Rsyrk.${_mplib}     -NOCHECK    >& log.Rsyrk.${_mplib}
done
####

####
MPLIBS="mpfr gmp qd"

for _mplib in $MPLIBS; do
env $LDPATHPREFIX ./Rsyrk.${_mplib}_opt -NOCHECK    >& log.Rsyrk.${_mplib}_opt
env $LDPATHPREFIX ./Rsyrk.${_mplib}     -NOCHECK    >& log.Rsyrk.${_mplib}
done
####

####
if [ `uname` = "Linux" ]; then
    MODELNAME=`lscpu | grep 'Model name' | uniq | awk '{for(i=3;i<=NF;i++) printf $i FS }'`
    SED=sed
elif [ `uname` = "Darwin" ]; then
    MODELNAME=`sysctl machdep.cpu.brand_string | awk '{for(i=2;i<=NF;i++) printf $i FS }'`
    SED=gsed
else
    MODELNAME="unknown"
fi

$SED -i -e "s/%%MODELNAME%%/$MODELNAME/g" Rsyrk1.plt
$SED -i -e "s/%%MODELNAME%%/$MODELNAME/g" Rsyrk2.plt
$SED -i -e "s/%%MODELNAME%%/$MODELNAME/g" Rsyrk3.plt
####

gnuplot Rsyrk1.plt > Rsyrk1.pdf
gnuplot Rsyrk2.plt > Rsyrk2.pdf
gnuplot Rsyrk3.plt > Rsyrk3.pdf
