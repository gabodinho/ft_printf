/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:25:52 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/20 19:24:44 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>		// for int_max

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
static int count;

void comp(int my, int og)
{
	count++;
	printf("\ntest no. %d: ", count);
	if (my - og == 0)
    {
        printf(GREEN "Passed\n" RESET);
		printf("return = %d\n", og);
        return ;
    }
    else
    {
        printf(RED "Failed\n" RESET);
		printf("my = %d, og = %d\n", my, og);
        return ;
    }
}

int main()
{
	char format[] = "% s";
	char *str = ft_strjoin("Format START:%", format);
	char arg[] = "";

//	ft_putstr_fd(str, 1);
	printf(str);
    printf("\nmy function START:");
	fflush(stdout);
	int a = ft_printf(format, arg);			// check this case!
    printf("\nog function START:");
    int b = printf(format, arg);
    comp(a, b);

	char format2[] = "%12.7s";
	char *str2 = ft_strjoin("\nFormat START:%", format2);
//	ft_putstr_fd(str, 1);
	printf(str2);
    printf("\nmy function START:");
	fflush(stdout);
    a = ft_printf(format2, 0);
    printf("\nog function START:");
    b = printf(format2, 0);
    comp(a, b);

	return (0);
}
