NAME= humans
CXX= c++
FLAGS= -Wall -Wextra -Werror -std=c++98
SRC= HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all