#include "../inc/pathfinder.h"

void mx_a_pop_back(a_list **head) {
    if (head == NULL || *head == NULL)
        return;

    a_list *walker = *head;

    if (walker->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    for ( ; walker->next->next != NULL; walker = walker->next);
    free(walker->next);
    walker->next = NULL;
}
