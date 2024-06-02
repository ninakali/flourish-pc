#!/bin/sh
echo "< Source >"
python3 assemble.py tests/$1/src.asm tests/$1/compiled.bin
echo "< Input tape >"
cat tests/$1/tape.in
echo "< Execution >"
python3 emu.py tests/$1/compiled.bin tests/$1/tape.in tests/$1/tape.out
echo ""
echo "< Output tape >"
cat tests/$1/tape.out
