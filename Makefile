NAME = navigator
CC = c++
HEADERS =	BreadthFirstSearch.h \
			Graph.h \
			SimpleNavigator.h
OBJ = main.cpp
SRC_DIR = ./
OBJ_DIR = obj/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(FLAG) $(HEADERS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all