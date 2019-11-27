#include "../inc/pathfinder.h"

void mx_e_pop_front(e_list **head) {
    if (head == NULL || *head == NULL)
        return;

    e_list *temp = *head;
    *head = temp->next;
    mx_strdel(&temp->vertex_1);
    mx_strdel(&temp->vertex_2);
    free(temp);
}
