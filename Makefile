# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 16:53:06 by ezhou             #+#    #+#              #
#    Updated: 2024/01/23 15:27:01 by ezhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

USER = ezhou

LIBFT = Libft/
RM = rm -f
INCLUDE = Include/

MLX = MLX42/
MLX_DEPENDENCIES = -framework Cocoa -framework OpenGL -framework IOKit
MLX_FLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

CC = gcc 
CFLAGS = -g -Wall -Wextra -Werror -Wunreachable-code -Ofast

NAME = So_long
SRC = ft_error_utils.c ft_error_check.c So_long.c textures_images.c key_hook.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(MLX)
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -L$(LIBFT) -lft -L$(MLX) -lmlx42 $(MLX_DEPENDENCIES) $(MLX_FLAGS) -o $(NAME) $(OBJ) 
	@echo "$(COLOUR_GREEN)(•̀ᴗ•́)و $(NAME) generado!$(COLOUR_END)"

%.o : %.c
	@$(CC) -I./$(INCLUDE) -c -o $@ $<
	@echo "$(COLOUR_BLUE)(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compilando archivos .c$(COLOUR_END)" 

clean:
	@$(RM) $(OBJ)
	@echo "$(COLOUR_RED)¯\_(ツ)_/¯ Objectos removidos!$(COLOUR_RED)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOUR_RED)(╯°□°）╯︵ ┻━┻ $(NAME) removido!$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re 