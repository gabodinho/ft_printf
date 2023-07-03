/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:11:08 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/03 21:33:06 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static int	get_size_str(t_fm *fm, const char *arg, int flag)
{
	int	len;

	len = ft_strlen(arg);
	if (fm -> precision < len && fm -> precision != -1)
		len = fm -> precision;
	if (len > fm -> width || flag)
		return (len);
	else
		return (fm -> width);
}

int	print_str(va_list ap, t_fm *fm)
{
	const char	*arg;
	char		*str;
	int			buff_len;
	int			prt_len;

	arg = va_arg(ap, const char*);
	buff_len = get_size_str(fm, arg, 0);
	str = prep_str(buff_len, ' ');
	if (!str)
		return (-1);
	prt_len = get_size_str(fm, arg, 1);
	if (fm -> zerominus == '-')
		ft_memcpy(str, arg, prt_len);
	else
		ft_memcpy(str + (buff_len - prt_len), arg, prt_len);
	ft_putstr_fd(str, 1);
	return (free_len(str));
}

int	print_char(va_list ap, t_fm *fm)
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
