# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gruocco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 16:46:15 by gruocco           #+#    #+#              #
#    Updated: 2018/01/19 16:46:16 by gruocco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fractol

CFLAGS = -Wall -Wextra -Werror -pthread

LIBS = libft/libft.a minilibx_macos/libmlx.a
LFLAGS = -framework OpenGL -framework AppKit

INC= -I ft_fdf.h

SRC_NAME = main.c \
		ft_checks.c \
		ft_keys.c	\
		ft_rgb_mappers.c \
		ft_fract_callers.c

OBJ_NAME= $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@make -C libft/
	@make -C minilibx_macos/
	@gcc $(LIBS) $(LFLAGS)  $^ -o $@

%.o: %.c
	@gcc  $(CFLAGS) $(INC) -c $<

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@/bin/rm -f $(OBJ_NAME)

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)


re: fclean all
