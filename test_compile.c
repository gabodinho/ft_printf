/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:08:35 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/27 02:18:26 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void  get_ap(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	t_format fm = new_format();
	get_format(str + 1, &fm);
	print_char(ap, &fm);
	va_end(ap);
	return ;
}

int main(void)
{
	get_ap("%#0-+2.3c testtesttest", 'd');
	write(1, "\n", 1);
	get_ap("%#-5.3c testtesttest", 'f');
	return (0);
}
