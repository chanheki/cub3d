# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 16:15:16 by sechung           #+#    #+#              #
#    Updated: 2023/05/29 15:27:28 by chanheki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRC_FILES	=	main.c

SRC_FILES	+=	/utils/error.c \
				/utils/program_validator.c\
				/utils/gnl/get_next_line_utils.c\
				/utils/gnl/get_next_line.c

SRC_FILES	+=	/executor/executor.c \
				/executor/init/init_game_data.c \
				/executor/init/init_texture.c \
				/executor/game/game.c \
				/executor/game/raycasting/raycasting.c \
				/executor/game/raycasting/dda_init.c \
				/executor/game/raycasting/set_wall_buffer.c \
				/executor/react/finish_game.c \
				/executor/react/press_events.c \
				/executor/react/release_events.c \
				/executor/game/actions/actions.c \
				/executor/game/actions/mv_actions.c \
				/executor/game/actions/rotate_actions.c

SRC_FILES	+=	/parser/checker.c \
				/parser/dfs.c \
				/parser/insert.c \
				/parser/parser.c \
				/parser/rgb.c \
				/parser/utils.c \
				/parser/validator.c 

SRC_DIR		=	src/

SCRS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		=	obj/

OBJS		=	$(addprefix $(OBJ_DIR), $(patsubst %.c,%.o,$(SRC_FILES)))

MLX			=	mlx/libmlx.a

MLX_DIR		=	mlx

MLX_FLAGS	=	-framework OpenGL -framework Appkit

LIBFT 		= 	libft/libft.a

LIB_DIR		=	libft

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

RESET		=	\033[0m
BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
UP			=	\033[A
CUT			=	\033[K

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	@echo "$(CYAN)Compiling...        [$(NAME)]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_DIR) -lmlx $(MLX_FLAGS) $(LIBFT)
	@echo "$(GREEN)Make success!       [$(NAME)]$(RESET)"

	@printf "\n"
	@printf "$(CYAN)              _      _____ ______ \n$(RESET)"
	@printf "$(CYAN)             | |    |____ ||  _  \\n$(RESET)"
	@printf "$(CYAN)  ___  _   _ | |__      / /| | | |\n$(RESET)"
	@printf "$(CYAN) / __|| | | || '_ \     \ \| | | |\n$(RESET)"
	@printf "$(CYAN)| (__ | |_| || |_) |.___/ /| |/ / \n$(RESET)"
	@printf "$(CYAN) \___| \__,_||_.__/ \____/ |___/  \n$(RESET)"
	@printf "\n"


$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling...        [$@]$(RESET)"
	@printf "$(UP)$(CUT)"
	@$(CC) $(CFLAGS) -I include -o $@ -c $<


$(MLX) :
	@echo "$(CYAN)Compiling...        [ mlx ]$(RESET)"
	@make -s -C $(MLX_DIR) CFLAGS="-Wno-deprecated-declarations"
	@printf "$(UP)$(CUT)"


$(LIBFT) :
	@echo "$(CYAN)Compiling...        [libft]$(RESET)"
	@make -s -C $(LIB_DIR)


clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(PURPLE)Delete all objects  [$(NAME)]$(RESET)"; else \
	echo "$(YELLOW)No object to remove [$(NAME)]$(RESET)"; \
	fi;
	@echo "$(PURPLE)Cleaning            [libft]$(RESET)";
	@make -s -C $(LIB_DIR) fclean;
	@echo "$(PURPLE)Cleaning            [ mlx ]$(RESET)";
	@make -s -C $(MLX_DIR) clean;


fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -rf $(NAME); \
	echo "$(PURPLE)Delete output file  [$(NAME)]$(RESET)"; else \
	echo "$(YELLOW)No output to remove [$(NAME)]$(RESET)"; \
	fi;


re:	fclean all


.PHONY:	all clean fclean re
