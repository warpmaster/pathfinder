#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int needle_len = mx_strlen(needle);
    int haystack_len = mx_strlen(haystack);

    if (needle_len == 0 && haystack_len == 0) // this special condition added to get such behavior as libc strstr()
        return "";
    if (needle_len == 0 && haystack_len != 0) // this special condition added to get such behavior as libc strstr()
        return (char *)haystack;

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (mx_strncmp(&haystack[i], needle, needle_len) == 0)
            return (char *)&haystack[i];
    }
    return NULL;
}
