#!/bin/sh
echo "< Source >"
python3 assemble.py tests/$1.asm tests/$1.bin
echo "< Input tape >"
cat tests/$1.in
echo "< Execution >"
python3 emu.py tests/$1.bin tests/$1.in tests/$1.out
echo ""
echo "< Output tape >"
cat tests/$1.out