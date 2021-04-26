NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAG = -L mlx -lmlx -framework OpenGL -framework AppKit

MLXFILE = libmlx.dylib

RM = rm -f

SRCS =	./libft/ft_memset.c\
		./read_info/util_read_info.c\
		./gnl/get_next_line.c\
		./gnl/get_next_line_utils.c\
		./cub3d.c\
		./libft/ft_atoi.c\
		./read_info/read_info.c\
		./map/read_map.c \
	 	./map/check_map.c\
		./map/util_map.c\
		./casting/wall.c\
		./casting/wall2.c\
		./casting/floor.c\
		./casting/sprite.c \
	 	./casting/sprite2.c\
		./libft/ft_strcmp.c\
		./bmp.c\
		./read_info/set.c\
		./read_info/key.c\
		./read_info/key2.c\
		./libft/ft_flip.c\

$(NAME) :
	make all -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(MLXFLAG) $(MLXFILE) $(SRCS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft/
clean :
	$(RM) $(NAME)
	make clean -C libft/

re : fclean all


# all : 
# 	gcc -Wall -Wextra -Werror libft/ft_memset.c util/get_next_line.c util/get_next_line_utils.c cub3d.c ./libft/ft_aoti.c
# a :
# 	 gcc -o cub3d -L ./mlx -lmlx -framework OpenGL -framework AppKit libft/ft_memset.c ./read_info/util_read_info.c \ 
# 	 gnl/get_next_line.c gnl/get_next_line_utils.c cub3d.c ./libft/ft_atoi.c ./read_info/read_info.c ./map/read_map.c \
# 	 ./map/check_map.c ./map/util_map.c ./map/move_map.c ./casting/wall.c ./casting/wall2.c ./casting/floor.c ./casting/sprite.c \
# 	 ./casting/sprite2.c ./libft/ft_strcmp.c ./bmp.c ./read_info/set.c ./read_info/key.c ./read_info/key2.c ./libft/ft_flip.c libmlx.dylib
# 	./cub3d
