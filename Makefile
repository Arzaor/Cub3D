# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeremybarette <jeremybarette@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:09:02 by jbarette          #+#    #+#              #
#    Updated: 2022/12/28 12:03:00 by jeremybaret      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3d

SRC_DIR 	= 	srcs/
INC_DIR 	= 	includes/

SRC 		=	main.c \
				parsing.c \
				init.c \
				save_texture.c \
				save_color.c \
				exit.c \
				utils.c \
				read_file.c \
				parser_map.c \

SRCS 		= 	$(addprefix ${SRC_DIR}, ${SRC})
SRCS_ALL 	= 	${SRCS}

OBJS 		= 	$(SRCS:.c=.o)

CC			= 	gcc
CFLAGS		=	#-Wall -Wextra -Werror

LIB_RDL 	= 	./libft/libft.a

%.o: %.c
		${CC} $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
		make -C ./libft
		${CC} $(OBJS) ${LIB_RDL} -o $(NAME)

all:
		$(MAKE) -j $(NAME)

clean:
		make -C ./libft clean
		rm -rf $(OBJS)

fclean:	clean
		make -C ./libft fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re