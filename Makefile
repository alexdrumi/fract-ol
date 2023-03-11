
NAME		=	fractol
MLX_DIR		= 	./minilibx
SRC_DIR		=	src
OBJ_DIR		=	obj
SRCS		=	$(wildcard $(SRC_DIR)/*.c)
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-Iinclude -MMD -MP
LDLIBS		=	-lm
RM			=	@rm -rf
MLX_F		=	libmlx.dylib -framework OpenGL -framework AppKit

.PHONY:			all fclean clean re

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "\n"
				@make -s -C $(MLX_DIR)
				@mv $(MLX_DIR)/libmlx.dylib .
				@$(CC) $^ $(LDLIBS) $(MLX_F) -o $@
				@$(CC) $(CPPFLAGS) $(CFLAGS) $(MLX_F) $(OBJS) -o $(NAME)
				@echo "\nFinished Building Fractol\n"
				@echo "You can now run ./fractol [name of chosen set eg. mandelbrot or julia]\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ 
				@printf "Building fractol objects...\n"
clean:
				@$(RM) $(OBJ_DIR)
				@make clean -C $(MLX_DIR)
				@echo "Object files and mlx files are cleaned"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) libmlx.dylib
				@echo "Executable and libmlx.dylib are cleaned"

re:				fclean all

-include $(OBJ:.o=.d)





%.o: %.c
	$(CC) $(CPPFLAGS) $< -c -I inc
