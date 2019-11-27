#include "libmx.h"

static void add_to_line(char **lineptr, char *fragment, int fr_len) {
    int ptr_len = mx_strlen(*lineptr);
    char *temp = NULL;

    if (*lineptr) {
        temp = mx_strncat(mx_strcpy(mx_strnew(ptr_len + fr_len), *lineptr), fragment, fr_len);
        free(*lineptr);
    } else {
        temp = mx_strndup(fragment, fr_len);
    }
    *lineptr = temp;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || buf_size <= 0) return -2;

    static char *static_buf = NULL;
    char *buf = mx_strnew(buf_size-1);
    int br = 0, di = 0, total_bytes = 0;

    if (!buf)
        return -2;

    // First step: read from the static buffer, if exists:
    if (static_buf) {
        int di = mx_get_char_index(static_buf, delim);
        int buf_len = mx_strlen(static_buf);

        if (di >= 0) {
            // add fragment until delimeter to line:
            add_to_line(lineptr, static_buf, di);

            // reduce static buffer by fragment length:
            char *temp = mx_strndup(&static_buf[di+1], buf_len - (di+1));

            free(static_buf);
            static_buf = temp;
            free(buf);
            return total_bytes += di;
        } else {

            // if delimeter not found then add whole static buffer to line:
            add_to_line(lineptr, static_buf, buf_len);
            total_bytes += buf_len;
            free(static_buf);
            static_buf = NULL;
        }
    }
    // Second step: read from the file descriptor:
    while ((br = read(fd, buf, buf_size)) > 0) {

        // check for delimeter within buffer:
        if ((di = mx_get_char_index(buf, delim)) >= 0) {
            add_to_line(lineptr, buf, di);
            static_buf = mx_strndup(&buf[di+1], br - (di+1));
            free(buf);
            return total_bytes += di;
        }
        add_to_line(lineptr, buf, br);
        total_bytes += br;
        mx_memset(buf, '\0', buf_size);
    }
    free(buf);

    return -1;
}

// static void add_to_line(char **lineptr, char *fragment, int fr_len) {
//     if (fd < 0 || buf_size <= 0) return -1;

//     char buffer[buf_size];
//     int line_size = 0, br = 0, di = 0, total_bytes_read = 0;
//     unsigned int pos = 0;

//     *lineptr = mx_strnew(buf_size);
//     line_size = buf_size;

//     while ((br = read(fd, buffer, buf_size)) == buf_size && (di = mx_get_char_index(buffer, delim)) < 0) {
//         mx_strcat(&(*lineptr)[pos], buffer);
//         pos += buf_size;
//         // --------------------------
//         line_size += buf_size;
//         char *temp = mx_strnew(line_size);
//         mx_strcpy(temp, *lineptr);
//         free(*lineptr);
//         *lineptr = temp;
//         // --------------------------
//         total_bytes_read += buf_size;
//     }
//     if (di >= 0) {
//         mx_strncat(&(*lineptr)[pos], buffer, di);
//         total_bytes_read += di;
//         lseek(fd, di - br + 1, SEEK_CUR);
//     } else {
//         mx_strncat(&(*lineptr)[pos], buffer, br);
//         total_bytes_read += br;
//     }
//     return total_bytes_read;
// }
