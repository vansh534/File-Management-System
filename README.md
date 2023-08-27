# File Management System in C

This is a simple file management system implemented in C. It provides 
basic functionality for managing files using custom library and 
including it in the main program by user-specific access control.

## Features

- File creation, deletion, and manipulation
- User Authentication using bit manipulation
- Displays the usage of RAM during the execution along with the time taken 
by it in the CPU.
- User-specific access control
- Storage allocation and optimization

## Getting Started

### Prerequisites

- C Compiler (e.g., GCC)
- Access To The Custom Static Library

### Compilation

Compile the program using a C compiler. For example:

```sh
gcc file_management.c -o file_management
```
##How to run it by linking the library with program

Use the following commands:

First Compile The lib.c library file:

```sh
gcc -c lib.c -o lib_output
```

Now create a archive file for the library using:

```sh
ar rcs lib_file_management_system.a lib_output
```
Now create a main.c program file and link with the archive using:

```sh
gcc -o sample_output main.c -L. lib_file_management.a

