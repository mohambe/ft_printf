/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:40:11 by msambo            #+#    #+#             */
/*   Updated: 2018/08/22 07:25:12 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

void	apply_char(t_info *info)
{
	int		c;
	int		holder;
	char	x;

	x = ' ';
	c = va_arg(*info->types, int);
	holder = actual_width(info, 1);
	holder = (holder - 1);
	if (info->zero == 1 && info->has_minus)
		x = ' ';
	if (info->zero == 1)
		x = '0';
	if (info->has_minus == 1)
	{
		info->res += write(1, &c, 1);
		while (holder-- > 0)
			info->res += write(1, &x, 1);
	}
	else
	{
		while (holder-- > 0)
			info->res += write(1, &x, 1);
		info->res += write(1, &c, 1);
	}
}
