#include "../inc/pathfinder.h"

void mx_e_push_back(e_list **head, const long w, const char *v1, const char *v2) {
    if (*head == NULL) {
        *head = mx_e_create_node(w, v1, v2);
        return;
    }

    e_list *walker = *head;
    for (; walker->next != NULL; walker = walker->next);
    walker->next = mx_e_create_node(w, v1, v2);
}
