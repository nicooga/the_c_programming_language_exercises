#!/usr/bin/env bash
compile "$(current_directory $0 )/stack.test.c" && ./a.out &&
echo "--- Stack tests passed" || (echo "Stack tests failed" && exit 1)