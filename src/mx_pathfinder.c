#include "../inc/pathfinder.h"

void mx_pathfinder(a_list ***graph, long *v_paths, a_list **v_from,
                                 size_t index, long carried_weight) {
    for (a_list *walker = (*graph)[index]; walker != NULL;
                                    walker = walker->next) {
        long new_weight = walker->weight + carried_weight;

        if (v_paths[walker->index] >= new_weight &&
                !mx_a_seek_node(v_from[walker->index], index, new_weight)) {
            v_paths[walker->index] = new_weight;
            mx_a_push_back(&v_from[walker->index], index, new_weight);

            //Delete node with longer path then current:
            mx_a_delete_longer_weights(&v_from[walker->index], new_weight);

            // Sort list according to index in a vertices array, for correct output:
            v_from[walker->index] = mx_a_sort_list(v_from[walker->index]);

            // Proceed pathfinding:
            mx_pathfinder(graph, v_paths, v_from, walker->index, new_weight);
        }
    }
}
