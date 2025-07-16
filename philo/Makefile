CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRC = main.c utils.c parsing.c init_philo.c 
	
all: $(NAME)

$(NAME):$(SRC)
	@cc $(SRC) $(CFLAGS) -o $(NAME) 

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
