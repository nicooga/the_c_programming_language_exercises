#!/usr/bin/env bash
gcc "$(current_directory $0 )/test.c" && ./a.out &&
echo "Stack tests passed"