/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:08:35 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/30 17:59:15 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_fm(t_format *fm)
{
	printf("These are the fm parameters:\n\tformatSpec: %c\n\twidth: %d\n\t\
precision: %d\n\talternative form: %d\n\tzerominus: %c\n\t\
spaceplus: %c\n", fm -> format_spec, fm -> width, fm -> precision, fm -> alter	\
	, fm -> zerominus, fm ->spaceplus);
	return ;
}

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

void test_dec(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	t_format fm = new_format();
	get_format(str + 1, &fm);
//	print_fm(&fm);
	printf("res_dec: %d\n", print_dec(ap, &fm));
	va_end(ap);
	return ;
}

void test_u(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	t_format fm = new_format();
	get_format(str + 1, &fm);
//	print_fm(&fm);
	printf("res_u: %d\n", print_u(ap, &fm));
	va_end(ap);
	return ;
}

int main(void)
{
	test_char("%#0-+2.3c testtesttest", 'd');
	write(1, "\n", 1);
	test_char("%#-5.3c testtesttest", 'f');
	write(1, "\n", 1);
	test_str("%10.3s testtesttest", "test");
	write(1, "\n", 1);
	test_dec("%d testtesttest", 1234);
	write(1, "\n", 1);
	test_u("%d testtesttest", -1234);
	return (0);
}
