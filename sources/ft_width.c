/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 07:42:33 by msambo            #+#    #+#             */
/*   Updated: 2018/08/20 16:47:08 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static int	width_digit(t_info *info, int holder, int i)
{
	while (info->form[i] != '\0' && holder == 0 && info->form[i] != '.')
	{
		if (info->form[i] >= '0' && info->form[i] <= '9')
		{
			if (info->zero == 1 && info->has_minus == 1)
				info->cs = ' ';
			else
				holder++;
			while (info->form[i + holder] >= '0' &&
					info->form[i + holder] <= '9')
			{
				holder++;
			}
		}
		i++;
	}
	return (holder);
}

static int	width_placing(t_info *info, int holder, int i, char *str)
{
	while (info->form[i] != '\0' && holder == 0 && info->form[i] != '.')
	{
		if (info->form[i] >= '1' && info->form[i] <= '9')
		{
			str[holder] = info->form[i];
			holder++;
			i++;
			while (info->form[i] >= '0' && info->form[i] <= '9')
			{
				str[holder] = info->form[i];
				holder++;
				i++;
			}
		}
		i++;
	}
	str[holder] = '\0';
	holder = ft_atoi(str);
	return (holder);
}

int			actual_width(t_info *info, long int nb)
{
	int		i;
	int		holder;
	char	*str;

	i = 0;
	holder = 0;
	info->cs = ' ';
	is_positive(info);
	if (nb < 0)
		info->has_plus = 0;
	is_negative(info);
	holder = width_digit(info, holder, i);
	str = ft_strnew(holder);
	i = 0;
	holder = 0;
	holder = width_placing(info, holder, i, str);
	return (holder);
}
