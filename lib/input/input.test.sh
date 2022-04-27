#!/usr/bin/env bash
compile "$(current_directory $0)/input.test.c" &&
(echo "asdf" | ./a.out) &&
echo "Input tests passed" || (echo "Input tests failed" && exit 1)