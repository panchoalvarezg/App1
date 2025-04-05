// utils.c
#include <ctype.h>
#include "utils.h"

void to_lower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}
