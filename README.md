# get_next_line

A function that reads a line from a file descriptor, including multiple file descriptors simultaneously.

## Description

`get_next_line` reads a file descriptor line by line until reaching the end of the file. The bonus version supports reading from multiple file descriptors at the same time without losing the reading thread of each file descriptor.

## Features

- Reads one line at a time from a file descriptor
- Handles multiple file descriptors simultaneously (bonus)
- Efficient memory management
- Works with any buffer size
- Returns the line read without the newline character (if present)

## Files

### Mandatory
- `get_next_line.c` - Main function implementation
- `get_next_line_utils.c` - Helper functions
- `get_next_line.h` - Header file

### Bonus
- `get_next_line_bonus.c` - Main function with multiple FD support
- `get_next_line_utils_bonus.c` - Helper functions for bonus
- `get_next_line_bonus.h` - Header file for bonus

## Prototype

```c
char *get_next_line(int fd);
