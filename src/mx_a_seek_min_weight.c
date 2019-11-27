#include "../inc/pathfinder.h"

long mx_a_seek_min_weight(a_list *head, const size_t i) {
    long min_weight = 9999999999;

    for (a_list *walker = head; walker != NULL; walker = walker->next) {
        if (walker->index == i && min_weight > walker->weight) {
            min_weight = walker->weight;
        }
    }
    return min_weight;
}
