#!/usr/bin/env bash

source $PROJECT_ROOT/script/assert.sh
 
assert "compile_and_run_ex 4 1" 18 xxyiiixxjjxxxjjjxyxxiii,xx
assert "compile_and_run_ex 4 1" 17 xxyiiixxjjxxxjjjxyxxiii,y
assert "compile_and_run_ex 4 1" 14 xxyiiixxjjxxxjjjxyxxiii,jj
assert "compile_and_run_ex 4 1" -1 xxyiiixxjjxxxjjjxyxxiii,oo

assert "compile_and_run_ex 4 2" 123.000000 "123.0"
assert "compile_and_run_ex 4 2" 3200000.000000 "3.2e6"
assert "compile_and_run_ex 4 2" 0.003200 "3.2e-3"

assert "compile_and_run_ex 4 3" "2.25" "1 2 + 3 * 4 /"
assert "compile_and_run_ex 4 3" "1" "1 2 + 3 * 4 %"
assert "compile_and_run_ex 4 3" "-5" "1 2 - 10 * 2 /"

assert_raises "compile_and_run_ex 4 4" 0

assert "compile_and_run_ex 4 5" "2.25" "1 2 + 3 * 4 /"
assert "compile_and_run_ex 4 5" "1" "1 2 + 3 * 4 %"
assert "compile_and_run_ex 4 5" "-5" "1 2 - 10 * 2 /"
assert "compile_and_run_ex 4 5" "9" "2 3 ^ 1 +"
assert "compile_and_run_ex 4 5" "0" "1 1 - s"
assert "compile_and_run_ex 4 5" "8.3890561" "2 e 1 +"

assert_end "Chapter 4"