COMPILER = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = a.out

SRCS = $(wildcard *.cpp)
OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

MYLIB_DIR = testkit_lib
MYLIB = $(MYLIB_DIR)/testkit_lib.a

INCLUDES = $(wildcard *.hpp)

RM = rm -rf

.PHONY: all clean fclean re lib run

all: lib $(NAME)

lib:
	$(MAKE) -C $(MYLIB_DIR)

$(NAME): $(OBJS) $(MYLIB)
	$(COMPILER) $(FLAGS) -o $@ $(OBJS) $(MYLIB)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(MYLIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MYLIB_DIR) fclean

re: fclean all

run: all
	valgrind ./$(NAME)