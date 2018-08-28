/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:48:58 by msambo            #+#    #+#             */
/*   Updated: 2018/08/26 12:24:41 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_print_oct(int oct, t_info *info, char c, int w)
{
	char	*str;
	int		len;
	char	z;

	str = ft_itoa_b(oct, 8, &info->res, c);
	len = 0;
	w = w - ft_strlen(str);
	z = ' ';
	if (info->zero == 1 && info->has_minus == 1)
		z = ' ';
	else if (info->zero == 1)
		z = '0';
	if (info->has_minus == 1)
	{
		ft_print_str(str);
		while (w-- > 0)
			info->res += ft_print_char(z);
	}
	else
	{
		while (w-- > 0)
			info->res += ft_print_char(z);
		ft_print_str(str);
	}
	return (len = ft_strlen(str));
}

void	apply_oct(t_info *info)
{
	int nb;
	int holder;

	nb = va_arg(*info->types, int);
	holder = 0;
	if (info->chara == 'o' || info->chara == 'O')
	{
		if (info->num > 0 || info->zero == 1 || info->has_space == 1)
		{
			holder = actual_width(info, nb);
			holder = holder - ft_strlen(ft_itoa(nb));
			ft_print_oct(nb, info, info->chara, holder);
		}
		else if (info->has_plus == 1 || info->has_minus == 1)
		{
			holder = actual_width(info, nb);
			holder = holder - ft_strlen(ft_itoa(nb));
			ft_print_oct(nb, info, info->chara, holder);
		}
		else
			ft_print_oct(nb, info, info->chara, holder);
	}
}
