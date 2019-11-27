#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *trimmed = mx_strtrim(str);
    char *temp = mx_strnew(mx_strlen(trimmed));
    char *final = NULL;

    if (!str) return NULL;

    temp[0] = trimmed[0];
    for (int i = 1, j = 1; trimmed[i] != '\0'; i++) {
        if (!mx_isspace(trimmed[i]))
            temp[j++] = trimmed[i];
        if (mx_isspace(trimmed[i]) && !mx_isspace(trimmed[i-1]))
            temp[j++] = ' ';
    }
    free(trimmed);
    final = mx_strdup(temp);
    free(temp);

    return final;
}

