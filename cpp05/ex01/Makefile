NAME= form
CXX= c++
FLAGS= -Wall -Wextra -Werror -std=c++98 -g
SRC= Form.cpp Bureaucrat.cpp main.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all