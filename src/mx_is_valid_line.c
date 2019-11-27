#include "../inc/pathfinder.h"

bool mx_is_valid_line(const char *s) {
    int i = 0;
    int prev = 0;

    if (!s)
        return false;

    for ( ; mx_isalpha(s[i]) && s[i] != '\0'; i++);

    if (i == 0 || s[i] != '-')
        return false;

    for (prev = ++i; mx_isalpha(s[i]) && s[i] != '\0'; i++);

    if (i == prev || s[i] != ',')
        return false;

    for (prev = ++i; mx_isdigit(s[i]) && s[i] != '\0'; i++);

    if (i == prev || s[i] != '\0')
        return false;

    return true;
}
