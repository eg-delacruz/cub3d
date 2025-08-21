NAME=cub3D

MAKEFLAGS += --no-print-directory

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIB_DIR = ./lib
OBJ_DIR = ./objs
SRC_DIR = ./src
LIBFT_DIR = $(LIB_DIR)/libft
GNL_DIR = $(LIB_DIR)/gnl
MLX42_DIR = $(LIB_DIR)/MLX42

MLX_GITHUB = https://github.com/codam-coding-college/MLX42.git
MLX42 = $(MLX42_DIR)/build/libmlx42.a

LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/gnl.a

INCLUDES = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX42_DIR)/include -I./inc
LIBSFLAGS = -lm -L$(LIBFT_DIR) -lft -ldl -pthread -lglfw


SRC = main.c \
	/parse/parse.c \
	/parse/check_input_file.c \
	/parse/file_parse.c \
	/parse/map_parse.c \
	/parse/map_parse_2.c \
	/parse/parse_utils.c \
	/parse/parse_utils_2.c \
	/parse/floodfill.c \
	/parse/textures.c \
	/parse/colors.c \
	init_program_struct.c \
	free.c \
	error.c \
	/game/raycasting.c \
	/game/hooks.c \
	/game/color.c \
	/game/draw.c \
	/game/utils.c \
	/player/movement.c \
	/player/utils.c \
	/utils/vector.c \
	/game/ray.c \
	/game/ray_utils.c \
	/game/wall.c

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Colors
RST = \033[0m
GRAY = \033[38;5;244m
CYAN = \033[38;5;45m
ORANGE1 = \033[38;5;196m
ORANGE2 = \033[38;5;202m
ORANGE3 = \033[38;5;208m
YELLOW1 = \033[38;5;214m
YELLOW2 = \033[38;5;220m

# TODO: check if MLX already exists to avoid clonning it when doing make re
all: header libmlx $(NAME)

header:
	@echo ""
	@echo "${ORANGE1}  ██████ ██    ██ ██████  ██████  ██████  ${RST}"
	@echo "${ORANGE2} ██      ██    ██ ██   ██      ██ ██   ██ ${RST}"
	@echo "${ORANGE3} ██      ██    ██ ██████   █████  ██   ██ ${RST}"
	@echo "${YELLOW1} ██      ██    ██ ██   ██      ██ ██   ██ ${RST}"
	@echo "${YELLOW2}  ██████  ██████  ██████  ██████  ██████  ${RST}"
	@echo ""
	@echo -n "${GRAY} Authors: ${RST}"
	@echo -n "Jean Tivan ${CYAN} j-tivanr ${RST}"
	@echo -n "${GRAY}& ${RST}"
	@echo "Gerardo de la Cruz ${CYAN} erde-la- ${RST}"
	@echo "${GRAY} From: ${RST}    42 Madrid\n"

$(MLX42):
	@git clone $(MLX_GITHUB) $(MLX42_DIR)
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build -j4

$(NAME): $(LIBFT) $(GNL) libmlx $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT) $(GNL) $(MLX42) $(LIBSFLAGS)
	@echo "\n✅ DONE ./$(NAME) created!"

libmlx: $(MLX42)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@printf "🔧 $(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(RST)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(GNL):
	@make -C $(GNL_DIR) all

# Testing
exe: all
	@echo "$(BLUE_UNDER)Executing $(NAME)...$(RST)"
	@./$(NAME) $(ARGS)
	@echo "$(GREEN)Program executed"
	@echo "$(BLUE_UNDER)Removing $(NAME)...$(RST)"
	@rm -rf $(NAME)

valgrind: libmlx $(NAME)
	@echo "$(BLUE_UNDER)Compiling...$(RST)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT) $(GNL) $(MLX42) $(LIBSFLAGS)
	@echo "$(BLUE_UNDER)Executing with Valgrind...$(RST)"
	@valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes ./$(NAME) $(ARGS)
	@echo "$(GREEN)Valgrind execution completed"
	@echo "$(BLUE_UNDER)Removing $(NAME)...$(RST)"
	@rm -rf $(NAME) $(OBJFILES)

clean:
	@printf "🧼 Cleaning .o files! 🫧\n"
	# TODO: uncomment this
# 	# @rm -rfd $(MLX42_DIR)/build
	@rm -rfd $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	# TODO: uncomment this
# 	# @echo "rm -rfd $(MLX42_DIR)"
# 	@rm -rfd ${MLX42_DIR}

test:
	@echo "$(LIB_DIR)"

re: fclean all

.PHONY: all clean fclean re exe valgrind test
