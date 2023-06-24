/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:11:08 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/24 21:26:42 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>


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


int	print_char(va_list ap, t_format *fm, const char *str)
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
	return (ft_strlen(str));
}

int	print_dec(va_list ap, const char *ptr)
{
	int		arg;
	char	*str;
	int		len;
	char	*buf;

	arg = va_arg(ap, int);
	str = ft_itoa(arg);
	len = ft_strlen(str);
	if (							//		<--- hier weiter


int	print_arg(va_list ap, t_format *fm, const char *str)
{
	if (fm -> format_spec == 'i' || fm -> format_spec == 'd')
		return (print_dec(ap, fm, str));
	if (fm -> format_spec == 'c')
		return (print_char(ap, fm, str));
	if (fm -> format_spec == 's')
		return (print_string(ap, fm, str));
	if (fm -> format_spec == 'p')
		return (print_pointer(ap, fm, str));
	if (fm -> format_spec == 'u')
		return (print_udec(ap, fm, str));
	if (fm -> format_spec == 'x' || fm -> format_spec == 'X')
		return (print_hex(ap, fm, str));
	if (fm -> format_spec == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else
		return (0);
}
