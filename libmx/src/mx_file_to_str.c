#include "libmx.h"

char *mx_file_to_str(const char *file) {
    size_t size = 256;
    int fd = -1;
    char *str = NULL;

    if (!file)
        return NULL;

    if ((fd = open(file, O_RDONLY)) == -1)
        return NULL;

    str = mx_strnew(size);

    for (unsigned long long i = 0; read(fd, &str[i], 1) > 0; i++) {
        if (i == size - 2) {
            size += size;
            char *temp = mx_strnew(size);

            if (!temp) {
                free(str);
                return NULL;
            }
            mx_strcpy(temp, str);
            free(str);
            str = temp;
        }
    }
    close(fd);

    char *temp = mx_strdup(str);
    free(str);
    str = temp;

    return str;
}
