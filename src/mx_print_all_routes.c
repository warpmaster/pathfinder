#include "../inc/pathfinder.h"

void mx_print_all_routes(a_list ***graph, char **vert_arr, size_t v_num) {
    long vertex_paths[v_num];
    a_list **vertex_from = (a_list **)malloc(sizeof(a_list *) * v_num);

    //initialize paths:
    for (size_t i = 0; i < v_num; i++) {
        vertex_paths[i] = 9999999999;
        vertex_from[i] = NULL;
    }

    for (size_t start_index = 0; start_index < v_num; start_index++) {
        vertex_paths[start_index] = 0;

        // calculate shortest paths from current vertex to all other vertices:
        mx_pathfinder(graph, vertex_paths, vertex_from, start_index, 0);

        // make all routes and print them:
        for (size_t v = start_index + 1; v < v_num; v++) {
            a_list *route = NULL;
            
            mx_route_maker(graph, v, vertex_from, vertex_paths, vert_arr, 
                                                                    &route);
            mx_a_delete_list(&route);
        }

        //reset paths:
        for (size_t i = 0; i < v_num; i++) {
            vertex_paths[i] = 9999999999;
            mx_a_delete_list(&vertex_from[i]);
        }
    }
    free(vertex_from);
}
