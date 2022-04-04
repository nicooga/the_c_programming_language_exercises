#!/usr/bin/env bash

source $PROJECT_ROOT/vendor/assert.sh || exit 1

assert "compile_and_run_ex 2 1" "$(cat <<EOF
Limits as in standard headers:

char  -> -128 to 127
short -> -32768 to 32767
int   -> -2147483648 to 2147483647
long  -> -9223372036854775808 to 9223372036854775807

Computed limits:

char  -> -128 to 127
short -> -32768 to 32767
int   -> -2147483648 to 2147483647
long  -> -9223372036854775808 to 9223372036854775807
EOF
)"

assert "compile_and_run_ex 2 2" "s: asdf" "asdf"
assert "compile_and_run_ex 2 3" 3416 D58
assert "compile_and_run_ex 2 4" afaf "asdfasdf ds"
assert "compile_and_run_ex 2 5" 12 "asdfqweruiopzxcv zxcv"
assert "compile_and_run_ex 2 6" 738197568 "64 2 4 123"
assert "compile_and_run_ex 2 7" 983526355 "111111123 2 4"
assert "compile_and_run_ex 2 8" 48 "3 60"
assert "compile_and_run_ex 2 9" 12 4095
assert "compile_and_run_ex 2 10" abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ

assert_end "Chapter 2"