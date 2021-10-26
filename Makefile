CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME = fractol

DEPS = fractol.h

SOURCE =	main.c	utils.c		\
			fract-ol.c hooks.c	\
			zoom.c

OBJ = ${SOURCE:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	gcc $(CFLAGS) -O3 -Lminilibx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)


clean :
	$(RM) $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus