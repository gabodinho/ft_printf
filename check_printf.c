/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:25:52 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/11 12:17:46 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

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
	char format[] = "%+0 15p";
	char *str = ft_strjoin("Format START:%", format);
//	ft_putstr_fd(str, 1);
	printf(str);
    printf("\nmy function START:");
	fflush(stdout);
    int a = ft_printf(format, &str );
    printf("\nog function START:");
    int b = printf(format, &str );
    comp(a, b);

	return (0);
}

