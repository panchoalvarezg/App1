// utils.c
#include <ctype.h>
#include "src/utils.h"

void to_lower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}
