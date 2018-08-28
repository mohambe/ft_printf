/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:32:02 by msambo            #+#    #+#             */
/*   Updated: 2018/08/26 12:28:37 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_print_hex(long hex, t_info *info, char c, int w)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa_b(hex, 16, &info->res, c);
	w = w - ft_strlen(str);
	info->cs = ' ';
	if (info->zero == 1)
		info->cs = '0';
	if (info->has_minus == 1)
	{
		ft_print_str(str);
		while (w-- > 0)
			info->res += ft_print_char(info->cs);
	}
	else
	{
		while (w-- > 0)
			info->res += ft_print_char(info->cs);
		ft_print_str(str);
	}
	if (info->chara == 'p')
		info->res += 2;
	return (len = (ft_strlen(str) + info->res));
}

void	apply_hex(t_info *info)
{
	long	nb;
	int		holder;

	nb = va_arg(*info->types, long);
	holder = 0;
	if (info->chara == 'x' || info->chara == 'X' || info->chara == 'p')
	{
		if (info->num > 0 || info->zero == 1 || info->has_space == 1)
		{
			holder = actual_width(info, nb);
			holder = holder - ft_strlen(ft_itoa(nb));
			ft_print_hex(nb, info, info->chara, holder);
		}
		else if (info->has_plus == 1 || info->has_minus == 1)
		{
			holder = actual_width(info, nb);
			holder = holder - ft_strlen(ft_itoa(nb));
			ft_print_hex(nb, info, info->chara, holder);
		}
		else
			ft_print_hex(nb, info, info->chara, holder);
	}
}
