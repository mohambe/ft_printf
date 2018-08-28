/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:34:18 by msambo            #+#    #+#             */
/*   Updated: 2018/08/22 15:32:02 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	apply_percentage(t_info *info)
{
	int holder;

	if (info->num != 0)
	{
		holder = info->num;
		holder = holder - 1;
		if (info->has_minus == 1)
		{
			info->res += write(1, "%", 1);
			while (holder-- > 0)
				info->res += write(1, " ", 1);
		}
		else
		{
			while (holder-- > 0)
				info->res += write(1, " ", 1);
			info->res += write(1, "%", 1);
		}
	}
	else
	{
		info->res += write(1, "%", 1);
	}
}
