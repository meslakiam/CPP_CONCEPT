NAME = a.out

CXX = c++

CXXFLAGS =  -std=c++98


SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGES) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

.SECONDARY : $(OBJ)