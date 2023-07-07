/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:51:58 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/07 20:00:54 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	print_arg(va_list ap, t_fm *fm)
{
	if (ft_strchr("diu", fm -> format_spec))
		return (print_dec(ap, fm));
	if (fm -> format_spec == 'c')
		return (print_char(ap, fm));
	if (fm -> format_spec == 's')
		return (print_str(ap, fm));
	if (ft_strchr("xXp", fm -> format_spec))
		return (print_hex(ap, fm));
	if (fm -> format_spec == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char* str, ...)
{
	int	res;
	va_list	ap;

	res = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%' && check_syntax(str + 1))
		{
			res += print_arg(ap, get_format(str + 1));
			str = check_syntax(str + 1);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			res++;
		}
		str++;
	}
	va_end(ap);
	return (res);
}
