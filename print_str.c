/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:11:08 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/02 22:09:50 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	get_size(t_format *fm, int arg, char flag)
{
	int	digits;
	int	is_negativ;

	is_negativ = 0;
	if (arg < 0)
	{
		is_negativ = 1;
		arg = arg * -1;
	}
	digits = ft_getdig(arg, 10);
	if (fm -> precision > digits)
		digits = fm -> precision;
	if (is_negativ || fm -> spaceplus)
		digits++;
	if (digits > fm -> width || flag)
		return (digits);
	else
		return (fm -> width);
}

int	print_str(va_list ap, t_format *fm)
{
	const char		*arg;
	char			*str;
	size_t			len;

	arg = va_arg(ap, const char*);
	len = ft_strlen(arg);
	if ((int) len >= fm -> width)
		fm -> width = len;
	str = prep_str(fm -> width, ' ');
	if (!str)
		return (-1);
	if (fm -> precision < 0 || fm -> precision >= (int) len)
		fm -> precision = len;
	if (fm -> zerominus == '-')
		ft_memcpy(str, arg, fm -> precision);
	else
		ft_memcpy(str + (fm -> width - fm -> precision), arg, fm -> precision);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}

int	print_char(va_list ap, t_format *fm)
{
	unsigned char	arg;
	char			*str;

	arg = (unsigned char) va_arg(ap, int);
	if (fm -> width == 0)
		fm -> width = 1;
	str = prep_str(fm -> width, ' ');
	if (!str)
		return (-1);
	if (fm -> zerominus == '-')
		*str = arg;
	else
		str[fm -> width - 1] = arg;
	ft_putstr_fd(str, 1);
	return (free_len(str));
}
