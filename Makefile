# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 19:18:04 by ajazbuti          #+#    #+#              #
#    Updated: 2022/03/08 19:27:28 by ajazbuti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c ft_parse_map.c ft_init.c utils.c movement.c

SRC_B = so_long_bonus.c ft_check_validity_bonus.c ft_init_bonus.c utils_bonus.c\
		movement_bonus.c ft_enemy_bonus.c

CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = sources/

INC = -I./libft/includes -I./includes -I./mlx

LFT_DIR = ./libft/

LFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

LIBS = -L./mlx -lmlx -L./libft -lft

all: ${NAME}

bonus: ${MLX} ${LFT} ${SRC_DIR}/*_bonus.c
	${CC} ${CFLAGS} ${LIBS} ${INC} -framework OpenGL -framework Appkit \
		${addprefix ${SRC_DIR}, ${SRC_B}} -o ${NAME}

${LFT}: ${LFT_DIR}/sources/*.c
	make -C ${LFT_DIR}

${MLX}:
	make -C ./mlx

${NAME}: ${MLX} ${LFT} ${addprefix ${SRC_DIR}, ${SRC}}
	${CC} ${CFLAGS} ${LIBS} ${INC} -framework OpenGL -framework Appkit \
		${addprefix ${SRC_DIR}, ${SRC}} -o ${NAME}

clean:
	${MAKE} -C ${LFT_DIR} clean
	${RM} so_long.dSYM

fclean:
	${RM} ${NAME}
	${MAKE} -C ${LFT_DIR} fclean
	make -C ./mlx clean

re: fclean all

.PHONY: all clean fclean re bonus
