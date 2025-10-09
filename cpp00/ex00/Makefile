NAME= megaphone
CXX= c++
FLAGS= -Wall -Wextra -Werror -std=c++98 -g
SRC= Megaphone.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all