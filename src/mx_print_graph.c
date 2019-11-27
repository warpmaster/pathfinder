#include "../inc/pathfinder.h"

void mx_print_graph(a_list **graph, size_t v_num) {
    if (!graph)
        return;

    for (size_t i = 0; i < v_num; i++) {
        mx_printstr("Vertex ");
        mx_printint(i);
        mx_printstr(":\n");
        mx_a_print_list(graph[i]);
    }
}
