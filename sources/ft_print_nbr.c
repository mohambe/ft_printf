/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:12:08 by msambo            #+#    #+#             */
/*   Updated: 2018/08/28 10:02:34 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_print_nbr(intmax_t n)
{
	char		c;
	static int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = ft_print_str("-2147483648");
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_print_nbr(-n);
	}
	else if (n >= 10)
	{
		ft_print_nbr(n / 10);
		c = n % 10 + '0';
		ft_print_char(c);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
	return (ft_strlen(ft_itoa(n)));
}

void	apply_digits(t_info *info)
{
	intmax_t	nb;
	int			holder;

	nb = va_arg(*info->types, int);
	holder = info->num;
	if (info->chara == 'd' || info->chara == 'i')
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
			info->res += ft_print_nbr(nb);
	}
}
