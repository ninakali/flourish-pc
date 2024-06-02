#!/bin/sh
echo "< Source >"
python3 assemble.py tests/$1/src.asm tests/$1/compiled.bin tests/$1/consts.in
echo "< Consts >"
cat tests/$1/consts.in
echo "< Input tape >"
cat tests/$1/data.in
echo "< Execution >"
cat tests/$1/consts.in tests/$1/data.in > tests/$1/tape.in
python3 emu.py tests/$1/compiled.bin tests/$1/tape.in tests/$1/tape.out
echo ""
echo "< Output tape >"
cat tests/$1/tape.out
