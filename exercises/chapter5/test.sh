#!/usr/bin/env bash

source $PROJECT_ROOT/script/assert.sh

assert "compile_and_run_ex 5 1" "123\n456\n" " 123   456   "
assert "compile_and_run_ex 5 1" "123\n456\n" " 123 - 456 "

assert_end "Chapter 5"