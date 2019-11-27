#include "../inc/pathfinder.h"

a_list *mx_a_create_node(const size_t i, const long w) {
    a_list *node = (a_list *)malloc(sizeof(a_list));

    if (!node)
        return NULL;

    node->index = i;
    node->weight = w;
    node->next = NULL;

    return node;
}
