/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:11:08 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/24 00:52:43 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	print_arg(va_list ap, char spec, const char *str)
{
	if (spec == 'i' || spec == 'd')
		return (print_dec(va_arg(ap, int), str));
	if (spec == 'c')
		return (print_char(va_arg(ap, int), str));
	if (spec == 's')
		return (print_string(va_arg(ap, const char*), str));
	if (spec == 'p')
		return (print_pointer(va_arg(ap, void*), str));
	if (spec == 'u')
		return (print_udec(va_arg(ap, unsigned int), str));
	if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(ap, unsigned int), str));
	if (spec == '%')
	{
		ft_putchar('%');
		return (1);
	}
}
