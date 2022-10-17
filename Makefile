# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:09:02 by jbarette          #+#    #+#              #
#    Updated: 2022/10/17 16:32:37 by jbarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3d

SRC_DIR 	= 	srcs/
INC_DIR 	= 	includes/

SRC 		=	main.c \
				parsing.c \
				init.c \
				save_texture.c \

SRCS 		= 	$(addprefix ${SRC_DIR}, ${SRC})
SRCS_ALL 	= 	${SRCS}

OBJS 		= 	$(SRCS:.c=.o)

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIB_RDL 	= 	./libft/libft.a

%.o: %.c
		${CC} $(CFLAGS) -I $(INC_DIR) -Imlx -c $< -o $@

$(NAME): $(OBJS)
		make -C ./libft
		make -C ./mlx
		mv ./mlx/libmlx.dylib ../cub3d
		${CC} $(OBJS) ${LIB_RDL} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:
		$(MAKE) -j $(NAME)

clean:
		make -C ./libft clean
		make -C ./mlx clean
		rm -rf $(OBJS)

fclean:	clean
		make -C ./libft fclean
		rm -f libmlx.dylib
		rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re