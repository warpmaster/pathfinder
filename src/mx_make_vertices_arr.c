#include "../inc/pathfinder.h"

void mx_make_vertices_arr(e_list *head, char **arr, size_t n) {
    size_t v = 0;

    for (e_list *walker = head; walker != NULL; walker = walker->next) {
        if (v > n) {
            mx_printerr("error: invalid number of islands\n");

            exit(6);
        }
        if (mx_search_str(arr, n, walker->vertex_1) < 0) {
            arr[v] = mx_strdup(walker->vertex_1);
            v++;
        }
        if (v > n) {
            mx_printerr("error: invalid number of islands\n");

            exit(6);
        }
        if (mx_search_str(arr, n, walker->vertex_2) < 0) {
            arr[v] = mx_strdup(walker->vertex_2);
            v++;
        }
    }
    if (v != n) {
        mx_printerr("error: invalid number of islands\n");

        exit(6);
    }
}
