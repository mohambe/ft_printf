/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_number1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:27:20 by msambo            #+#    #+#             */
/*   Updated: 2018/08/26 12:27:24 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		print_plus_zero(t_info *info, int holder, intmax_t nb)
{
	if (info->has_plus == 1 && nb >= 0)
		info->res += write(1, "+", 1);
	else if (nb < 0 && info->has_plus == 1)
	{
		info->res += write(1, "-", 1);
		nb = -nb;
	}
	if (info->zero == 1 && nb < 0 && info->has_plus == 1)
	{
		info->res += write(1, "-", 1);
		nb = -nb;
	}
	if (info->num > 0)
	{
		while (holder > 0)
		{
			info->res += write(1, "0", 1);
			holder--;
		}
	}
	ft_print_nbr(nb);
	info->res += (ft_strlen(ft_itoa(nb)));
}

static void		plus_digit(t_info *info, int holder, intmax_t nb)
{
	if (info->has_space == 1 && nb > -1 && info->has_plus != 1)
	{
		info->res += write(1, " ", 1);
		holder--;
	}
	if (info->num > 0)
	{
		while (holder > 0)
		{
			info->res += ft_print_char(info->cs);
			holder--;
		}
	}
	if (info->has_plus == 1 && nb >= 0)
		info->res += write(1, "+", 1);
	if (nb < 0 && info->has_plus == 1)
	{
		info->res += write(1, "-", 1);
		nb = -nb;
	}
	ft_print_nbr(nb);
	info->res += (ft_strlen(ft_itoa(nb)));
}

static void		plus_minus_digit(t_info *info, int holder, long int nb)
{
	if (info->has_minus == 1)
	{
		if (info->has_plus == 1 && nb >= 0)
			info->res += write(1, "+", 1);
		if (nb < 0 && info->has_plus == 1)
		{
			info->res += write(1, "-", 1);
			nb = -nb;
		}
		ft_print_nbr(nb);
		info->res += (ft_strlen(ft_itoa(nb)));
		while (holder-- > 0)
			info->res += ft_print_char(info->cs);
	}
	else
		plus_digit(info, holder, nb);
}

void			print_dd(t_info *info, int holder, intmax_t nb)
{
	if (info->has_plus == 1)
		holder--;
	if (info->zero == 1)
		info->cs = '0';
	(info->zero == 1) ? info->cs = '0' : info->cs == ' ';
	if (info->cs == '0' && info->zero == 1)
		print_plus_zero(info, holder, nb);
	else
		plus_minus_digit(info, holder, nb);
}
