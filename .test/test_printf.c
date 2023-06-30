/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:49:36 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/30 18:58:47 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

int test_printf(const char* str, ...)
{
	va_list ap;
	va_start(ap, str);
	int test = va_arg(ap, int);
	int count = 0;
	while(test != 1)
	{
		printf("test_printf: %d\n", test);
		test = va_arg(ap, int);
		count++;
	}
	va_end(ap);
	return (count);
}

int main(void)
{
	char str[] = "";
	int test_int = 1234;
	char test_char = 't';
	void *ptr;
	uintptr_t int_ptr = (uintptr_t) &test_int;
	printf("1. %x\n", 1234);
	printf("2. %#X\n", 16);
	printf("3. %0# 7.7X\n", 31);
	printf("4. %#3x\n", 31);
/*
	printf("1. %- 06.6d\n", -1234);
	printf("2. %0 d\n", test_int);
	printf("3. %.1d\n", test_int);
	printf("4. %1d\n", test_int);
	printf("5. %0 d\n", test_int);
	printf("6. %0+5d\n", test_int);
	printf("7. %+.5d\n", test_int);
	printf("8. % 7.5d\n", test_int);
	printf("9. % .5d\n", test_int);
	printf("10. % .d\n", test_int);
	printf("11. %07.5d\n", test_int);
	printf("12. START%.dEND\n", 0);
	printf("13. %0-7d\n", test_int);
	printf("14. %u\n", -1234);
*/	
//	printf("%d\n", test_int);

//	printf("%s\n", test_char);		format specifies type 'char *' but the argument has type 'char'
//	printf("%s\n", ptr);		format specifies type 'char *' but the argument has type 'void 
	printf("%x\n", test_int);
	printf("%p\n", str);
	printf("START%- sENDE\n", str);
	printf("hello", test_int);
	test_printf("this ", 3, 3, 4, 6);
	printf("using ptr conversin: %p\n", &test_int);
	printf("using uintptr_t: %#lx\n", int_ptr);
	printf("this is a test: %# 0#-00+5.4d\nds weiter gehts im text : %d\n %d", test_int, str);
	printf("this is another test: %%%#.1d0#-00+5.4d\nds weiter gehts im text : %d\n %d END", test_int, str);
	return (0) ;
}

