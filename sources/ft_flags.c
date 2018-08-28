/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:59:17 by msambo            #+#    #+#             */
/*   Updated: 2018/08/20 16:08:33 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	is_negative(t_info *info)
{
	int i;

	i = 0;
	info->has_minus = 0;
	while (info->form[i] != '\0')
	{
		if (info->form[i] == '-')
			info->has_minus = 1;
		i++;
	}
}

void	is_positive(t_info *info)
{
	int i;

	i = 0;
	info->has_plus = 0;
	while (info->form[i] != '\0')
	{
		if (info->form[i] == '+')
			info->has_plus = 1;
		i++;
	}
}

void	is_spac(t_info *info)
{
	int i;

	i = 0;
	info->has_space = 0;
	while (info->form[i] != '\0')
	{
		if (info->form[i] == ' ')
			info->has_space = 1;
		i++;
	}
}
