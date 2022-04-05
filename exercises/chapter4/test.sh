#!/usr/bin/env bash

source $PROJECT_ROOT/script/assert.sh
 
assert "compile_and_run_ex 4 1" 18 xxyiiixxjjxxxjjjxyxxiii,xx
assert "compile_and_run_ex 4 1" 17 xxyiiixxjjxxxjjjxyxxiii,y
assert "compile_and_run_ex 4 1" 14 xxyiiixxjjxxxjjjxyxxiii,jj
assert "compile_and_run_ex 4 1" -1 xxyiiixxjjxxxjjjxyxxiii,oo

assert "compile_and_run_ex 4 2" 123.000000 "123.0"
assert "compile_and_run_ex 4 2" 3200000.000000 "3.2e6"
assert "compile_and_run_ex 4 2" 0.003200 "3.2e-3"

assert_end "Chapter 4"