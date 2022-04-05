#!/usr/bin/env bash

source $PROJECT_ROOT/script/assert.sh

tab="$(printf '\t')"
new_line="$(printf '\n')"

assert_raises "compile_and_run_ex 3 1" 0
assert "compile_and_run_ex 3 2" "asdf\tqwer\n" 'uasdf\tqwer\n'
assert "compile_and_run_ex 3 2" 'asdf\\tqwer\\n' "easdf${tab}qwer${new_line}"

assert "compile_and_run_ex 3 4" "$(cat <<EOF
n: 2147483647
my_itoa(n): 2147483647
EOF
)"

assert "compile_and_run_ex 3 5" "2710" "10000 16"
assert "compile_and_run_ex 3 5" "10011100010000" "10000 2"
assert "compile_and_run_ex 3 5" "23420" "10000 8"

assert "compile_and_run_ex 3 6" "     123" "123 8"

assert_end "Chapter 3"