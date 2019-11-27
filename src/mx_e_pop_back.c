#include "../inc/pathfinder.h"

void mx_e_pop_back(e_list **head) {
    if (head == NULL || *head == NULL)
        return;

    e_list *walker = *head;

    if (walker->next == NULL) {
        mx_strdel(&(*head)->vertex_1);
        mx_strdel(&(*head)->vertex_2);
        free(*head);
        *head = NULL;
        return;
    }

    for ( ; walker->next->next != NULL; walker = walker->next);
    mx_strdel(&walker->next->vertex_1);
    mx_strdel(&walker->next->vertex_2);
    free(walker->next);
    walker->next = NULL;
}
