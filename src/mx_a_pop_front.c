#include "../inc/pathfinder.h"

void mx_a_pop_front(a_list **head) {
    if (head == NULL || *head == NULL)
        return;

    a_list *temp = *head;
    *head = temp->next;
    free(temp);
}
