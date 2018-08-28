/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_datatype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:14:16 by msambo            #+#    #+#             */
/*   Updated: 2018/08/27 16:53:52 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_multi_datatype(char const *str, t_info *info)
{
	int len;
	int store;

	store = 0;
	len = 0;
	if (ft_isdigit(str[len]))
	{
		while (ft_isdigit(str[len]))
		{
			info->num = ft_atoi(str);
			len++;
			info->index++;
		}
		store += ft_datatype(str[len], info);
	}
	else if (str[len] == '%')
		store += ft_print_char('%');
	else
	{
		if (ft_strchr("spdDioOuUxXcChl", str[len]))
		{
			store += ft_datatype(str[len], info);
		}
	}
	return (store);
}
