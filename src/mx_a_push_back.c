#include "../inc/pathfinder.h"

void mx_a_push_back(a_list **head, size_t i, const long w) {
    if (*head == NULL) {
        *head = mx_a_create_node(i, w);
        return;
    }

    a_list *walker = *head;
    for (; walker->next != NULL; walker = walker->next);
    walker->next = mx_a_create_node(i, w);
}
