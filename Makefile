NAME		=	cub3d
CC			=	gcc
CFLAGS		=	-g -Wall -Werror -Wextra #-fsanitize=address
LFLAGS		=	-Lget_next_line -Llibft -Lminilibx -lft -lmlx -framework OpenGL -framework AppKit
SOURCES		=	main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				srcs/control/key.c srcs/control/destroy.c srcs/control/rotate.c srcs/control/move.c srcs/parsing/map.c \
				srcs/render/dda_algoritm.c srcs/render/render.c srcs/render/draw_line.c srcs/render/image.c srcs/render/textures.c \
				srcs/parsing/get_map_data.c srcs/parsing/create_map.c srcs/parsing/get_map_size.c srcs/parsing/get_rgb_check.c \
				srcs/parsing/get_metadata.c srcs/parsing/verify_enclosed_with_walls.c safe_alloc/aborter.c safe_alloc/allocator.c srcs/parsing/get_metadata_value.c\

OBJ			=	$(SOURCES:%.c=%.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	make -C libft
	make -C minilibx
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)
	make -C libft clean
	make -C minilibx clean

fclean : clean
	rm	-f $(NAME) minilibx/libmlx.a libft/libft.a

re		:	fclean all
