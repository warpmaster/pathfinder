#include "../inc/pathfinder.h"

void mx_e_print_list(e_list *head) {
    for (e_list *walker = head; walker != NULL; walker = walker->next) {
        mx_printstr(walker->vertex_1);
        mx_printstr(", ");
        mx_printstr(walker->vertex_2);
        mx_printstr(", ");
        mx_printint(walker->weight);
        mx_printchar('\n');
    }
}
