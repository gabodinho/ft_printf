/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:40:09 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/03 20:09:59 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	rdec2hex(char *dest, long arg, char flag)
{
	int	i;
	int dec;
	int offset;

	i = 0;
	offset = 87;
	if (flag == 'X')
		offset = 55;
	while (arg)
	{
		dec = arg % 16;
		if (dec >= 10)
			dest[i] = dec + offset;
		else
			dest[i] = dec + 48;
		arg /= 16;
		i++;
	}
	return (i);
}

char	*prep_str(size_t size, char	fill)
{
	char			*ptr;
	unsigned long	count;

	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (0);
	ptr[size] = 0;
	count = 0;
	while (count < size)
	{
		ptr[count] = fill;
		count++;
	}
	return (ptr);
}

int	free_len(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t   ft_getdig(long n, int base)
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

int	add_prefix(char *dest, t_fm *fm, int sign)
{
	int i;

	i = 0;
	if (sign == -1 || (fm -> spaceplus && sign == 1))
	{
		if (sign == -1)
	        *dest = '-';
		else
			*dest = fm -> spaceplus;
		i = 1;
	}
	else if ((sign == 2 && fm -> alter) || fm -> format_spec == 'P')
	{
		if (fm -> format_spec == 'x' || fm -> format_spec == 'p')
			*dest = 'x';
		else if (fm -> format_spec == 'X')
			*dest = 'X';
		*(dest + 1) = '0';
	    i = 2;
	}
	return (i);
}
