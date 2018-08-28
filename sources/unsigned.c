/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:12:18 by msambo            #+#    #+#             */
/*   Updated: 2018/08/28 10:04:09 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static	void	print_u1(t_info *info, int holder, long long int nb)
{
	char c;
	char *str;

	c = 'u';
	str = NULL;
	if (info->has_hash == 1)
		info->res += write(1, "0", 2);
	while (holder > 0)
	{
		info->res += write(1, "0", 1);
		holder--;
	}
	ft_itoa_b(nb, 10, &info->res, c);
	ft_print_str(str);
	free(str);
}

void			apply_unsigned(t_info *info)
{
	int			holder;
	uintmax_t	nb;

	nb = va_arg(*info->types, uintmax_t);
	holder = actual_width(info, nb);
	ft_print_unsigned(info, holder, nb);
}

void			ft_print_unsigned(t_info *info, int holder, long long int nb)
{
	char	c;
	char	*str;

	c = 'u';
	str = ft_itoa_b(nb, 10, &info->res, c);
	if (nb < 0)
	{
		ft_strdel(&str);
		str = ft_strdup("4294967295");
	}
	if (info->cs == 0)
		print_u1(info, holder, nb);
	else
		ft_print_str(str);
	free(str);
}
