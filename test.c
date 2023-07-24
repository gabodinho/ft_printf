/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:26:03 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/24 15:09:56 by ggiertzu         ###   ########.fr       */
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
	og = printf(format, arg);
	printf("END");
	printf("\nmy:");
	fflush(stdout);
	res = ft_printf(format, arg);
	printf("END");
	if (res != og)
		printf("\nERROR");
	else
		printf("\nSUCCESS");
	printf("\nog: %d, my: %d\n", og, res);
	return (0);
}
