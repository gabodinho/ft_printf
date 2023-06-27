# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 18:33:58 by ggiertzu          #+#    #+#              #
#    Updated: 2023/06/27 03:35:03 by ggiertzu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = libftprintf.h
CC = cc
CFLAGS = -Werror -Wall -Wextra
CPPFLAGS = -I./libft
LDFLAGS = -L./libft -L.
LDLIBS = -lftprintf -lft
RM = rm -f

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)		 # $(DEPS)
	ar rcs $@ $^

$(OBJS): %.o: %.c $(HEADER) $(DEPS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LDLIBS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(DEPS): %.d: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -M $< >$@

include $(DEPS)

clean:
	${RM} $(OBJS) $(DEPS)
	make -C $(LIBFT_DIR) clean
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
re: fclean all

cf:
	$(MAKE) -f Makefile2 $(TARGET)

cfclean:
	$(MAKE) -f Makefile2 clean

# $@ refers to target name; $^ all prerequisites; $< refers to first matching object
#%.o: %.c   <-- this is an implicit rule and does not need to be written
#   $(CC) $(CFLAGS) -c $< -o $@

