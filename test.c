/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:26:03 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/24 21:57:21 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int	res;
	int og;

	char format[] = "p28 %.0x\n"; //"t7 %1.50d\n";
	long arg = 0;
	long arg2 = 2147483647;
	char *str = ft_strjoin("%", format);
//	printf("%%.x, %%.0x\n");
	printf("og:");
	og = printf("%00065.197d%132p%-%%-173.71i%--1.32i" ,-699619784,(void*)4809237208452777030lu,366715426,-130141062);
	printf("END");
	printf("\nmy:");
	fflush(stdout);
	res = ft_printf("%00065.197d%132p%-%%-173.71i%--1.32i" ,-699619784,(void*)4809237208452777030lu,366715426,-130141062);
	printf("END");
	if (res != og)
		printf("\nERROR");
	else
		printf("\nSUCCESS");
	printf("\nog: %d, my: %d\n", og, res);
	return (0);
}
