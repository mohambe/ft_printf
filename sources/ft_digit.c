/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:55:42 by msambo            #+#    #+#             */
/*   Updated: 2018/08/28 10:03:53 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	apply_ld(t_info *info)
{
	intmax_t	nb;
	int			holder;

	info->cs = ' ';
	nb = va_arg(*info->types, intmax_t);
	holder = actual_width(info, nb);
	holder = holder - ft_strlen(ft_itoa(nb));
	if (info->chara == 'D' || info->chara == 'U')
	{
		info->cs = ' ';
		if (info->num > 0 || info->zero == 1 || info->has_space == 1)
		{
			holder = holder - ft_strlen(ft_itoa(nb));
			print_dd(info, holder, nb);
		}
		else if (info->has_plus == 1 || info->has_minus == 1)
		{
			holder = holder - ft_strlen(ft_itoa(nb));
			print_dd(info, holder, nb);
		}
		else
			info->res += ft_print_str(ft_itoa_b(nb, 10,
						&info->res, info->chara));
	}
}
