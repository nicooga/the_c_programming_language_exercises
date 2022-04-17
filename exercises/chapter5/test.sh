#!/usr/bin/env bash

source $PROJECT_ROOT/script/assert.sh

assert "compile_and_run_ex 5 1" "123\n456\n" " 123   456   "
assert "compile_and_run_ex 5 1" "123\n456\n" " 123 - 456 "

assert "compile_and_run_ex 5 2" "12.300000\n4.560000\n" " 12.3   4.56   "
assert "compile_and_run_ex 5 2" "12.300000\n4.560000\n" " 12.3 - 4.56 "

assert_raises "compile_and_run_ex 5 3" 0

assert_end "Chapter 5"