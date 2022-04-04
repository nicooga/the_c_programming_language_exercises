#!/usr/bin/env bash

source $PROJECT_ROOT/vendor/assert.sh || exit 1

tab="$(printf '\t')"

assert "compile_and_run_ex 1 1" "hello, world"
assert "compile_and_run_ex 1 2" "d"

assert "compile_and_run_ex 1 3" "$(cat <<EOF
F°\tC°
300\t 148.9
280\t 137.8
260\t 126.7
240\t 115.6
220\t 104.4
200\t  93.3
180\t  82.2
160\t  71.1
140\t  60.0
120\t  48.9
100\t  37.8
 80\t  26.7
 60\t  15.6
 40\t   4.4
 20\t  -6.7
  0\t -17.8
EOF
)"

assert "compile_and_run_ex 1 4" "$(cat <<EOF
C°\tF°
  0\t  32.0
 20\t  68.0
 40\t 104.0
 60\t 140.0
 80\t 176.0
100\t 212.0
120\t 248.0
140\t 284.0
160\t 320.0
180\t 356.0
200\t 392.0
220\t 428.0
240\t 464.0
260\t 500.0
280\t 536.0
300\t 572.0
EOF
)"

assert "compile_and_run_ex 1 5" "$(cat <<EOF
C°\tF°
300\t 572.0
280\t 536.0
260\t 500.0
240\t 464.0
220\t 428.0
200\t 392.0
180\t 356.0
160\t 320.0
140\t 284.0
120\t 248.0
100\t 212.0
 80\t 176.0
 60\t 140.0
 40\t 104.0
 20\t  68.0
  0\t  32.0
EOF
)"

assert "compile_and_run_ex 1 6" "$(cat <<EOF
1
1
1
1
1
0
EOF
)" "asdf"

assert "compile_and_run_ex 1 7" -1

assert "compile_and_run_ex 1 8" "5" "$(cat <<EOF
asdf$tab$tab
qwer
uiop
EOF
)"

assert "compile_and_run_ex 1 9" " asdf qwer uiop " "    asdf          qwer   uiop         "
assert "compile_and_run_ex 1 10" 'asdf\\t\\t\\' "asdf$tab$tab\\"

assert "compile_and_run_ex 1 11" "5 16 98" "$(cat <<EOF
Lorem ipsum dolor amet.${tab}

Lorem ipsum dolor amet.
Lorem ipsum dolor amet.
Lorem ipsum dolor amet.
EOF
)"

assert "compile_and_run_ex 1 12" "asdf\nqwer\nuiop\n" "asdf qwer uiop"

assert "compile_and_run_ex 1 13" "  1: ---\n  2: ----\n  3: ---\n  4: -" "$(cat <<EOF
xxx
xxx
xxxx
xx
xxx
x
xx
xx
xx
x
x
EOF
)"

assert "echo -n abcaad | compile_and_run_ex 1 14" "a: --\nb: -\nc: -\nd: -"

assert "compile_and_run_ex 1 15" "$(cat <<EOF
F°\tC°
  0\t -17.8
 20\t  -6.7
 40\t   4.4
 60\t  15.6
 80\t  26.7
100\t  37.8
120\t  48.9
140\t  60.0
160\t  71.1
180\t  82.2
200\t  93.3
220\t 104.4
240\t 115.6
260\t 126.7
280\t 137.8
300\t 148.9
EOF
)"

assert "compile_and_run_ex 1 16" "xxxxxxxxxxxxxxxx" "$(cat <<EOF
xxxxxx
xx
xxxx
xxx
xxxxxxxxxxxxxxxx
xxxxxxxxxxxx
xxx
EOF
)"

long_line="                                                                                                  "

assert "compile_and_run_ex 1 17" "$long_line" "$(cat <<EOF
asdf
qwerqwer
asdfasdf
$long_line
EOF
)"

assert "compile_and_run_ex 1 18" "asdf\nqwerqwer\nasdfasdf" "$(cat <<EOF
asdf$tab$tab
qwerqwer

asdfasdf

EOF
)"

assert "compile_and_run_ex 1 19" "fdsa\nrewq\npoiu" "$(cat <<EOF
asdf
qwer
uiop
EOF
)"

assert "compile_and_run_ex 1 23" "\nint main(void) {\n  \n}" "$(cat <<EOF
// This is a line comment
int main(void) {
  /* This is a block comment */
}
EOF
)"

assert_raises "compile_and_run_ex 1 24" 0 "$(cat <<EOF
int main() {
  "{}]";
  return 0;
}
EOF
)"

assert_raises "compile_and_run_ex 1 24" 1 "$(cat <<EOF
int main() {
  "{}];
  return 0;
}
EOF
)"

assert_end "Chapter 1"