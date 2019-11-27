#include "../inc/pathfinder.h"

void mx_a_delete_longer_weights(a_list **head, long new_weight) {
    a_list *walker = *head;
    a_list *prev = *head;

    while (walker != NULL) {
        if (walker->weight > new_weight) {
            a_list *temp = walker;
            prev = walker->next;
            walker = walker->next;
            if (*head == temp) {
                *head = walker;
            }
            free(temp);
        } else {
            prev = walker;
            walker = walker->next;
        }
    }
}
