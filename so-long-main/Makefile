
NAME := so_long
SRC_DIR := src
BUILD_DIR := .build
DEPS_DIR := .deps

INC_DIR = inc
INC := $(INC_DIR)/so_long.h

MLX_DIR = minilibx-linux
MLX_INC = $(MLX_DIR)/mlx.h

IFLAGS = -I $(INC_DIR) \
		 -I $(MLX_DIR)

SO_LONG =	$(SRC_DIR)/so_long.c \
			$(SRC_DIR)/map_test.c \
			$(SRC_DIR)/map_good.c \
			$(SRC_DIR)/map_edge.c \
			$(SRC_DIR)/map_init.c \
			$(SRC_DIR)/init_mlx_var.c \
			$(SRC_DIR)/mlx_error.c \
			$(SRC_DIR)/mlx_keys.c \
			$(SRC_DIR)/map_size.c \
			$(SRC_DIR)/mlx_free.c

SRC := $(SO_LONG)

OBJS    := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEPS    := $(patsubst %.o, %.d,$(OBJS))

LIBS       				:= libft 

LIBS_TARGET 			:= libft/libft.a 

DIR_MLX		:=	minilibx_linux

MLX_TARGET :=			minilibx-linux/libmlx_Linux.a 

CC := cc -g3
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -MD -MP
LDFLAGS := $(addprefix -L,$(dir $(LIBS_TARGET))) \
			 $(addprefix -L,$(dir $(MLX_TARGET)))

LDLIBS := -lmlx_Linux -lft -lX11 -lXext  -lm 

RM := rm -f

all: $(NAME) 

FORCE:


$(LIBS_TARGET): FORCE
	$(MAKE) -C $(LIBS) all

$(MLX_TARGET): FORCE
	$(MAKE) -C $(MLX_DIR) all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(LIBS_TARGET) $(MLX_TARGET)
		mkdir -p $(@D)
		$(CC) $(CFLAGS) $(CPPFLAGS) $(IFLAGS) -c $< -o $@ 

$(NAME): $(OBJS) $(LIBS_TARGET) $(MLX_TARGET)
			$(CC) $(LDFLAGS) $(OBJS)  $(LDLIBS) -o $(NAME) 


-include $(DEPS)

# **************************************************************************** #

clean:
	$(MAKE) -C $(LIBS) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR)

# **************************************************************************** #

fclean: clean
	$(RM) -r $(NAME)

# **************************************************************************** #

re: fclean all

# **************************************************************************** # # .PHONY #

.PHONY: all clean fclean re

# *****************************