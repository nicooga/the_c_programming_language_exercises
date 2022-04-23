#!/usr/bin/env bash

source $PROJECT_ROOT/script/assert.sh

assert "compile_and_run_ex 5 1" "123\n456\n" " 123   456   "
assert "compile_and_run_ex 5 1" "123\n456\n" " 123 - 456 "

assert "compile_and_run_ex 5 2" "12.300000\n4.560000\n" " 12.3   4.56   "
assert "compile_and_run_ex 5 2" "12.300000\n4.560000\n" " 12.3 - 4.56 "

assert_raises "compile_and_run_ex 5 3" 0
assert_raises "compile_and_run_ex 5 4" 0
assert_raises "compile_and_run_ex 5 5" 0

assert "compile_and_run_ex 5 7" "asdf\nqwer\nuiop\n" "$(cat << EOF
asdf
qwer
uiop
EOF
)"

assert "compile_and_run_ex 5 7" "asdf\nqwer\nuiop\nzxcv\n" "$(cat << EOF
asdf
qwer
uiop
zxcv
EOF
)"

assert "compile_and_run_ex 5 7" "asdf\nqwer\nuiop\nzxcv\n" "$(cat << EOF
asdf
qwer
uiop
zxcv
hjkl
EOF
)"

assert "compile_and_run_ex 5 7" "asdf\nqw\n" "$(cat << EOF
asdf
qw
EOF
)"

assert_end "Chapter 5"