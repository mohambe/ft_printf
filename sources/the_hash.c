/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:13:35 by msambo            #+#    #+#             */
/*   Updated: 2018/08/28 10:03:22 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_print_hash(int oct, t_info *info, char c, int w)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa_b(oct, 8, &info->res, c);
	w = w - (ft_strlen(str) + 1);
	if (info->zero == 1 && info->has_minus == 1)
		info->cs = ' ';
	else if (info->zero == 1)
		info->cs = '0';
	if (info->has_hash == 1)
	{
		while (w-- > 0)
			info->res += ft_print_char(info->cs);
		info->res += ft_print_char('0');
		ft_print_str(str);
	}
	else if (info->has_minus == 1)
	{
		ft_print_char(info->cs);
		ft_print_str(str);
		while (w-- > 0)
			info->res += ft_print_char(info->cs);
	}
	return (len = ft_strlen(str) + 1);
}

void	apply_oct_hash(t_info *info)
{
	int nb;
	int holder;

	nb = va_arg(*info->types, int);
	holder = info->num;
	if (nb == 0)
		info->res += ft_print_char('0');
	else
		ft_print_hash(nb, info, info->chara, holder);
}
