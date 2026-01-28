This project has been created as part of the 42 curriculum by nmeunier.
# ft_printf

A custom implementation of the standard C `printf` function. This project provides a lightweight library that replicates the core functionality of the standard library's printf, supporting various format specifiers and output formatting.

## Overview

`ft_printf` is a printf-like function designed to format and print strings with support for multiple data types and conversions. It processes format strings containing conversion specifiers and outputs the resulting formatted text.

## Features

### Supported Format Specifiers

- `%c` - Character conversion
- `%s` - String conversion
- `%p` - Pointer address in hexadecimal format (lowercase)
- `%d` - Integer conversion (decimal)
- `%i` - Integer conversion (decimal)
- `%u` - Unsigned integer conversion
- `%x` - Unsigned integer conversion in hexadecimal format (lowercase)
- `%X` - Unsigned integer conversion in hexadecimal format (uppercase)
- `%%` - Literal percent character

## Project Structure

### Core Files

- **ft_printf.c** - Main implementation containing the core `ft_printf` function and the conversion specifier dispatcher
- **ft_printf.h** - Header file with function declarations and necessary includes
- **functions.c** - Helper functions for character, string, and integer output handling
- **functions_hexa.c** - Specialized functions for hexadecimal and pointer conversions
- **Makefile** - Build configuration for compiling the library

## API Reference

### Main Function

`int ft_printf(const char *str, ...)`

Formats and prints a string with variable arguments, similar to the standard printf function. Returns the number of characters printed.

### Helper Functions

- `int ft_putchar(const char c)` - Output a single character
- `int ft_putstr(const char *str)` - Output a string
- `int ft_putnbr(int nbr)` - Output a signed integer
- `int ft_unsigned_nbr(unsigned int nbr)` - Output an unsigned integer
- `int ft_voidhexa(void *adress)` - Output a pointer address in hexadecimal format
- `int ft_putnbrhexa_low(unsigned int n)` - Output unsigned integer in lowercase hexadecimal
- `int ft_putnbrhexa_up(unsigned int n)` - Output unsigned integer in uppercase hexadecimal
- `int ft_putnbrhexa_low_long(unsigned long n)` - Output unsigned long in lowercase hexadecimal
- `int check(const char *str, int i, va_list *args)` - Dispatcher for format specifier handling

## Building

### Compilation

The project uses a Makefile with standard targets:

- `make` or `make all` - Compile the library to generate `libftprintf.a`
- `make clean` - Remove object files
- `make fclean` - Remove object files and the library archive

### Requirements

- GCC compiler with standard flags: `-Wall -Wextra -Werror`

## Dependencies

- Standard C library headers: `unistd.h`, `stdio.h`, `stdarg.h`

## Implementation Details

The implementation uses variadic arguments to handle variable numbers of parameters. The main parsing loop iterates through the format string, identifying conversion specifiers prefixed with `%`. When a specifier is encountered, it is dispatched to the appropriate handler function via the `check` function, which extracts the corresponding argument and processes the conversion.

The function returns the total number of characters printed, making it compatible with standard printf behavior.

## Author

nmeunier (42 school project)
