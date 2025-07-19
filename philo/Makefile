CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRC = main.c utils.c parsing.c init.c dinner.c getters_setters.c synchro_utils.c utils2.c write.c monitor.c
	
all: $(NAME)

$(NAME):$(SRC)
	@cc $(SRC) $(CFLAGS) -o $(NAME) 

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
