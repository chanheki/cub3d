# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 16:15:16 by sechung           #+#    #+#              #
#    Updated: 2023/05/29 16:16:14 by chanheki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

# ----- MANDATORY ----- #
SRC_FILES	=	src/main.c

SRC_FILES	+=	src/utils/error.c \
				src/utils/program_validator.c\
				src/utils/gnl/get_next_line_utils.c\
				src/utils/gnl/get_next_line.c

SRC_FILES	+=	src/executor/executor.c \
				src/executor/init/init_game_data.c \
				src/executor/init/init_texture.c \
				src/executor/game/game.c \
				src/executor/game/raycasting/raycasting.c \
				src/executor/game/raycasting/dda_init.c \
				src/executor/game/raycasting/set_wall_buffer.c \
				src/executor/react/finish_game.c \
				src/executor/react/press_events.c \
				src/executor/react/release_events.c \
				src/executor/game/actions/actions.c \
				src/executor/game/actions/mv_actions.c \
				src/executor/game/actions/rotate_actions.c

SRC_FILES	+=	src/parser/checker.c \
				src/parser/dfs.c \
				src/parser/insert.c \
				src/parser/parser.c \
				src/parser/rgb.c \
				src/parser/utils.c \
				src/parser/validator.c 

# ----- BONUS ----- #
BONUS_FILES	=	src_bonus/main_bonus.c

BONUS_FILES	+=	src_bonus/utils/error_bonus.c \
				src_bonus/utils/program_validator_bonus.c\
				src_bonus/utils/gnl/get_next_line_utils_bonus.c\
				src_bonus/utils/gnl/get_next_line_bonus.c

BONUS_FILES	+=	src_bonus/executor/executor_bonus.c \
				src_bonus/executor/init/init_game_data_bonus.c \
				src_bonus/executor/init/init_texture_bonus.c \
				src_bonus/executor/game/game_bonus.c \
				src_bonus/executor/game/raycasting/raycasting_bonus.c \
				src_bonus/executor/game/raycasting/dda_init_bonus.c \
				src_bonus/executor/game/raycasting/set_wall_buffer_bonus.c \
				src_bonus/executor/react/finish_game_bonus.c \
				src_bonus/executor/react/press_events_bonus.c \
				src_bonus/executor/react/release_events_bonus.c \
				src_bonus/executor/game/actions/actions_bonus.c \
				src_bonus/executor/game/actions/mv_actions_bonus.c \
				src_bonus/executor/game/actions/rotate_actions_bonus.c
				
BONUS_FILES	+=	src_bonus/parser/checker_bonus.c \
				src_bonus/parser/dfs_bonus.c \
				src_bonus/parser/insert_bonus.c \
				src_bonus/parser/parser_bonus.c \
				src_bonus/parser/rgb_bonus.c \
				src_bonus/parser/utils_bonus.c \
				src_bonus/parser/validator_bonus.c 

OBJ_DIR		=	obj/

MLX			=	mlx/libmlx.a

MLX_DIR		=	mlx

MLX_FLAGS	=	-framework OpenGL -framework Appkit

LIBFT 		= 	libft/libft.a

LIB_DIR		=	libft

INCS		=	include

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

ALL_SOURCES = $(SRC_FILES) $(BONUS_FILES)

OBJECTS1 = $(SRC_FILES:.c=.o)
OBJECTS2 = $(BONUS_FILES:.c=.o)
ALL_OBJECTS = $(SRC_FILES) $(BONUS_FILES)

define OBJECTS_GOAL
$(addprefix $(OBJ_DIR)/, $(call $(if $(filter bonus, $(MAKECMDGOALS)), OBJECTS2, OBJECTS1))) 
endef

define REACT
$(if $(filter bonus, $(MAKECMDGOALS)), bonus, all)
endef

.PHONY : all bonus clean fclean re

all: $(NAME)

$(NAME) : $(OBJECTS_GOAL) $(MLX) $(LIBFT)
	@echo "$(CYAN)Compiling...        [$(NAME)]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS_GOAL) -o $(NAME) -L$(MLX_DIR) -lmlx $(MLX_FLAGS) $(LIBFT)
	@echo "$(GREEN)Make success!       [$(NAME)]$(RESET)"

	@printf "\n"
	@printf "$(CYAN)              _      _____ ______ \n$(RESET)"
	@printf "$(CYAN)             | |    |____ ||  _  \\n$(RESET)"
	@printf "$(CYAN)  ___  _   _ | |__      / /| | | |\n$(RESET)"
	@printf "$(CYAN) / __|| | | || '_ \     \ \| | | |\n$(RESET)"
	@printf "$(CYAN)| (__ | |_| || |_) |.___/ /| |/ / \n$(RESET)"
	@printf "$(CYAN) \___| \__,_||_.__/ \____/ |___/  \n$(RESET)"
	@printf "\n"


$(OBJ_DIR)/%.o: %.c
	@#mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(dir $^)
	@echo "$(CYAN)Compiling...        [$@]$(RESET)"
	@printf "$(UP)$(CUT)"
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(INCS)


$(MLX) :
	@echo "$(CYAN)Compiling...        [ mlx ]$(RESET)"
	@make -s -C $(MLX_DIR) CFLAGS="-Wno-deprecated-declarations"
	@printf "$(UP)$(CUT)"


$(LIBFT) :
	@echo "$(CYAN)Compiling...        [libft]$(RESET)"
	@make -s -C $(LIB_DIR)

bonus : $(NAME)

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


re : fclean
	@make $(react)
