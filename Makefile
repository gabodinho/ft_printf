# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 18:33:58 by ggiertzu          #+#    #+#              #
#    Updated: 2023/07/24 02:43:16 by ggiertzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ./libft/libft.h ./ft_printf.h
CC = cc
CFLAGS = -Werror -Wall -Wextra -I. -Ilibft
MAKE = make -C
LDFLAGS = -Llibft/
LDLIBS = -lft
RM = rm -f

SRCS = print_dec.c  print_hex.c print_ptr.c printf_utils1.c \
printf_utils2.c printf_utils3.c print_str.c ft_printf.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar x $(LIBFT)
	ar crs $@ *.o

%.o: %.c #$(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

bonus: $(NAME)
clean:
	${RM} *.o
	make clean -C $(LIBFT_DIR)
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
re: fclean all

.PHONY: all clean fclean re bonus
