# Get Next Line

This project is about programming a function that returns a line read from a file descriptor.


| **Name** | `get_next_line` |
|----------|-----------------|
| **Synopsis** | `char *get_next_line(int fd);` |
| **Description** | The `get_next_line` function returns a line read from a file descriptor. |
| **Return Values** | If successful, the `get_next_line` function returns the line read from the file descriptor. If there is nothing else to read or an error occurred, it returns a `NULL` pointer. |
| **External Functions** | `read`, `malloc`, `free` |
