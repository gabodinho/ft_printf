# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 18:33:58 by ggiertzu          #+#    #+#              #
#    Updated: 2023/07/21 18:14:58 by ggiertzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
CC = cc
CFLAGS = -Werror -Wall -Wextra -I. -I./libft
#CPPFLAGS = -I./libft
MAKE = make -C
LDFLAGS = -L./libft -L.
#LDLIBS = -lftprintf -lft
RM = rm -f

SRCS = print_dec.c  print_hex.c print_ptr.c printf_utils1.c \
printf_utils2.c printf_utils3.c print_str.c ft_printf.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

bonus: $(NAME)
clean:
	${RM} $(OBJS)
	$(MAKE) $(LIBFT_DIR) clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBFT_DIR) fclean
re: fclean all
