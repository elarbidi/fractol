# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 17:12:07 by aelarbid          #+#    #+#              #
#    Updated: 2022/12/22 00:10:56 by aelarbid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
NAME = fractol
FLAGS= -Wall -Werror -Wextra
RM = rm
FILES= ./src/main.c\
	./src/init.c\
	./src/printPx.c\
	./src/mandelbrot/mandlbrotSet.c \
	./src/mandelbrot/mZoom.c \
	./src/julia/juliaSet.c\
	./src/julia/jZoom.c
OBJ= $(FILES:%.c=%.o)
MLX= -lmlx -framework OpenGL -framework AppKit
MAKE= make
LIBFT= ./libft/libft.a

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)	

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean:
	$(MAKE) clean -C  ./libft
	$(RM) $(OBJ)

fclean:
	@$(MAKE) fclean -C  ./libft
	@$(RM) $(OBJ) $(NAME)

re: fclean all