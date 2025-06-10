NAME	=	minirt

GNL		= 	gnl/get_next_line_utils.c gnl/get_next_line.c

PARSING =	parsing/handle_shapes.c parsing/handling.c \
			parsing/helper.c parsing/initialization.c \
			parsing/insert.c parsing/validation.c \
			parsing/handle_helper.c

UTILS	=	utils/atoi.c utils/errors.c \
			utils/frees.c utils/libft.c \
			utils/split.c utils/angle_calcul.c

INTER	= 	intersections/cylinder.c intersections/plane.c \
			intersections/sphere.c

CAM		=	camera/camera.c camera/create_window.c \
			camera/my_mlx_pixel_put.c camera/lighting.c

VECT	=	vector/vector.c vector/vector_ops.c

SRCS	=	main.c $(GNL) $(PARSING) $(UTILS) $(INTER) $(CAM) $(VECT)
OBJS	=	${SRCS:.c=.o}
CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall -I. -I./minilibx-linux
MLX_FLAGS = -lmlx -lXext -lX11 -L./minilibx-linux -lm
MLX 	= minilibx-linux/libmlx_Linux.a

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
	@for i in 1 ; do \
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