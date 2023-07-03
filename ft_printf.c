/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:51:58 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/02 23:06:04 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	print_arg(va_list ap, t_format *fm)
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
