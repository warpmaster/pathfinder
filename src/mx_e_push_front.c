#include "../inc/pathfinder.h"

void mx_e_push_front(e_list **head, const long w, const char *v1, const char *v2) {
    e_list *new_node = mx_e_create_node(w, v1, v2);
    new_node->next = *head;
    *head = new_node;
}
