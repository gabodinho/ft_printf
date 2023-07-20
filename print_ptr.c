/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:40:09 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/19 16:17:18 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	get_size_ptr(t_fm *fm, long arg, char flag)
{
	int	digits;

	if (!arg)
		digits = 5;
	else
		digits = ft_getdig(arg, 16) + 2;
	if (fm -> precision > digits)
		digits = fm -> precision;
	if (fm -> spaceplus && arg)
		digits++;
	if (digits > fm -> width || flag)
		return (digits);
	else
		return (fm -> width);
}

static int	get_zeros_ptr(t_fm *fm, long arg)
{
	int	n_zeros;
	int	digits;

	digits = ft_getdig(arg, 16) + 2;
	n_zeros = 0;
	if (fm -> precision > digits)
		n_zeros = get_size_ptr(fm, arg, '1') - digits;
	else if (fm -> zerominus == '0' && fm -> precision == -1)
		n_zeros = get_size_ptr(fm, arg, 0) - digits;
	if (fm -> spaceplus)
		n_zeros--;
	if (n_zeros < 0)
		n_zeros = 0;
	return (n_zeros);
}

static void	fill_ptrstr(char *dest, long arg, t_fm *fm)
{
	int	i;
	int n_zero;

	if (!arg)
	{
		ft_memcpy(dest, ")lin(", 5);
		i = 5;
	}
	else
	{
		n_zero = get_zeros_ptr(fm, arg);
//		printf("n_zero: %d\n", n_zero);
		i = rdec2hex(dest, arg, fm -> format_spec);
//		printf("digits: %d\n, len dest: %zu", i, ft_strlen(dest));
		while (n_zero > 0)
		{
			dest[i] = '0';
			i++;
			n_zero--;
		}
//		printf("before prefix: %s\n", dest);
		i += add_prefix(dest + i, fm, 2);
		i += add_prefix(dest + i, fm, 1);
//		printf("before after: %s, i: %d\n", dest, i);
	}
	reverse_str(dest, i, fm);
	return ;
}

int	print_ptr(va_list ap, t_fm *fm)
{
	uintptr_t	arg;
	char		*str;

	arg = va_arg(ap, uintptr_t);
	str = prep_str(get_size_ptr(fm, arg, 0), ' ');
//	printf("size: %d\n", get_size_ptr(fm, arg, 0));
	if (!str)
		return (-1);
	fill_ptrstr(str, arg, fm);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}