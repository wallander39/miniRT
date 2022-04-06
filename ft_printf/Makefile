# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 16:32:38 by pperea-d          #+#    #+#              #
#    Updated: 2021/02/02 16:06:52 by pperea-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB		=	ft_printf.h
SRCS	=	ft_printf.c 			\
			flags.c					\
			print_manager.c			\
			ft_printf_utils.c		\
			ft_itoa_base.c			\
			ft_print_char.c			\
			ft_print_pointer.c		\
			ft_print_string.c		\
			ft_print_unsigned.c		\
			ft_print_int.c			\
			ft_print_hex.c			\
			ft_printf_utils2.c		\
			ft_print_percent.c		\
			ft_print_total.c
OBJS	=	$(SRCS:.c=.o)
NAME	=	libftprintf.a
CFLAGS	=	-I 	../libft/ -Wall -Werror -Wextra  
			

$(NAME):	$(OBJS) 
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)

.c.o:
			@gcc $(CFLAGS) -c $< -o $(<:.c=.o) 


all:		$(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
