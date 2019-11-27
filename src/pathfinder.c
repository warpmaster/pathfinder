#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
    const int buffer_size = 128;
    a_list **graph = NULL;
    e_list *e_head = NULL;
    char *line = NULL;
    char **vertices = NULL;
    int v_num = 0;
    int fd = -1;
    int br = 0;

    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        
        return 1;
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");

        return 2;
    }

    br = mx_read_line(&line, buffer_size, '\n', fd);

    if (br < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");

        return 3;
    }

    if (!mx_is_valid_num(line)) {
        mx_printerr("error: line 1 is not valid\n");

        return 4;
    }

    v_num = mx_atoi(line);
    mx_strdel(&line);
    line = NULL;

    if (v_num == 0) {
        mx_printerr("error: invalid number of islands\n");

        return 6;
    }

    // allocate memory for an array of vertices:
    vertices = (char **)malloc(sizeof(char *) * (v_num + 1));

    for (int i = 0; i <= v_num; i++) {
        vertices[i] = NULL;
    }

    // allocate memory for an adjacency list:
    graph = (a_list **)malloc(sizeof(a_list *) * v_num);

    for (int i = 0; i < v_num; i++) {
        graph[i] = NULL;
    }

    // read data from file:
    for (int lines = 2; (br = mx_read_line(&line, buffer_size, '\n', fd)) >= 0;
                                                                     lines++) {
        char *temp = NULL;
        char **splitted = NULL;
        int w = 0;

        if (!mx_is_valid_line(line)) {
            mx_printerr("error: line ");
            mx_printint(lines);
            mx_printerr(" is not valid\n");

            return 5;
        }

        temp = mx_replace_substr(line, "-", ",");
        splitted = mx_strsplit(temp, ',');

        // add edges and vertices to source list:
        w = mx_atoi(splitted[2]);

        if (!mx_is_valid_num(splitted[2]) || w == 0) {
            mx_printerr("error: line ");
            mx_printint(lines);
            mx_printerr(", invalid distance between islands\n");

            return 7;
        }

        // avoid full duplicates (make sure to do it - ?):
        if (!mx_e_seek_duplicate(e_head, w, splitted[0], splitted[1])) {
            mx_e_push_back(&e_head, w, splitted[0], splitted[1]);
        }

        mx_del_strarr(&splitted);
        mx_strdel(&temp);
        mx_strdel(&line);
        line = NULL;
    }
    close(fd);
    mx_strdel(&line);
    line = NULL;

    // make array of vertices:
    mx_make_vertices_arr(e_head, vertices, v_num);

    // construct graph (adjacency list):
    mx_construct_graph(&graph, e_head, vertices, v_num);
    //mx_print_graph (graph, v_num);

    // print the shortest paths from each vertex to all others:
    mx_print_all_routes(&graph, vertices, v_num);

    // delete source list:
    mx_e_delete_list(&e_head);

    // delete vertices array:
    mx_del_strarr(&vertices);

    // delete graph:
    mx_delete_graph(&graph, v_num);

    //system("leaks pathfinder");
    return 0;
}
