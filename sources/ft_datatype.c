/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datatype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:02:21 by msambo            #+#    #+#             */
/*   Updated: 2018/08/21 17:00:21 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_datatype(char c, t_info *info)
{
	info->chara = c;
	if (c == 'c' || c == 'C')
		apply_char(info);
	else if (c == 's')
		apply_str(info);
	else if (c == 'i' || c == 'd')
		apply_digits(info);
	else if (c == 'X' || c == 'x' || c == 'p')
	{
		if (info->has_hash == 1)
			apply_hex_hash(info);
		else
		{
			if (c == 'p')
				info->res += 2;
			apply_hex(info);
		}
	}
	else
		more_datatype(c, info);
	return (info->res);
}

void	more_datatype(char c, t_info *info)
{
	if (c == 'o' || c == 'O')
	{
		if (info->has_hash == 1)
			apply_oct_hash(info);
		else
			apply_oct(info);
	}
	else if (c == 'u')
		apply_unsigned(info);
	else if (c == '%')
		apply_percentage(info);
	else if (c == 'D' || c == 'U')
		apply_ld(info);
	return ;
}
