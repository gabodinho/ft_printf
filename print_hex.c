/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:40:09 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/30 19:00:43 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"


static size_t   ft_getdig(long n, int base)
{
        unsigned long   digits;

        if (n < 0)
        {
                digits = 2;
                n = n * (-1);
        }
        else
                digits = 1;
        while (n / base > 0)
        {
                n = n / base;
                digits++;
        }
        return (digits);
}

// hier weitermachen !
int	get_zeros(t_format *fm, long arg)
{
	int	n_zeros;
	int	digits;

	digits = ft_getdig(arg, 16);
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
	printf("get_zeros return: %d\n", n_zeros);
	return (n_zeros);
}

int	add_prefix(char *dest, t_format *fm, int sign)
{
	if (sign == -1)
	{
		*dest = '-';
		return (1);
	}
	else if (fm -> spaceplus)
	{
		*dest = fm -> spaceplus;
		return (1);
	}
	else
		return (0);
}

void	reverse_str(char *dest, int size, t_format *fm)
{
	size_t	i;
	char	buff;

	i = 0;
	printf("before revering: %s\n", dest);
	while (i < size - i)
	{
		buff = dest[i];
		dest[i] = dest[size - i - 1];
		dest[size - i - 1] = buff;
		i++;
	}
	printf("after reversing: %s\n", dest);
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
	printf("after moving: %s\n", dest);
	return ;
}

void	fill_decstr(char *dest, long arg, t_format *fm)
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

int	print_dec(va_list ap, t_format *fm)
{
	long	arg;
	char	*str;

	arg = va_arg(ap, long);
	str = prep_str(get_size(fm, arg, 0), ' ');
	printf("return get_size: %d\n", get_size(fm, arg, 0));
	if (!str)
		return (-1);
	fill_decstr(str, arg, fm);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}

int	print_u(va_list ap, t_format *fm)
{
	unsigned int	arg;
	char			*str;

	arg = va_arg(ap, unsigned int);
	str = prep_str(get_size(fm, arg, 0), ' ');
	printf("return get_size: %d\n", get_size(fm, arg, 0));
	if (!str)
		return (-1);
	fill_decstr(str, arg, fm);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}

/*
void test_dec(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	t_format fm = new_format();
	get_format(str + 1, &fm);
	printf("res_dec: %d\n", print_dec(ap, &fm));
	va_end(ap);
	return ;
}

int main(void)
{
	test_dec("%- 06.6d testtesttest", -1234);
	return (0);
}

*/
