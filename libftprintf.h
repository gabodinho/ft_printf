/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:44:13 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/27 23:26:27 by ggiertzu         ###   ########.fr       */
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

typedef struct s_format
{
		char	format_spec;
		int		width;
		int		precision;
		int		alter;
		char	zerominus;
		char	spaceplus;
		}       t_format;

int	ft_digtoi(const char *nptr);
t_format	new_format(void);
void	get_format(const char *ptr, t_format *fm);
char	check_syntax(const char *ptr);
char	*prep_str(size_t size, char	fill);
int	print_char(va_list ap, t_format *fm);
int	print_dec(va_list ap, t_format *fm);
int print_str(va_list ap, t_format *fm);

#endif
