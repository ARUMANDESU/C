the C `printf` format specifiers

## Format Specifier Syntax

```
%[flags][width][.precision][length]specifier
```

## Conversion Specifiers

| Specifier | Type | Output |
|-----------|------|--------|
| `%d` / `%i` | `int` | Signed decimal integer |
| `%u` | `unsigned int` | Unsigned decimal integer |
| `%o` | `unsigned int` | Unsigned octal |
| `%x` | `unsigned int` | Unsigned hexadecimal (lowercase) |
| `%X` | `unsigned int` | Unsigned hexadecimal (uppercase) |
| `%f` | `double` | Decimal floating point (e.g., `3.141593`) |
| `%F` | `double` | Same as `%f`, uppercase for `INF`/`NAN` |
| `%e` | `double` | Scientific notation (lowercase `e`) |
| `%E` | `double` | Scientific notation (uppercase `E`) |
| `%g` | `double` | Shorter of `%f` or `%e` |
| `%G` | `double` | Shorter of `%F` or `%E` |
| `%a` | `double` | Hexadecimal floating point (lowercase) |
| `%A` | `double` | Hexadecimal floating point (uppercase) |
| `%c` | `int` | Single character |
| `%s` | `char *` | Null-terminated string |
| `%p` | `void *` | Pointer address |
| `%n` | `int *` | Stores the number of characters written so far (no output) |
| `%%` | — | Literal `%` |

## Flags

| Flag | Meaning |
|------|---------|
| `-` | Left-justify within the field width |
| `+` | Always show sign for signed numbers |
| ` ` (space) | Prefix a space for positive signed numbers |
| `0` | Pad with leading zeros instead of spaces |
| `#` | Alternate form (`0x` prefix for `%x`, always a decimal point for `%f`, keep trailing zeros for `%g`) |

## Length Modifiers

| Modifier | Applies to | Type |
|----------|------------|------|
| `hh` | `d i o u x X` | `signed char` / `unsigned char` |
| `h` | `d i o u x X` | `short` / `unsigned short` |
| `l` | `d i o u x X` | `long` / `unsigned long` |
| `ll` | `d i o u x X` | `long long` / `unsigned long long` |
| `j` | `d i o u x X` | `intmax_t` / `uintmax_t` |
| `z` | `d i o u x X` | `size_t` / `ssize_t` |
| `t` | `d i o u x X` | `ptrdiff_t` |
| `L` | `f F e E g G a A` | `long double` |
| `l` | `c` | `wint_t` (wide character) |
| `l` | `s` | `wchar_t *` (wide string) |

## Width and Precision

| Syntax | Meaning |
|--------|---------|
| `%5d` | Minimum field width of 5 |
| `%-5d` | Width 5, left-justified |
| `%05d` | Width 5, zero-padded |
| `%.2f` | Two digits after the decimal point |
| `%.3s` | At most 3 characters of a string |
| `%*d` | Width taken from an `int` argument |
| `%.*f` | Precision taken from an `int` argument |

## Example

```c
#include <stdio.h>

int main(void) {
    int i = 42;
    unsigned int u = 255;
    double d = 3.14159;
    char c = 'A';
    char s[] = "hello";

    printf("%d %u %x %X %o\n", i, u, u, u, u);  // 42 255 ff FF 377
    printf("%f %e %g\n", d, d, d);              // 3.141590 3.141590e+00 3.14159
    printf("%c %s %%\n", c, s);                 // A hello %
    printf("[%5d] [%-5d] [%05d]\n", i, i, i);   // [   42] [42   ] [00042]
    printf("[%.2f] [%8.3f]\n", d, d);           // [3.14] [   3.142]
    return 0;
}
```
