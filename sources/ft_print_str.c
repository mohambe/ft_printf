/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:42:38 by msambo            #+#    #+#             */
/*   Updated: 2018/08/21 18:35:58 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_print_str(char const *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	return (i);
}

void	apply_str(t_info *info)
{
	char	*str;
	int		holder;

	info->cs = ' ';
	holder = 0;
	str = va_arg(*info->types, char*);
	if (!str)
		str = "(null)";
	if (info->num > 0)
		holder = actual_width(info, 1);
	holder = (holder - ft_strlen(str));
	if (info->zero == 1 && info->has_minus == 1)
		info->cs = ' ';
	if (info->has_minus == 1)
	{
		info->res += ft_print_str(str);
		while (holder-- > 0)
			info->res += ft_print_char(info->cs);
	}
	else
	{
		while (holder-- > 0)
			info->res += ft_print_char(info->cs);
		info->res += ft_print_str(str);
	}
}
