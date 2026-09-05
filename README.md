# Get_next_line

_This project has been created as part
of the 42 curriculum by mradkovi_

## Description
`Get next line` is a function that returns a line read from a file descriptor.

It can be used to read files or to read standard input line by line . Its behavior is similar to the Linux tool `less`.

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
