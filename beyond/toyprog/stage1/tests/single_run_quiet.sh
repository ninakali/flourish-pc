#!/bin/sh
python3 ../assemble.py $1/src.asm $1/compiled.bin $1/consts.in > /dev/null
cat $1/consts.in $1/data.in > $1/tape.in
python3 ../emu.py $1/compiled.bin $1/tape.in $1/tape.out > /dev/null
diff $1/tape.out $1/expect.out
if [ $? -eq 0 ] ; then echo "Got expected output" ; else echo "Bad output" ; fi