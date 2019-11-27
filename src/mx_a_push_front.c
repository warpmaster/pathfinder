#include "../inc/pathfinder.h"

void mx_a_push_front(a_list **head, size_t i, const long w) {
    a_list *new_node = mx_a_create_node(i, w);
    new_node->next = *head;
    *head = new_node;
}
