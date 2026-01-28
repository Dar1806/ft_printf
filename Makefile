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

SRCS = functions.c functions_hexa.c
MAIN_SRC = ft_printf.c

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf
LIB_NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(MAIN_OBJ) $(OBJS)
			$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) -o $(NAME)

$(LIB_NAME):	$(OBJS)
			ar rcs $(LIB_NAME) $(OBJS)

clean:
			$(RM)	$(OBJS) $(MAIN_OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIB_NAME)

re:			fclean all
