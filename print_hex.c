/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:40:09 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/03 20:07:14 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static void	mod_fmptr(t_fm	*fm)
{
	if (fm -> zerominus == '0')
		fm -> zerominus = 0;
	fm -> spaceplus = 0;
	fm -> alter = 1;
	fm -> precision = -1;
	return ;
}

static int	get_size_hex(t_fm *fm, int arg, char flag)
{
	int	digits;

	digits = ft_getdig(arg, 16);
	if (fm -> precision > digits)
		digits = fm -> precision;
	if (fm -> alter)
		digits += 2;
	if (digits > fm -> width || flag)
		return (digits);
	else
		return (fm -> width);
}

static int	get_zeros_hex(t_fm *fm, long arg)
{
	int	n_zeros;
	int	digits;

	digits = ft_getdig(arg, 16);
	n_zeros = 0;
	if (fm -> precision > digits)
		n_zeros = fm -> precision - digits;
	else if (fm -> zerominus == '0' && fm -> precision == -1)
	{
        n_zeros = fm -> width - digits;
        if (fm -> alter == 1)
			n_zeros -= 2;
	}
	if (n_zeros >= 0)
		return (n_zeros);
	else
		return (0);
}

static void	fill_hexstr(char *dest, long arg, t_fm *fm)
{
	int	i;
	int n_zero;

	n_zero = get_zeros_hex(fm, arg);
	i = 0;
	i = rdec2hex(dest, arg, fm -> format_spec);
	while (n_zero > 0)
	{
	        dest[i] = '0';
	        i++;
	        n_zero--;
	}
	i += add_prefix(dest + i, fm, 2);
	reverse_str(dest, i, fm);
	return ;
}

int	print_hex(va_list ap, t_fm *fm)
{
	uintptr_t	arg;
	char			*str;

	if (fm -> format_spec == 'p')
	{
		arg = va_arg(ap, uintptr_t);
		mod_fmptr(fm);
	}
	else
		arg = (uintptr_t) va_arg(ap, unsigned int);
	str = prep_str(get_size_hex(fm, arg, 0), ' ');
	if (!str)
		return (-1);
	fill_hexstr(str, arg, fm);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}
