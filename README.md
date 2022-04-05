[![CI](https://github.com/nicooga/the_c_programming_language_exercises/actions/workflows/main.yml/badge.svg)](https://github.com/nicooga/the_c_programming_language_exercises/actions/workflows/main.yml)

# "The C Programming Language" solved exercises

This a collection of solved exercises for the book "The C Programming Language" by Brian W. Kernighan and Dennis M. Ritchie.

### Scripts

I've wrote a few Bash scripts for my own usage:

~~~bash
./scripts/generate_ex <chapter> <exercise>
./scripts/compile_and_run <chapter> <exercise>
~~~

In order for all these scripts to work properly, env var PROJECT_ROOT must be set, and the `script/` should be added to your path.
I use direnv to automate these tasks for me.

### This project is tested

I've written a rudimentary test suite using a mix of assertions at bash level, and some C level tests.
You can run the tests via `run_tests` script.

This testing is not top-knotch, but is enough to give me confidence that I'm not breaking the code base when sharing code among exercises.