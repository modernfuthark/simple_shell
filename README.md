**Simple Shell**\
Tim Sninksy, Matthew Feliciano\
04/02/20
---

# Description
- The implementation of a simple shell. A shell is a user intferace for access to an operating system's services. Shells use either a command-line interface or graphical user interface, depending on a computer's role and particular operation.
- You compile it with this command: 
- (./hsh [arg...])
## Example
./hsh
$ ls
README.md main.c
$
- __or__
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c 'test_ls_2'
$
## This Shell is abled to use the built-ins:

> `env`: Use this command to print environment variables.

> `exit`: Use this command to exit our shell.
---
# Files:
- __shell.h__: This file contains all the prototypes used for our shell project.

- __envMain.c__: This file gets the index of the PATH variable.

- __AUTHORS__: This file contains all the contributors to this repository.

- `man_1_simple_shell`: The man page for our shell.

- __shellMain.c__: This file contains the main function and helper function of our code.

- __builtins.c__: This file contains the code for the builtin functions of code.

- __execute.c__: Fork and execute a file.

- __stringFunctions.c__: This file contains the code that handles strings.
