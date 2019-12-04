#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct e_list {
    char *vertex_1;
    char *vertex_2;
    long weight;
    struct e_list *next;
} e_list;

typedef struct a_list {
    size_t index;
    long weight;
    struct a_list *next;
} a_list;

e_list *mx_e_create_node(const long w, const char *v1, const char *v2);
void mx_e_push_front(e_list **head, const long w, const char *v1, const char *v2);
void mx_e_push_back(e_list **head, const long w, const char *v1, const char *v2);
void mx_e_pop_front(e_list **head);
void mx_e_pop_back(e_list **head);
bool mx_e_seek_duplicate(e_list *head, const long w, const char *v1, const char *v2);
bool mx_a_seek_node(a_list *head, const size_t i, const long w);
void mx_e_print_list(e_list *head);
void mx_e_delete_list(e_list **head);

a_list *mx_a_create_node(const size_t i, const long w);
void mx_a_push_front(a_list **head, const size_t i, const long w);
void mx_a_push_back(a_list **head, const size_t i, const long w);
void mx_a_pop_front(a_list **head);
void mx_a_pop_back(a_list **head);
long mx_a_seek_min_weight(a_list *head, const size_t i);
void mx_a_print_list(a_list *head);
void mx_a_delete_list(a_list **head);
void mx_a_delete_longer_weights(a_list **head, long new_weight);
a_list *mx_a_sort_list(a_list *head);

bool mx_is_valid_num(const char *s);
bool mx_is_valid_line(const char *s);
int mx_search_str(char **arr, const size_t size, const char *str);
void mx_make_vertices_arr(e_list *head, char **arr, size_t n);
void mx_construct_graph(a_list ***graph, e_list *source_list, char **vert_arr, size_t v_num);
void mx_pathfinder(a_list ***graph, long *v_paths, a_list **v_from, size_t index, long carried_weight);
void mx_print_graph(a_list **graph, size_t v_num);
void mx_delete_graph(a_list ***graph, size_t v_num);
void mx_route_maker(a_list ***graph, const size_t v, a_list **v_from, long *v_paths, char **vert_arr, a_list **route);
void mx_print_all_routes(a_list ***graph, char **vert_arr, size_t v_num);
void mx_print_route(a_list *route, long *v_paths, char **vert_arr, size_t start);

#endif
