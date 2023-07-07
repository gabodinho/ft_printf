/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:25:52 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/07 20:00:55 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
static int count;

void comp(int result)
{
	count++;
	printf("\ntest no. %d: ", count);
	if (result == 0)
    {
        printf(GREEN "Passed\n" RESET);
        return ;
    }
    else
    {
        printf(RED "Failed\n" RESET);
        return ;
    }
}

int main()
{
    printf("\nmy function: ");
	fflush(stdout);
    int a = ft_printf("%c", 'A');
    printf("\nog function: ");
    int b = printf("%c", 'A');
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%s", "Hello, world!");
    printf("\nog function: ");
    b = printf("%s", "Hello, world!");
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%p", NULL);
    printf("\nog function: ");
    b = printf("%p", NULL);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%d", 42);
    printf("\nog function: ");
    b = printf("%d", 42);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%i", -123);
    printf("\nog function: ");
    b = printf("%i", -123);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%u", 12345);
    printf("\nog function: ");
    b = printf("%u", 12345);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%x", 255);
    printf("\nog function: ");
    b = printf("%x", 255);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%X", 65535);
    printf("\nog function: ");
    b = printf("%X", 65535);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%%");
    printf("\nog function: ");
    b = printf("%%");
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%-10c", 'A');
    printf("\nog function: ");
    b = printf("%-10c", 'A');
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%10c", 'A');
    printf("\nog function: ");
    b = printf("%10c", 'A');
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%-10s", "string");
    printf("\nog function: ");
    b = printf("%-10s", "string");
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%10s", "string");
    printf("\nog function: ");
    b = printf("%10s", "string");
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%-10d", 123);
    printf("\nog function: ");
    b = printf("%-10d", 123);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%10d", 123);
    printf("\nog function: ");
    b = printf("%10d", 123);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%-10i", -123);
    printf("\nog function: ");
    b = printf("%-10i", -123);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%10i", -123);
    printf("\nog function: ");
    b = printf("%10i", -123);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%-10u", 12345);
    printf("\nog function: ");
    b = printf("%-10u", 12345);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%10u", 12345);
    printf("\nog function: ");
    b = printf("%10u", 12345);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%-10x", 255);
    printf("\nog function: ");
    b = printf("%-10x", 255);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%10x", 255);
    printf("\nog function: ");
    b = printf("%10x", 255);
    comp(a - b);

    printf("\nmy function: ");
	fflush(stdout);
    a = ft_printf("%-10X", 65535);
    printf("\nog function: ");
   	b = ft_printf("%-10X", 65535);
	comp(a - b);

	return (0);
}

