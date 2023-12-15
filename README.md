# *C - Simple Shell*

### Table of contents

- [Description](#description)
- [Files](#files)
- [Features](#features)
- [Flags](#flags)
- [Usage](#usage)
- [Examples](#examples)
- [Resources](#resources)
- [Credits](#credits)

## Description

This is our *Simple Shell* project for Holberton Coding School. The task for this project was to make our own version of a *Unix Command Interpreter* program, called `simple_shell`. This program receives *input* from the user and *executes* the respective *command* and prints back to the *standard output*.

## Files

- `AUTHORS` - File that contains the project authors.
- `README.md` - File that contains project description.
- `man_1_simple_shell` - File that contains the manual of the program.
- `main.h` - Header file containing function prototypes.
- `simple_shell.c` - Main shell function.
- `functions.c` - File that contains the helper functions for the main code.
- `free_arrays.c` - Function that frees arrays.

## Features

This are the commands that our program can run:

- `pwd` - prints current working directory.
- `ls` - list current directory files.
- `cp` - copies a file and the contents of it.
- `mv` - move or rename a file.
- `rm` - deletes the specified file(s). 
- `touch` - creates a file.
- `echo` - sends text to a file.
- `cat` - shows/prints a file contents.
- `chmod` - changes file's permissions.
- `exit` - exits the shell.

## Flags

1. ls
   - `-l` - Long format.
   - `-a` - All files.
   - `-r` - Reverse order.
2. rm
   - `-r` - Recursive removal.
  
## Usage

To use the program, run the `./hsh` executable to open the prompt:

```c
prodjohnper@penguin:~/holbertonschool-simple_shell$ ./hsh
($)
```

Then type the command to execute it:

```c
prodjohnper@penguin:~/holbertonschool-simple_shell$ ./hsh
($) /bin/pwd
Executing command: /bin/pwd
/home/prodjohnper/holbertonschool-simple_shell
($)
```

When done, close the program with the `exit` command or the EoF marker `CTRL+D`:

```c
prodjohnper@penguin:~/holbertonschool-simple_shell$ ./hsh
($) /bin/pwd
Executing command: /bin/pwd
/home/prodjohnper/holbertonschool-simple_shell
($) exit
prodjohnper@penguin:~/holbertonschool-simple_shell$
```

## Examples

Here are some examples of the commands that can be used in our shell program:

- `pwd` command:

```c
prodjohnper@penguin:~/holbertonschool-simple_shell$ ./hsh
($) /bin/pwd
Executing command: /bin/pwd
/home/prodjohnper/holbertonschool-simple_shell
($)
```
- `ls -l` command:

```c
prodjohnper@penguin:~/holbertonschool-simple_shell$ ./hsh
($) /bin/ls -l
Executing command: /bin/ls
total 48
-rw-r--r-- 1 prodjohnper prodjohnper   149 Dec 14 21:30 AUTHORS
-rw-r--r-- 1 prodjohnper prodjohnper   756 Dec  7 11:00 README.md
-rw-r--r-- 1 prodjohnper prodjohnper   216 Dec 14 21:36 free_arrays.c
-rw-r--r-- 1 prodjohnper prodjohnper  1597 Dec 14 22:04 functions.c
-rwxr-xr-x 1 prodjohnper prodjohnper 17768 Dec 14 21:49 hsh
-rw-r--r-- 1 prodjohnper prodjohnper   340 Dec 14 21:35 main.h
-rw-r--r-- 1 prodjohnper prodjohnper   825 Dec 14 21:34 man_shell.1
-rw-r--r-- 1 prodjohnper prodjohnper   633 Dec 14 21:51 simple_shell.c
($)
```
- `exit` command:

```c
prodjohnper@penguin:~/holbertonschool-simple_shell$ ./hsh
($) exit
prodjohnper@penguin:~/holbertonschool-simple_shell$
```

## Resources

- *[Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)*
- *[Thompson Shell](https://en.wikipedia.org/wiki/Thompson_shell)*
- *[Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)*

## Credits

- *[Jonathan Pérez](https://github.com/prodjohnper)*
- *[Osvaldo Antompietri](https://github.com/ojvl1)*
