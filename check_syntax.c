/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:35:15 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/24 19:01:52 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

char	*ft_strchr(const char *s, int c)
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

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

char	check_syntax(const char *ptr)
{
	if (*ptr == '%')
		return ('%');
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
		return (*ptr);
	else
		return (0);
}

#include <stdio.h>

int main(void)
{
	char str[] = "#++--#0 345.34545s4%this";
	printf("result is: %c\n", check_syntax(str));
	return (0);
}

/*
int main(int argn, char argv[])
{
	char input[] = argv[1];
	return (0);
}
*/
