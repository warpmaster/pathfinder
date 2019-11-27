#include "../inc/pathfinder.h"

int mx_search_str(char **arr, const size_t size, const char *str) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] != NULL && mx_strcmp(arr[i], str) == 0) {
            return i;
        }
    }
    return -1;
}
