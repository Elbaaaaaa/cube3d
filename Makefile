NAME = cube3d
LIBFT = libft/libft.a

INC = ./minilibx-linux
LIBFT_DIR = libft

UNAME := $(shell uname)

CC = cc
CFLAGS = -I$(INC) -I$(LIBFT_DIR)/include -O3 -g

SRC = ./src/main.c \
	./src/mlx.c \
	./src/hook.c \
	./src/parsing/parsing.c \
	./src/parsing/parsing_img.c \
	./src/parsing/parsing_rgb.c \
	./src/parsing/parsing_map.c \
	./src/error.c \
	./src/struct.c \
	./src/parsing/check_map.c

	OBJ = $(SRC:%.c=%.o)

LFLAGS = -Wall -Wextra -Werror -g -L$(INC) -lmlx -lXext -lX11 -lm -L$(LIBFT_DIR) -lft

ifeq ($(UNAME), Linux)
	LFLAGS += -lbsd
endif

# Règles de compilation
all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) *~ core *.core
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
