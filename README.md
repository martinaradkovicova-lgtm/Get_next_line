# Get_next_line

_This project has been created as part
of the 42 curriculum by mradkovi_.

## Description
`Get next line` is a function that returns a line read from a file descriptor.

It can be used to read files or to read standard input line by line. 

### Project Files
- **get_next_line.c** is the main file containing the get_next_line function and all its helper functions.
    1. **get_next_line** this function is the core of the project itself, where all other parts are called. It returns a single line.
    2. **read_file** this function allocates memory of size `SIZE_BUFFER` (specified at compile time) and reads from the file descriptor. Handling potential issues.
    3. **read_file_error** A function to clear memory if an error occurs while using the read function.
    4. **extract_new_line** This function finds the end of the line in the input buffered from the file descriptor and then extracts the substring. It returns all characters from the beginning up to the occurrence of the newline character, including the newline character itself. Handling potential issues.
    5. **trim_static_storage** This function finds the end-of-line character in the input stored from the file descriptor and subsequently retrieves and returns the substring following that character. Handling potential issues. 
- **get_next_line_utils.c** contains helper functions that are used in the project.
    1. **ft_strlen** calculates and returns the length of the string. 
    2. **ft_strdup** calculates and allocates the necessary memory and stores a copy of the string in it.
    3. **ft_strjoin** It combines two strings into one and allocates new memory for the result. The source string is appended to the end of the destination string.
    4. **ft_strchr** finds a character in a string and returns the position of its first occurrence from the beginning.
    5. **ft_substr** It is used to find and return a substring, for which it allocates new memory.
- **get_next_line.h** This file stores the prototypes of helper functions and includes the necessary libraries required for `get_next_line` to run.

### Project diagram
![Diagram](https://raw.githubusercontent.com/martinaradkovicova-lgtm/Get_next_line/refs/heads/main/diagram_get_next_line.png)

## Instructions

Including the header file:
```c
#include "get_next_line.h"
```
Compile:
```bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<n> get_next_line.c get_next_line_utils.c 
```
`BUFFER_SIZE` is defined during the compilation
_( -D BUFFER_SIZE=42 )_

## Resources
* **System manual pages** (`man` `3` `"function_name"` and `man` `2` `"function_name"`)
* **Info and apropos command** (`info` `"function_name"`, `apropos` `"function_name"`)  
### Books
* **The Linux Programming Interface** (https://man7.org/tlpi/) by Michael Kerrisk - Chapter 4 (File I/O:The Universal I/O Model) Chapter 5 (File I/O: Further Details)
* **Advanced Programming in the UNIX Enviroment** (http://www.apuebook.com/apue3e.html) by W. Richard Stevens, Stephen A. Rago - Chapter 3 (File I/O)
### Links
* [Static variables] (https://www.geeksforgeeks.org/c/static-variables-in-c/)
* [Valgrind User Manual] (https://valgrind.org/docs/manual/manual.html)
* [Plantuml guide] (https://plantuml.com/guide) Used for designing and rendering the project architecture diagram.
### AI usage
* **Gemini AI** assisting with PlantUML syntax for the flowchart and explaining edge cases.
* **Perplexity AI** used as a search assistant to locate relevant documentation, standard C specifications and recommended literature.
