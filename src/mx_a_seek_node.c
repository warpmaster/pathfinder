#include "../inc/pathfinder.h"

bool mx_a_seek_node(a_list *head, const size_t i, const long w) {
    for (a_list *walker = head; walker != NULL; walker = walker->next) {
        if (walker->index == i && walker->weight == w) {
            return true;
        }
    }
    return false;
}
