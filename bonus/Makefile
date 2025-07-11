NAME	=	minirt

GNL		= 	gnl/get_next_line_utils.c gnl/get_next_line.c

PARSING =	parsing/handle_shapes.c parsing/handling.c \
			parsing/helper.c parsing/helper2.c \
			parsing/initialization.c parsing/insert.c \
			parsing/validation.c parsing/handle_helper.c \
			parsing/handling_light.c parsing/init_helper.c

UTILS	=	utils/atoi.c utils/errors.c \
			utils/frees.c utils/libft.c \
			utils/split.c utils/angle_calcul.c \
			utils/frees2.c

INTER	= 	intersections/cylinder.c intersections/plane.c \
			intersections/sphere.c intersections/cone.c \

CAM		=	camera/camera.c camera/create_window.c \
			camera/my_mlx_pixel_put.c camera/lighting.c \
			camera/lighting_helper.c camera/rgb_utils.c \
			camera/precamera.c camera/thread_fct.c \
			camera/copy.c camera/closing_window.c \
			camera/camera_helper.c

FONTS	=	fonts/font.c fonts/handle_letters.c \
			fonts/abcde.c fonts/fghij.c \
			fonts/klmno.c fonts/pqrst.c fonts/uvwxy.c \
			fonts/z0123.c fonts/45678.c fonts/9arrows.c

BUTTONS	=	buttons/buttons.c buttons/mouse_click.c \
			buttons/button_click.c \
			buttons/check_click.c buttons/menu_helper.c \
			buttons/mouse_click_helper.c buttons/obj_menu.c \
			buttons/new_shape.c buttons/button_click_helper.c \
			buttons/click_in.c buttons/make_buttons.c \
			buttons/add_shape.c buttons/shape_buttons.c

KEYS	=	keys/arrows.c keys/hjkl.c keys/key_press.c \
			keys/mod.c keys/wasd.c keys/zaxis.c \
			keys/rgb.c keys/rotate_helper.c

VECT	=	vector/vector.c vector/vector_ops.c

FEATURES=	features/display_gen.c

SRCS	=	main.c $(GNL) $(PARSING) $(UTILS) $(INTER) $(CAM) $(VECT) $(FONTS) $(BUTTONS) $(FEATURES) $(KEYS)
OBJS	=	${SRCS:.c=.o}
CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall -I. -I./minilibx-linux
MLX_FLAGS = -lmlx -lXext -lX11 -L./minilibx-linux -lm
MLX 	= minilibx-linux/libmlx_Linux.a

X_LEN    ?= 1920
Y_HEIGHT ?= 1080

CFLAGS += -DX_LEN=$(X_LEN) -DY_HEIGHT=$(Y_HEIGHT)

# Colors and style
END		:= \033[0m
WHITE	:= \033[1;37m
NC		:= \033[0m
RED		:= \033[0;31m
PINK	:= \033[1;35m
GREEN	:= \033[0;32m
BOLD	:= \033[1m
L_PURPLE:= \033[38;5;55m
YELLOW	:= \033[0;33m
BLUE	:= \033[34m
REPLACE := \033[9A\033[9K\033[A

# Rules
all:	${NAME} header

header:
	@for i in 1 2 3 4 5; do \
		sleep 0.5 ; \
		echo "$(L_PURPLE)"  ; \
		echo "  __  __              _   _                 ____      _____   " ; \
		echo "U|' \/ '|u   ___     | \ |\"|       ___   U |  _\"\ u  |_ \" _|  " ; \
		echo "\| |\/| |/  |_\"_|   <|  \| |>     |_\"_|   \| |_) |/    | |    " ; \
		echo " | |  | |    | |    U| |\  |u      | |     |  _ <     /| |\   " ; \
		echo " |_|  |_|  U/| |\u   |_| \_|     U/| |\u   |_| \_\   u |_| U  " ; \
		echo "<<,-,,-..-,_|___|_,-.||   "'\\'"\,-.-,_|___|_,-.//   "'\\'"\_  _// "'\\'"\_  " ; \
		echo " (./  \.)\_)-' '-(_/ (_\")  (_/ \_)-' '-(_/(__)  (__)(__) (__) " ; \
		echo "$(END)" ;	 \
		sleep 0.5 ; \
		echo "$(REPLACE)" ; \
		echo "$(GREEN)" ; \
		echo "  __  __              _   _                 ____      _____   " ; \
		echo "U|' \/ '|u   ___     | \ |\"|       ___   U |  _\"\ u  |_ \" _|  " ; \
		echo "\| |\/| |/  |_\"_|   <|  \| |>     |_\"_|   \| |_) |/  u\| |/U   " ; \
		echo " | |  | |  U\\| |/u  U| |\  |u    U\\| |/u   |  _ <      | |    " ; \
		echo " |_|  |_|    | |     |_| \_|       | |     |_| \_\     |_|    " ; \
		echo "<<,-,,-..-,_|___|_,-.||   "'\\'"\,-.-,_|___|_,-.//   "'\\'"\_  _// "'\\'"\_  " ; \
		echo " (./  \.)\_)-' '-(_/ (_\")  (_/ \_)-' '-(_/(__)  (__)(__) (__) " ; \
		echo "$(END)" ; \
		echo "$(REPLACE)" ; \
	done	
	@echo "$(L_PURPLE)"
	@echo "  __  __              _   _                 ____      _____   "
	@echo "U|' \/ '|u   ___     | \ |\"|       ___   U |  _\"\ u  |_ \" _|  "
	@echo "\| |\/| |/  |_\"_|   <|  \| |>     |_\"_|   \| |_) |/    | |    "
	@echo " | |  | |    | |    U| |\  |u      | |     |  _ <     /| |\   "
	@echo " |_|  |_|  U/| |\u   |_| \_|     U/| |\u   |_| \_\   u |_|U   "
	@echo "<<,-,,-..-,_|___|_,-.||   "'\\'"\,-.-,_|___|_,-.//   "'\\'"\_  _// "'\\'"\_  "
	@echo " (./  \.)\_)-' '-(_/ (_\")  (_/ \_)-' '-(_/(__)  (__)(__) (__) "
	@echo "$(END)"

${NAME}:	${OBJS} ${MLX}
	@echo -n "${BLUE}"
	${CC} ${CFLAGS} ${OBJS} -lm -o ${NAME} ${MLX_FLAGS}
	@echo -n "${END}"

%.o: %.c
	@echo -n "${BLUE}"
	${CC} ${CFLAGS} -c -o $@ $<
	@echo -n "${END}"

${MLX} :
		cd minilibx-linux && ./configure
		cd ..

clean:
	@echo -n "${RED}"
	rm -f ${OBJS}
	@echo -n "${END}"

fclean: clean
	@echo -n "${RED}"
	rm -f ${NAME}
	@echo -n "${END}"

re: fclean all

good: fclean all
	make clean
	clear

.PHONY: all clean fclean re header good