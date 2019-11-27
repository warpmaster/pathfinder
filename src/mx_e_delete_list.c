#include "../inc/pathfinder.h"

void mx_e_delete_list(e_list **head) {
    if (!head || !*head)
        return;

    e_list *walker = *head;

    while (walker != NULL) {
        e_list *temp = walker;
        walker = walker->next;
        mx_strdel(&temp->vertex_1);
        mx_strdel(&temp->vertex_2);
        free(temp);
    }
    *head = NULL;
}
