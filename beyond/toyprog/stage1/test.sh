#!/bin/sh
cd tests
echo "## Basics ##"
echo
./single_run_quiet.sh test01
echo
echo "## Loops & conditions ##"
echo
./single_run_quiet.sh test02