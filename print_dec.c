/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:40:09 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/08 23:56:52 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	get_size(t_fm *fm, int arg, char flag)
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

static int	get_zeros(t_fm *fm, long arg)
{
	int	n_zeros;
	int	digits;

	digits = ft_getdig(arg, 10);
	n_zeros = 0;
	if (fm -> precision >= digits)
	{
		n_zeros = fm -> precision - digits;
		if (arg < 0)
			n_zeros++;
	}
	else if (fm -> width > digits && fm -> zerominus == '0')
	{
		n_zeros = fm -> width - digits;
		if (arg < 0 || (arg > 0 && fm -> spaceplus))
			n_zeros--;
	}
	return (n_zeros);
}

static void	fill_decstr(char *dest, long arg, t_fm *fm)
{
	int	i;
	int sign;
	int n_zero;

	n_zero = get_zeros(fm, arg);	
	sign = 1;
	if (arg < 0)
		sign = -1;
	arg *= sign;
	i = 0;
	while (arg)
	{
		dest[i] = arg % 10 + 48;
		arg = arg / 10;
		i++;
	}
	while (n_zero > 0)
	{
		dest[i] = '0';
		i++;
		n_zero--;
	}
	i += add_prefix(dest + i, fm, sign);
	reverse_str(dest, i, fm);
	return ;
}

// funktioniert auch für format_spec u
int	print_dec(va_list ap, t_fm *fm)
{
	long	arg;
	char	*str;

	arg = va_arg(ap, int);
	str = prep_str(get_size(fm, arg, 0), ' ');
	if (!str)
		return (-1);
	fill_decstr(str, arg, fm);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}
/*
int	print_u(va_list ap, t_fm *fm)
{
	unsigned int	arg;
	char			*str;

	arg = va_arg(ap, unsigned int);
	str = prep_str(get_size(fm, arg, 0), ' ');
	if (!str)
		return (-1);
	fill_decstr(str, arg, fm);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}
*/
