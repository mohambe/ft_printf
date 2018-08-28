/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:20:37 by msambo            #+#    #+#             */
/*   Updated: 2018/08/20 17:26:34 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void		transfer_to_struct(t_info *info, const char *format)
{
	int i;

	i = 0;
	if (!(info->form = (char *)malloc(sizeof(char) * (info->format_len + 1))))
		return ;
	while (format[i] != '\0')
	{
		info->form[i] = format[i];
		i++;
	}
	info->form[i] = '\0';
}

static void		transfer(t_info *info, const char *format, va_list *types)
{
	reset_var(info);
	info->types = types;
	info->format_len = ft_strlen((char*)(format));
	transfer_to_struct(info, format);
	info->res = 0;
	info->index = 0;
}

void			reset_var(t_info *info)
{
	info->has_hash = 0;
	info->has_minus = 0;
	info->zero = 0;
	info->has_plus = 0;
	info->has_space = 0;
	info->num = 0;
}

static	char	flag(char *format, t_info *info)
{
	if (format[info->index] == '-' || format[info->index] == '+'
			|| format[info->index] == '#' || format[info->index] == '0'
			|| format[info->index] == ' ')
	{
		if (format[info->index] == '-')
			info->has_minus = 1;
		else if (format[info->index] == '+')
			info->has_plus = 1;
		else if (format[info->index] == '0')
			info->zero = 1;
		else if (format[info->index] == '#')
			info->has_hash = 1;
		else if (format[info->index] == ' ')
			info->has_space = 1;
	}
	return (format[info->index]);
}

int				ft_printf(const char *format, ...)
{
	int			counter;
	va_list		types;
	t_info		info;

	info.index = 0;
	counter = 0;
	va_start(types, format);
	transfer(&info, format, &types);
	while (format[info.index])
	{
		info.res = 0;
		if (format[info.index] == '%')
		{
			info.index++;
			while (ft_strchr("-+0# ", flag((char*)format, &info)))
				info.index++;
			counter += ft_multi_datatype(&format[info.index], &info);
		}
		else if (format[info.index] != '%')
			counter += ft_print_char(format[info.index]);
		info.index++;
	}
	va_end(types);
	return (counter);
}
