#!/bin/sh
echo "< Source >"
python3 ../assemble.py $1/src.asm $1/compiled.bin $1/consts.in
echo "< Consts >"
cat $1/consts.in
echo "< Input tape >"
cat $1/data.in
echo "< Execution >"
cat $1/consts.in $1/data.in > $1/tape.in
python3 ../emu.py $1/compiled.bin $1/tape.in $1/tape.out
echo ""
echo "< Output tape >"
cat $1/tape.out
echo "< Check if all good... >"
diff $1/tape.out $1/expect.out
if [ $? -eq 0 ] ; then echo "Got expected output" ; else echo "Bad output" ; fi