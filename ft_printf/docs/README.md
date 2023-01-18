# ft_printf

The goal of this project is pretty straightforward. You will recode `printf()`. You will mainly learn about using a variable number of arguments.


| **Name** | `libftprintf.a` |
|----------|-----------------|
| **Description** | Write a library that contains `ft_printf()`, a function that will mimic the original `printf()`. |
| **Libft Authorised** | Yes |


| **Name** | `ft_printf` |
|----------|-----------------|
| **Synopsis** | `int ft_printf(const char *format, ...)` |
| **Description** | The `ft_print` function writes output to stdout according to a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of `stdarg(3)`) are converted. |
| **Return Values** | If successful, the `ft_printf` function returns the number of characters printed. If an error occurred, it returns a negative value. |
| **External Functions** | `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end` |
