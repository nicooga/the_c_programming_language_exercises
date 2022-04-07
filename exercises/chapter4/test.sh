#!/usr/bin/env bash

source $PROJECT_ROOT/script/assert.sh

new_line="$(printf '\n')"

assert_implements_basic_calculator_behavior() {
  assert "compile_and_run_ex 4 $1" 2.25 "1 2 + 3 * 4 /"
  assert "compile_and_run_ex 4 $1" 1 "1 2 + 3 * 4 %"
  assert "compile_and_run_ex 4 $1" -5 "1 2 - 10 * 2 /"
}

assert_implements_exponentiation() {
  assert "compile_and_run_ex 4 $1" 9 "2 3 ^ 1 +"
}

assert_implements_sin_function() {
  assert "compile_and_run_ex 4 $1" 0 "1 1 - s"
}

assert_implements_exp_function() {
  assert "compile_and_run_ex 4 $1" 8.3890561 "2 e 1 +"
}

assert_implements_intermediate_calculator_behavior() {
  assert_implements_exponentiation $1
  assert_implements_sin_function $1
  assert_implements_exp_function $1
}

assert_implements_calculator_variables() {
  assert "compile_and_run_ex 4 $1" "3\n4" "$(cat <<EOF
3 A =
A 1 +
EOF
  )"

  assert "compile_and_run_ex 4 $1" "3\n2\n5" "$(cat <<EOF
3 A =
2 Z =
A Z +
EOF
  )"

  assert "compile_and_run_ex 4 $1" "3\n4\n5" "$(cat <<EOF
3 A =
A 1 +
v 1 +
EOF
  )"
}
 
assert "compile_and_run_ex 4 1" 18 xxyiiixxjjxxxjjjxyxxiii,xx
assert "compile_and_run_ex 4 1" 17 xxyiiixxjjxxxjjjxyxxiii,y
assert "compile_and_run_ex 4 1" 14 xxyiiixxjjxxxjjjxyxxiii,jj
assert "compile_and_run_ex 4 1" -1 xxyiiixxjjxxxjjjxyxxiii,oo

assert "compile_and_run_ex 4 2" 123.000000 "123.0"
assert "compile_and_run_ex 4 2" 3200000.000000 "3.2e6"
assert "compile_and_run_ex 4 2" 0.003200 "3.2e-3"

assert_implements_basic_calculator_behavior 3

assert_raises "compile_and_run_ex 4 4" 0

assert_implements_basic_calculator_behavior 5
assert_implements_intermediate_calculator_behavior 5

assert_implements_basic_calculator_behavior 6
assert_implements_intermediate_calculator_behavior 6
assert_implements_calculator_variables 6

assert_end "Chapter 4"