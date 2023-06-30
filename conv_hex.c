/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:03:26 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/30 18:43:30 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static char	dec2hex_char(int dec, int flag)
{
	int offset;

	offset = 87;
	if (flag)
		offset = 55;
	if (dec >= 10)
		return (dec + offset);
	else
		return (dec + 48);
}

void	rdec2hex_str(char *dest, long arg, int flag)
{
	int	i;

	i = 0;
	while (arg)
	{
		dest[i] = dec2hex_char(arg % 16, flag);
		arg /= 16;
		i++;
	}
	return ;
}
/*
int main(void)
{
	char str[] = "this is a test";
	rdec2hex_str(str, 31, 1);
	printf("%s\n", str);
	return (0);
}
*/
