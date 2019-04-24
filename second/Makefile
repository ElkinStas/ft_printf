NAME = libftprintf.a

SRC = ./libft/*.c
OBJS = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I /libft/libft.h
	ar rc $(NAME) $(OBJS)
		
clean:
	rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
