/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:35:15 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/27 00:24:34 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct s_format
{
		char	format_spec;
		int		width;
		int		precision;
		int		alter;
		char	zerominus;
		char	spaceplus;
		}       t_format;

int     ft_isdigit(int c)
{
        if (c > 47 && c < 58)
                return (1);
        else
                return (0);
}

char    *ft_strchr(const char *s, int c)
{
        while (*s)
        {
                if (*s == (char) c)
                        return ((char *) s);
                s++;
        }
        if (*s == (char) c)
                return ((char *) s);
        return (0);
}

int	ft_digtoi(const char *nptr)
{
	int	res;

	res = 0;
	while (ft_isdigit(*nptr))
	{
		res = (res * 10) + *nptr - 48;
			nptr++;
	}
	return (res);
}

t_format	new_format(void)
{
	t_format	*new;

	new = malloc(sizeof(t_format));
	new -> format_spec = 0;
	new -> width = 0;
	new -> precision = 0;
	new -> alter = 0;
	new -> zerominus = 0;
	new -> spaceplus = 0;
	return (*new);
}

static void	get_formatII(const char *ptr, t_format *fm)
{
	fm -> width = ft_digtoi(ptr);
	while (ft_isdigit(*ptr))
		ptr++;
	if (*ptr == '.')	
	{
		ptr++;
		if (fm -> zerominus == '0')
			fm -> zerominus = 0;
		fm -> precision = ft_digtoi(ptr);
		while (ft_isdigit(*ptr))
			ptr++;
	}
	if (ft_strchr("cspdiuxX", *ptr))
		fm -> format_spec = *ptr;
	return ;
}

void	get_format(const char *ptr, t_format *fm)
{
	if (*ptr == '%')
	{
		fm -> format_spec = '%';
		return ;
	}
	while (ft_strchr("#0- +", *ptr))
	{
		if (*ptr == '#')
			fm -> alter = 1;
		if (*ptr == '0' && fm -> zerominus == 0)
			fm -> zerominus = '0';
		if (*ptr == '-')
			fm -> zerominus = '-';
		if (*ptr == ' ' && fm -> spaceplus == 0)
			fm -> spaceplus = ' ';
		if (*ptr == '+')
			fm -> spaceplus = '+';
		ptr++;
	}
	get_formatII(ptr, fm);
	return ;
}
/*
#include <stdio.h>

int main(void)
{
	char str[] = "#++--#0 345.34545s4%this";
	t_format fm = new_format();
	get_format(str, &fm);
	printf("flags are: \"%d%0-10c%c\"; width is: %d; precision is %d;\nformat specifier is: %c", \
	fm.alter, fm.zerominus, fm.spaceplus, fm.width, fm.precision, fm.format_spec);
	return (0);
}*/
