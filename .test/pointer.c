/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:25:53 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/24 19:34:05 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	my_func(char **ptr)
{
	while (**ptr == '1')
		*ptr++;
	return ;
}

int main(void)
{
	char str[] = "11111test";
	char *ptr = str;
	my_func(&ptr);
	printf("result: %s", ptr);
	return (0);
}
