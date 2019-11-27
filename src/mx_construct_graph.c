#include "../inc/pathfinder.h"

void mx_construct_graph(a_list ***graph, e_list *source_list, char **vert_arr,
															size_t v_num) {
    for (e_list *walker = source_list; walker != NULL; walker = walker->next) {
        int v1_index = mx_search_str(vert_arr, v_num, walker->vertex_1);
        int v2_index = mx_search_str(vert_arr, v_num, walker->vertex_2);

        mx_a_push_back(&(*graph)[v1_index], v2_index, walker->weight);
        mx_a_push_back(&(*graph)[v2_index], v1_index, walker->weight);
    }
}
