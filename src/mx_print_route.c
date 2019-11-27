#include "../inc/pathfinder.h"

void mx_print_route(a_list *route, long *v_paths, char **vert_arr,
                                                    size_t start) {
    int v_counter = 0;
    a_list *last_node = route;

    for (; last_node->next != NULL; last_node = last_node->next);

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(vert_arr[start]);
    mx_printstr(" -> ");
    mx_printstr(vert_arr[last_node->index]);
    mx_printchar('\n');
    mx_printstr("Route: ");
    mx_printstr(vert_arr[start]);

    for (a_list *walker = route; walker != NULL; walker = walker->next,
                                                         v_counter++) {
        mx_printstr(" -> ");
        mx_printstr(vert_arr[walker->index]);
    }
    mx_printchar('\n');
    mx_printstr("Distance: ");

    for (a_list *walker = route; walker != NULL; walker = walker->next) {
        mx_printint(walker->weight);

        if (v_counter > 1 ) {
            walker->next ? mx_printstr(" + ") : mx_printstr(" = ");
        }
    }
    
    if (v_counter > 1 ) {
        mx_printint(v_paths[last_node->index]);
    }
    mx_printchar('\n');
    mx_printstr("========================================\n");
}
