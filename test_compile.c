/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:08:35 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/27 23:44:45 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void  test_char(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	t_format fm = new_format();
	get_format(str + 1, &fm);
	printf("res_char: %d\n",print_char(ap, &fm));
	va_end(ap);
//	free((void *) fm);
	return ;
}

void test_str(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	t_format fm = new_format();
	get_format(str + 1, &fm);
	printf("res_str: %d\n", print_str(ap, &fm));
	va_end(ap);
	return ;
}

int main(void)
{
	test_char("%#0-+2.3c testtesttest", 'd');
	write(1, "\n", 1);
	test_char("%#-5.3c testtesttest", 'f');	//	<-- Error when printing f
	write(1, "\n", 1);
	test_str("%10.3s testtesttest", "test");
	return (0);
}
