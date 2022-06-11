#!/usr/bin/env bash
compile "$(current_directory $0 )/stack-v2.test.c" && ./a.out &&
echo "--- Stack V2 tests passed" || (echo "Stack tests failed" && exit 1)
