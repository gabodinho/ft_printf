/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:35:15 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/24 00:58:16 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (check_syntax(str + 1))
			{
				str++;
				count += print_arg(ap, get_format_spec(str), str);
				set_ptr(str);		// <-- yet to be defined 
			}
			else
			{
				count += print_char(*str);
				str++;
			}
		}
		else
		{
			count += print_char(*str);
			str++;
		}
	}
	return (count);
}



/*
#include <stdio.h>

int main(void)
{

	return (0);
}
*/
/*
int main(int argn, char argv[])
{
	char input[] = argv[1];
	return (0);
}
*/
