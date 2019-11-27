#include "../inc/pathfinder.h"

e_list *mx_e_create_node(const long w, const char *v1, const char *v2) {
    e_list *node = (e_list *)malloc(sizeof(e_list));

    if (!node)
        return NULL;

    node->weight = w;
    node->vertex_1 = mx_strdup(v1);
    node->vertex_2 = mx_strdup(v2);
    node->next = NULL;

    return node;
}
