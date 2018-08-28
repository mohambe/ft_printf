/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_hex_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:22:13 by msambo            #+#    #+#             */
/*   Updated: 2018/08/26 12:25:47 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static	void	zero_hex(t_info *info, char *s, int holder)
{
	if (info->zero)
	{
		info->res += (info->chara == 'X') ? ps("0X") : ps("0x");
		while (holder-- > 0)
			info->res += ft_print_char(info->cs);
		ft_print_str(s);
	}
	else
	{
		while (holder-- > 0)
			info->res += ft_print_char(info->cs);
		info->res += (info->chara == 'X') ? ps("0X") : ps("0x");
		ft_print_str(s);
	}
}

int				ft_print_hex_hash(long hex, t_info *info, char c, int w)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa_b(hex, 16, &info->res, c);
	w = w - (ft_strlen(str));
	if (info->zero == 1 && info->has_minus == 1)
		info->cs = ' ';
	else if (info->zero == 1)
		info->cs = '0';
	if (info->has_minus == 1 && hex > 0)
	{
		info->res += (info->chara == 'X') ? ps("0X") : ps("0x");
		ft_print_str(str);
		while (w-- > 0)
			info->res += ft_print_char(info->cs);
	}
	else
	{
		zero_hex(info, str, w);
	}
	return (len += (ft_strlen(str) + 2));
}

void			apply_hex_hash(t_info *info)
{
	long	nb;
	int		holder;

	nb = va_arg(*info->types, long);
	holder = 0;
	if (nb == 0)
		info->res += ft_print_char('0');
	else
	{
		if (info->num > 0 || info->zero == 1 || info->has_space == 1)
		{
			holder = actual_width(info, nb);
			holder = holder - ft_strlen(ft_itoa(nb));
			ft_print_hex_hash(nb, info, info->chara, holder);
		}
		else if (info->has_plus == 1 || info->has_minus == 1)
		{
			holder = actual_width(info, nb);
			holder = holder - ft_strlen(ft_itoa(nb));
			ft_print_hex_hash(nb, info, info->chara, holder);
		}
		else
			ft_print_hex_hash(nb, info, info->chara, holder);
	}
}
