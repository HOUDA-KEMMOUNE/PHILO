
CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRC = main.c utils.c parsing.c

# OBJ = $(SRC:.c=.o)
	
all: $(NAME)

# $(NAME): $(OBJ)
# 	@ar rcs $@ $(OBJ)

# %.c: $(NAME)
# 	@cc $(CFLAGS) 

$(NAME):$(SRC)
	@cc $(SRC) $(CFLAGS) -o $(NAME) 

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
