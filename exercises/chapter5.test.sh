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

test_day_functions_behavior() {
  cmd="compile_and_run_ex 5 $1"

  assert "$cmd" "113" "day_of_year  2022 04 23"
  assert "$cmd" "Invalid year \`-1\`. Year must be a positive number\n" "day_of_year -1 04 23"
  assert "$cmd" "Invalid year \`0\`. Year must be a positive number\n" "day_of_year 0 04 23"
  assert "$cmd" "Invalid month \`-1\`. Month must be a positive number\n" "day_of_year 2002 -1 23"
  assert "$cmd" "Invalid month \`0\`. Month must be a positive number\n" "day_of_year 2002 0 23"
  assert "$cmd" "Invalid month \`13\`. Month must be a less than or equal to 12\n" "day_of_year 2002 13 23"
  assert "$cmd" "Invalid day \`-1\`. Day must be a positive number\n" "day_of_year 2002 04 -1"
  assert "$cmd" "Invalid day \`32\`. No day can be greater than 31\n" "day_of_year 2002 04 32"

  assert "$cmd" "4 23" "month_day 2022 113"
  assert "$cmd" "Invalid year \`-1\`. Year must be a positive number\n" "month_day -1 113"
  assert "$cmd" "Invalid year \`0\`. Year must be a positive number\n" "month_day 0 113"
  assert "$cmd" "Invalid year day \`-1\`. Year day must be a positive number\n" "month_day 1 -1"
  assert "$cmd" "Invalid year day \`0\`. Year day must be a positive number\n" "month_day 1 0"
  assert "$cmd" "Invalid year day \`366\`. Year 1 is not a leap year and has only 365 days\n" "month_day 1 366"
  assert "$cmd" "Invalid year day \`367\`. Year 4 is a leap year and has only 366 days\n" "month_day 4 367"
}

test_day_functions_behavior 8
test_day_functions_behavior 9

assert "compile_and_run_ex 5 10" 14.00 "2 3 4 + *"
assert "compile_and_run_ex 5 10" 21.00 "2 3 4 + * 7 +"
assert "compile_and_run_ex 5 10" 1.00 "2 1 -"
assert "compile_and_run_ex 5 10" -5.00 "2 1 3 4 + - * 7 +"

assert "compile_and_run_ex 5 13 -n 3" "asdf\nqwer\nuiop\n" "$(cat << EOF
asdf
qwer
uiop
EOF
)"

assert "compile_and_run_ex 5 13 -n 1" "uiop\n" "$(cat << EOF
asdf
qwer
uiop
EOF
)"

assert "compile_and_run_ex 5 13 -n 0" "" "$(cat << EOF
asdf
qwer
uiop
EOF
)"

assert "compile_and_run_ex 5 13 -n -1" "" "$(cat << EOF
asdf
qwer
uiop
EOF
)"

assert "compile_and_run_ex 5 13 -n asdf" "" "asdf"
assert "compile_and_run_ex 5 13 -n" "" "asdf"
assert "compile_and_run_ex 5 13" "" "asdf"

assert_end "Chapter 5"
