#include "../inc/pathfinder.h"

void mx_delete_graph(a_list ***graph, size_t v_num) {
    for (size_t i = 0; i < v_num; i++) {
        mx_a_delete_list(&(*graph)[i]);
    }
    free(*graph);
    *graph = NULL;
}
