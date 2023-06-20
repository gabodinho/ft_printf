/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fcns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:06:13 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/20 21:09:38 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *str, ...)
{
	int	nargs;
	va_list ap;
	void *ival;
	nargs = ft_getnargs(str);
	va_start(ap, str)
	while (*str)
	{
		ival = get_value(
