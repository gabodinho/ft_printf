/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:11:08 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/28 13:09:47 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"


static size_t   ft_getdig(long n)
{
        unsigned long   digits;

        if (n < 0)
        {
                digits = 2;
                n = n * (-1);
        }
        else
                digits = 1;
        while (n / 10 > 0)
        {
                n = n / 10;
                digits++;
        }
        return (digits);
}

int	free_len(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	free(str);
	return (len);
}

//			************* hier weiter *************
fill_str(char *str, int arg, t_format *fm)
{
	int	digits;
	int start;

	digits = get_dig(arg);
	start = 0;
	if (fm -> zerominus != '-')
		start = ft_strlen(str) - get_size(fm, arg, 1);
	if (fm -> spaceplus == ' ' && arg > 0)
		memcpy(str + start, " ", 1);
// evtl muss die Generierung des ergebnisses mit in die itoa funktion integriert werden.
// es gestaltet sich äußerst umständlich andauernd inrgendwelche Längen zu berücksichtigen
// auf jeden fall fehlt noch eine Funktion, die die Zahl mit Nullen auffüllt, falls precision > digits ist. --> itoa bearbeiten.
// new_itoa output soll sein string mit länge precision und negativem vorzeichen, wenn nötig

int	get_size(t_format fm, int arg, char flag)
{
	int		digits;
	int		prec;
	int		width;

	digits = get_dig(arg);
	prec = fm -> precision;
	width = fm -> width;
	if (prec >= digits)
	{
		digits = prec;
		if (arg < 0 || fm -> spaceplus)
			digits++;
	}
	if (fm -> spaceplus)
		digits++;
	if (digits > width || flag)
		return (digits);
	else
		return (width);
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

int	print_dec(va_list ap, const char *ptr)
{
	int		arg;
	char	*str;
	char	*dig_str;
	size_t	*dig;

	arg = va_arg(ap, int);
	if (fm -> zerominus == '0')
		str = prep_str(get_size(fm, arg, 0), '0');
	else
		str = prep_str(get_size(fm, arg, 0), ' ');
	if (!str)
		return (-1);
	fill_str(str, arg, fm);
	
//
	str = ft_itoa(arg);
	len = ft_strlen(str);
	if (							//		<--- hier weiter

*/
/*
int	print_arg(va_list ap, t_format *fm, const char *str)
{
	if (fm -> format_spec == 'i' || fm -> format_spec == 'd')
		return (print_dec(ap, fm));
	if (fm -> format_spec == 'c')
		return (print_char(ap, fm));
	if (fm -> format_spec == 's')
		return (print_string(ap, fm));
	if (fm -> format_spec == 'p')
		return (print_pointer(ap, fm));
	if (fm -> format_spec == 'u')
		return (print_udec(ap, fm));
	if (fm -> format_spec == 'x' || fm -> format_spec == 'X')
		return (print_hex(ap, fm));
	if (fm -> format_spec == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else
		return (0);
}
*/
