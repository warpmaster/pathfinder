#include "../inc/pathfinder.h"

void mx_a_print_list(a_list *head) {
    for (a_list *walker = head; walker != NULL; walker = walker->next) {
        mx_printstr("index: ");
        mx_printint(walker->index);
        mx_printstr("; weight: ");
        mx_printint(walker->weight);
        // mx_printstr("; index_from: ");
        // mx_printint(walker->index_from);
        // mx_printstr("; total_weight: ");
        // mx_printint(walker->total_weight);
        mx_printchar('\n');
    }
}
