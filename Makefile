NAME= fillit

SRC= ./src/*.c
OBJ= *.o

CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I libft/

$(NAME):
		make -C ./libft/
		$(CC) -c $(CFLAGS) $(SRC) $(LIBINC)
		$(CC) -o $(NAME) $(OBJ) $(LIBFT)

all: $(NAME)

clean:
		/bin/rm -rf *.o
		/bin/rm -rf ./libft/*.o

fclean: clean
		/bin/rm -rf $(NAME)
		/bin/rm -rf ./libft/libft.a

re: fclean all