#include "../inc/pathfinder.h"

a_list *mx_a_sort_list(a_list *head) {
    if (!head)
        return NULL;

    for (a_list *i = head; i != NULL; i = i->next) {
        for (a_list *j = i->next; j != NULL; j = j->next) {
            if (j->index < i->index) {
                size_t temp1 = j->index;
                int temp2 = j->weight;

                j->index = i->index;
                j->weight = i->weight;
                i->index = temp1;
                i->weight = temp2;
            }
        }
    }
    return head;
}
