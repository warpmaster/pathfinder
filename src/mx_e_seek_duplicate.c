#include "../inc/pathfinder.h"

bool mx_e_seek_duplicate(e_list *head, const long w, const char *v1, 
                                                    const char *v2) {
    if (!head)
        return false; // perhaps unnecessary condition, check it later

    for (e_list *walker = head; walker != NULL; walker = walker->next) {
        if (walker->weight == w &&
            ((mx_strcmp(walker->vertex_1, v1) == 0 && 
                mx_strcmp(walker->vertex_2, v2) == 0) ||
            (mx_strcmp(walker->vertex_1, v2) == 0 && 
                mx_strcmp(walker->vertex_2, v1) == 0))) {
                return true;
            }
    }
    return false;
}
