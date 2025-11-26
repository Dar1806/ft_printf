# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 19:17:26 by nmeunier          #+#    #+#              #
#    Updated: 2025/11/23 19:17:26 by nmeunier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_print.c functions.c functions_hexa.c

CC = cc 
RM = rm -f
CFLAGS = -Wall _wextra -Werror

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM)	$(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM)	libft.so

re:			fclean all
