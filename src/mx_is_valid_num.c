#include "../inc/pathfinder.h"

bool mx_is_valid_num(const char *s) {
    if (!s)
        return false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!mx_isdigit(s[i]) || i > 8) {
            return false;
        }
    }
    return true;
}
