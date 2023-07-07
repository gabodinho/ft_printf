/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pass_valist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:12:26 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/07/07 19:16:44 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void valist(const char* str, ...)
{
	va_list args;
	va_start(args, str);
	ft_printf(str, args);
	return ;
}

int main(void)
{
	valist("print this %s\n", "please");
	return (0);
}
