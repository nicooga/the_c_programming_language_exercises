#!/usr/bin/env bash

compile_and_run_ex 1 1 &&
compile_and_run_ex 1 2 &&
compile_and_run_ex 1 3 &&
compile_and_run_ex 1 4 &&
compile_and_run_ex 1 5 &&
echo "asdf" | compile_and_run_ex 1 6 &&
compile_and_run_ex 1 7 &&
echo -e "\t \nasdf" | compile_and_run_ex 1 8 &&
echo "       asdf                qwer         uiop       " | compile_and_run_ex 1 9 &&
echo  -e "\t \t \t \t \n \n \n \n " | compile_and_run_ex 1 10  &&
echo -e "  \n \n \n \n \t \t \t   asdf qwer " | compile_and_run_ex 1 11 &&
echo "asdf qwer uiop zxcv" | compile_and_run_ex 1 12 &&
echo "asdf asdf asdf asdf asdf qwer qwer yuaosdf zxcv" | compile_and_run_ex 1 13 &&
echo "asdf asdf asdf asdf asdf qwer qwer yuaosdf zxcv" | compile_and_run_ex 1 14 &&
compile_and_run_ex 1 15 &&
echo -e "asdf\nqwer   \nuiop               \n" | compile_and_run_ex 1 16 &&
echo -e "asdf\nqwer   \nuiop                                                                                            \n" | compile_and_run_ex 1 17 &&
echo -e "asdf \n \n \n asdf sadf wqer " | compile_and_run_ex 1 18 &&
echo -n "asdf" | compile_and_run_ex 1 19 &&
echo -e "// asdf\nmain() {}/*thisisacomment*/" | compile_and_run_ex 1 23 &&
echo -e "// asdf\nmain() {}/*thisisacomment*/" | compile_and_run_ex 1 24