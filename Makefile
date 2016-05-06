SRCS = node.c node.h tree.c tree.h main.c treeInterface.c treeInterface.h

CC = gcc

FLAGS = -Wall

NAME = tree_test

all: $(SRCS)
	$(CC) $(SRCS) $(FLAGS) -o $(NAME)
