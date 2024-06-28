CC = g++
CPPFLAGS = -I include -lsfml-graphics -lsfml-window -lsfml-system
WFLAGS = -Wall -Wextra

SRC = main.cpp \
	src/Gates.cpp

OBJ = $(SRC:.cpp=.o)
NAME = CircuitManager

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(WFLAGS) $(CPPFLAGS) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
