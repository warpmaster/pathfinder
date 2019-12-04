NAME = pathfinder

LIBAR = ./libmx/libmx.a

DIROBJ = obj

DIRSRC = src

DIRINC = inc

LIB = ./libmx

SRC = src/pathfinder.c \
	src/mx_e_create_node.c \
	src/mx_e_push_front.c \
	src/mx_e_push_back.c \
	src/mx_e_pop_front.c \
	src/mx_e_pop_back.c \
	src/mx_e_seek_duplicate.c \
	src/mx_a_seek_node.c \
	src/mx_e_print_list.c \
	src/mx_e_delete_list.c \
	src/mx_a_create_node.c \
	src/mx_a_push_front.c \
	src/mx_a_push_back.c \
	src/mx_a_pop_front.c \
	src/mx_a_pop_back.c \
	src/mx_a_seek_min_weight.c \
	src/mx_a_print_list.c \
	src/mx_a_delete_list.c \
	src/mx_a_delete_longer_weights.c \
	src/mx_a_sort_list.c \
	src/mx_is_valid_num.c \
	src/mx_is_valid_line.c \
	src/mx_search_str.c \
	src/mx_make_vertices_arr.c \
	src/mx_construct_graph.c \
	src/mx_pathfinder.c \
	src/mx_print_graph.c \
	src/mx_delete_graph.c \
	src/mx_route_maker.c \
	src/mx_print_all_routes.c \
	src/mx_print_route.c \

OUT = pathfinder.o \
	mx_e_create_node.o \
	mx_e_push_front.o \
	mx_e_push_back.o \
	mx_e_pop_front.o \
	mx_e_pop_back.o \
	mx_e_seek_duplicate.o \
	mx_a_seek_node.o \
	mx_e_print_list.o \
	mx_e_delete_list.o \
	mx_a_create_node.o \
	mx_a_push_front.o \
	mx_a_push_back.o \
	mx_a_pop_front.o \
	mx_a_pop_back.o \
	mx_a_seek_min_weight.o \
	mx_a_print_list.o \
	mx_a_delete_list.o \
	mx_a_delete_longer_weights.o \
	mx_a_sort_list.o \
	mx_is_valid_num.o \
	mx_is_valid_line.o \
	mx_search_str.o \
	mx_make_vertices_arr.o \
	mx_construct_graph.o \
	mx_pathfinder.o \
	mx_print_graph.o \
	mx_delete_graph.o \
	mx_route_maker.o \
	mx_print_all_routes.o \
	mx_print_route.o \

INC = inc/pathfinder.h

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror #-g -fsanitize=address

all: install clean

install:
	@cd $(LIB) && make install
	@mkdir $(DIROBJ)
	@clang $(CFLAGS) $(SRC) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@clang $(CFLAGS) $(SRC) $(LIBAR) -o $(NAME) -I $(INC)
	@make clean

uninstall: clean
	@rm -rf $(NAME)
	@cd $(LIB) && make uninstall

clean:
	@rm -rf $(DIROBJ)
	@cd $(LIB) && make clean

reinstall: uninstall all
