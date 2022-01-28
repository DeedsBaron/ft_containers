#-Wall -Wextra -Werror
NAME = func

CC = clang++
FLAGS = -std=c++98 -MMD -Wall -Wextra -Werror

DIR_S =	./
DIR_O =	./srcs/obj
DIR_BIN = ./srcs/bin
DIR_TESTS = ./srcs/tests
DIR_OUT = ./srcs/out

SOURCES	= main.cpp
TESTS_SOURCES = myvector.cpp stdvector.cpp mystack.cpp stdstack.cpp mymap.cpp stdmap.cpp myset.cpp stdset.cpp

SRCS = $(addprefix $(DIR_S)/,${SOURCES})
OBJS = $(addprefix $(DIR_O)/,${SOURCES:.cpp=.o})
TEST_SRCS = $(addprefix $(DIR_TESTS)/,${TESTS_SOURCES})
TEST_OBJS = $(addprefix $(DIR_O)/,${TESTS_SOURCES:.cpp=.o})

all: dir $(NAME)

dir:
	@echo "\033[0;32m"
	@if [ ! -d "srcs/obj" ]; then mkdir srcs/obj; fi
	@if [ ! -d "srcs/bin" ]; then mkdir srcs/bin; fi
	@if [ ! -d "srcs/out" ]; then mkdir srcs/out; fi


$(DIR_O)/%.o: $(DIR_TESTS)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@ -g

$(DIR_O)/%.o: $(DIR_S)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@ -g

$(NAME): $(TEST_OBJS) vec stack map set

test: $(OBJS)
	@echo "\033[0;35m"
	$(CC) $(FLAGS) $^ -o $@
	chmod 777 $@

set: dir
	$(CC) $(FLAGS) $(DIR_O)/myset.o -o $(DIR_BIN)/myset
	$(CC) $(FLAGS) $(DIR_O)/stdset.o -o $(DIR_BIN)/stdset
	./$(DIR_BIN)/myset > $(DIR_OUT)/myset.out
	./$(DIR_BIN)/stdset > $(DIR_OUT)/stdset.out
	open -a Terminal.app $(DIR_BIN)/stdset
	open -a Terminal.app $(DIR_BIN)/myset

map: dir
	$(CC) $(FLAGS) $(DIR_O)/mymap.o -o $(DIR_BIN)/mymap
	$(CC) $(FLAGS) $(DIR_O)/stdmap.o -o $(DIR_BIN)/stdmap
	./$(DIR_BIN)/mymap > $(DIR_OUT)/mymap.out
	./$(DIR_BIN)/stdmap > $(DIR_OUT)/stdmap.out
	open -a Terminal.app $(DIR_BIN)/stdmap
	open -a Terminal.app $(DIR_BIN)/mymap

vec: dir
	$(CC) $(FLAGS) $(DIR_O)/myvector.o -o $(DIR_BIN)/myvector
	$(CC) $(FLAGS) $(DIR_O)/stdvector.o -o $(DIR_BIN)/stdvector
	./$(DIR_BIN)/myvector > $(DIR_OUT)/myvector.out
	./$(DIR_BIN)/stdvector > $(DIR_OUT)/stdvector.out
	open -a Terminal.app $(DIR_BIN)/stdvector
	open -a Terminal.app $(DIR_BIN)/myvector

stack: dir
	$(CC) $(FLAGS) $(DIR_O)/mystack.o -o $(DIR_BIN)/mystack
	$(CC) $(FLAGS) $(DIR_O)/stdstack.o -o $(DIR_BIN)/stdstack
	./$(DIR_BIN)/mystack > $(DIR_OUT)/mystack.out
	./$(DIR_BIN)/stdstack > $(DIR_OUT)/stdstack.out
	open -a Terminal.app $(DIR_BIN)/stdstack
	open -a Terminal.app $(DIR_BIN)/mystack

diff_stack:
	diff $(DIR_OUT)/mystack.out $(DIR_OUT)/stdstack.out
diff_vec:
	diff $(DIR_OUT)/myvector.out $(DIR_OUT)/stdvector.out
diff_map:
	diff $(DIR_OUT)/mymap.out $(DIR_OUT)/stdmap.out
diff_set:
	diff $(DIR_OUT)/myset.out $(DIR_OUT)/stdset.out

clean:
	@echo "\033[0;33m"
	rm -rf $(DIR_O)
	rm -rf ./srcs/out
	rm -rf ./srcs/bin


fclean: clean
	@echo "\033[0;33m"
	rm -f $(NAME)

re: fclean all

.PHONY: all lib clean fclean re

-include $(TEST_OBJS:.o=.d)
-include $(OBJS:.o=.d)