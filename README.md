# MY LIBASM
A collection of functions from the Standard C Library written in x86-64 Assembly.

## Project Structure

The libasm source code can be found in the `lib/` directory. The functions are made available to C via `src/libasm.h`.

Use `make` to compile and link the assembly code:

    $ make

This will produce the binary `bin/main`. This binary will execute and run tests for all libasm functions. The output of both libasm and the Stardard C Library function calls will be returned when an error is encountered.

    $ ./bin/main

    strlen passed!
    strchr passed!
    memset passed!
    memcpy passed!
    strcmp passed!
    memmove passed!
    strncmp passed!
    strcasecmp passed!
    index passed!
    read passed!
    write passed!


`make clean` will clean up the binary and object files .


## Running and Editing tests

You can find the tests in the `src/main.c` source file. Feel free to comment, edit or create new tests during your review process.

`my_read` and `my_write` use external files. These are found in the `test_files/` directory. Note the `my_write` test will always create and delete the files during test.

Make sure you `make clean` after you make a change to `src/main.c`.

    $ make clean && make $$ ./bin/main
