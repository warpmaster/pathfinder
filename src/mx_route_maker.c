#include "../inc/pathfinder.h"

void mx_route_maker(a_list ***graph, const size_t v, a_list **v_from,
                             long *v_paths, char **vert_arr, a_list **route) {
    for (a_list *walker = v_from[v]; walker != NULL; walker = walker->next) {
        long min_weight = mx_a_seek_min_weight((*graph)[walker->index], v);

        mx_a_push_front(route, v, min_weight);

        if (v_paths[walker->index] == 0) {
            mx_print_route(*route, v_paths, vert_arr, walker->index);
        }

        mx_route_maker(graph, walker->index, v_from, v_paths, vert_arr, route);

        // Delete all nodes from head including current node (to make correct parallel routes):
        while ((*route)->index != v && (*route)->weight != min_weight) {
            mx_a_pop_front(route);
        }
        mx_a_pop_front(route);
    }
}
