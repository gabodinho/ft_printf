/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:26:03 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/24 01:39:58 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int	res;

	res = ft_printf("test\n");
	ft_printf("this is the return value: %d\n", res);
	return (0);
}
