SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = megaphone


all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
