#include "../inc/pathfinder.h"

void mx_a_delete_list(a_list **head) {
    if (!head || !*head)
        return;

    a_list *walker = *head;

    while (walker != NULL) {
        a_list *temp = walker;
        walker = walker->next;
        free(temp);
    }
    *head = NULL;
}
