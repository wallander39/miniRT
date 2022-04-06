# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 16:39:31 by pperea-d          #+#    #+#              #
#    Updated: 2021/02/10 17:29:31 by pperea-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB		=	minirt.h
SRC	=		main.c\
			camera.c\
			checker.c \
			cylinder.c \
			delete_scene.c \
			mini_utils.c\
			plane.c\
			render_cylinder.c\
			render_plane.c\
			render_scene.c\
			render_sphere.c\
			render_triangle.c\
			sphere.c\
			square.c\
			triangle.c\
			light.c\
			render_square.c\
			shading.c\
			shadows1.c\
			v_operations.c\
			saver.c\
			v_operations2.c\
			error.c\
			reader.c\
			mini_utils2.c\
			caps.c\
			camrot.c\

SRC_BONUS	=	main.c\
				camera.c\
				checker.c \
				cylinder.c \
				delete_scene.c \
				mini_utils.c\
				plane.c\
				render_cylinder.c\
				render_plane.c\
				render_scene.c\
				render_sphere.c\
				render_triangle.c\
				sphere.c\
				square.c\
				triangle.c\
				light.c\
				render_square.c\
				shading.c\
				shadows1.c\
				v_operations.c\
				saver.c\
				v_operations2.c\
				v_operations3.c\
				error.c\
				reader.c\
				mini_utils2.c\
				caps.c\
				camrot.c\
				select.c\
				movecam.c\
				movesp.c\
				movecyl.c\
				movepl.c\
				movetr.c\
				movetr2.c\
				initclose.c\
				dirlight.c\
				dirshadows1.c\
				shading2.c\
				filters.c\
				filters2.c\
				sphere2.c\
				uvfunc.c\
				cube.c\
				pyramid.c\
				pyramid2.c\
			
SRC_DIR		= src/

SRC_BONUS_DIR	= src_bonus/

SRCS			= $(addprefix $(SRC_DIR), $(SRC))

SRCS_BONUS	= $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS))

THREADS = 1		
OBJS	=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
NAME	=	miniRT
CFLAGS	=	-Ilibft/ -Ignl/ -Ift_printf -Wall -Werror -Wextra -D THREADS=$(THREADS)
LFAGS	=	-L./ft_printf/ -lftprintf -L./gnl/ -lgnl -L./libft/ -lft -lmlx -framework OpenGL -framework AppKit -I /usr/local/include -L /usr/local/lib  		


CC		=	gcc

%o: %c
			$(MAKE) -s -C libft
			$(MAKE) -s -C gnl
			$(MAKE) -s -C ft_printf
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(LFAGS) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(OBJS_BONUS)
			$(CC) $(LFAGS) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)

all:		$(NAME)

clean:
			@rm -f $(OBJS) $(OBJS_BONUS)
			@make -C libft clean
			@make -C gnl clean
			@make -C ft_printf clean


fclean:		clean
			rm -f $(NAME)
			@make fclean -C libft
			@make fclean -C gnl 
			@make fclean -C ft_printf

re:			fclean all

rebonus:			fclean bonus

.PHONY:		all clean fclean re bonus