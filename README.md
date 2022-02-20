#MY LIBASM
A collection of functions from the Standard C Library written in x86-64 assembly.


## Project Structure

The libasm source code can be found in the `lib/` directory. The functions are made available to C via de `src/libasm.h`.

Use `make` to compile and link the assembly code:

    make

This will produce a a binary `bin/main`. This binary will execute and test all libasm functions and return an error when a test fails.

`make clean` will clean up the binary and object files .


## Running and Editing tests

You can find the tests in the `src/main.c` source file. Feel free to comment, edit or create new tests during your review process.

`my_read` and `my_write` use external files. These are found in the `test_files/` directory. Note the `my_write` test will always create and delete the files during test.
