#!/usr/bin/env bash
gcc "$(current_directory $0)/test.c" &&
(echo "asdf" | ./a.out) &&
echo "Input tests passed"