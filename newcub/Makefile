
NAME = cub3D

DIR = .
FT = $(DIR)/libft
MLX = $(DIR)/minilibx-linux
INCS_DIR = $(DIR)/incs
OBJS_DIR =$(DIR)/objs

MAIN = $(DIR)/main.c

SRCS = \
	$(addprefix $(DIR)/srcs/, \
	parse.c \
	gnl.c \
	utils.c \
	)

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g
IDFLAGS = -I$(INCS_DIR)
LDFLAGS = -L$(FT)
IDFLAGS += -I$(FT)
LDFLAGS += -L$(MLX)
IDFLAGS += -I$(MLX)
LIBS = -lft -lmlx -lm -lXext -lX11

.PHONY: all clean fclean re

all: $(FT) $(MLX) $(NAME)

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(IDFLAGS) $^ -o $@ $(LIBS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(FT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(FT)
$(FT):
	@make -C $@ all

.PHONY: $(MLX)


