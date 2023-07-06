/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:35:15 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/06 00:01:22 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

const char	*check_syntax(const char *ptr)
{
	if (*ptr == '%')
		return (ptr);
	while (ft_strchr("#0+- ", *ptr))
		ptr++;
	while (ft_isdigit(*ptr))
		ptr++;
	if (*ptr == '.')
	{
		ptr++;
		while (ft_isdigit(*ptr))
			ptr++;
	}
	if (ft_strchr("cspdiuxX", *ptr))
		return (ptr);
	else
		return (0);
}

void	reverse_str(char *dest, int size, t_fm *fm)
{
	size_t	i;
	char	buff;

	i = 0;
	while (i < size - i)
	{
		buff = dest[i];
		dest[i] = dest[size - i - 1];
		dest[size - i - 1] = buff;
		i++;
	}
	if (fm -> zerominus != '-')
	{
		memmove(dest + ft_strlen(dest) - size, dest, size);
		i = 0;
		while (i < ft_strlen(dest) - size)
		{
			dest[i] = ' ';
			i++;
		}
	}
	return ;
}

static int	ft_digtoi(const char *nptr)
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

t_fm	*new_format(void)
{
	t_fm	*new;

	new = malloc(sizeof(t_fm));
	new -> format_spec = 0;
	new -> width = 0;
	new -> precision = -1;
	new -> alter = 0;
	new -> zerominus = 0;
	new -> spaceplus = 0;
	return (new);
}

static void	get_formatII(const char *ptr, t_fm *fm)
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

t_fm	*get_format(const char *ptr)
{
	t_fm	*fm;

	fm = new_format();
	if (*ptr == '%')
	{
		fm -> format_spec = '%';
		return (fm);
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
	return (fm);
}
/*
#include <stdio.h>

int main(void)
{
	char str[] = "#++--#0 345.34545s4%this";
	t_fm fm = new_format();
	get_fm(str, &fm);
	printf("flags are: \"%d%0-10c%c\"; width is: %d; precision is %d;\nformat specifier is: %c", \
	fm.alter, fm.zerominus, fm.spaceplus, fm.width, fm.precision, fm.format_spec);
	return (0);
}*/
