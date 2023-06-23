/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_variadic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:27:15 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/24 00:08:11 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>


#include <stdio.h>

void print_arg(va_list ap, char spec)
{
	if (spec == 'd')
		printf("this is an int: %d\n", va_arg(ap, int));
	else if (spec == 's')
		printf("this is a string: %s\n", va_arg(ap, const char*));
	return;
}

int my_func(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	int count = 0;
	while (*str)
	{
		print_arg(ap, *str);
		str++;
		count++;
	}
	va_end(ap);
	return (count);
}

int main(void)
{
	printf("this is a test: %d\n", my_func("dsd", 1, "test string", 3));
	return (0);
}

/*
int main(int argn, char argv[])
{
	char input[] = argv[1];
	return (0);
}
*/
