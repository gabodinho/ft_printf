/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:44:13 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/02 23:01:47 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <bsd/string.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_format
{
		char	format_spec;
		int		width;
		int		precision;
		int		alter;
		char	zerominus;
		char	spaceplus;
		}       t_format;

size_t   ft_getdig(long n, int base);
int add_prefix(char *dest, t_format *fm, int sign);
void    reverse_str(char *dest, int size, t_format *fm);
t_format	new_format(void);
void	get_format(const char *ptr, t_format *fm);
char	check_syntax(const char *ptr);
char	*prep_str(size_t size, char	fill);
int	free_len(char *str);
int	get_size(t_format *fm, int arg, char flag);
int rdec2hex(char *dest, long arg, char flag);
int	print_char(va_list ap, t_format *fm);
int	print_dec(va_list ap, t_format *fm);
int print_str(va_list ap, t_format *fm);
int	print_dec(va_list ap, t_format *fm);
int print_u(va_list ap, t_format *fm);
int print_hex(va_list ap, t_format *fm);

#endif
