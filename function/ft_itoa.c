/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:35:25 by msambo            #+#    #+#             */
/*   Updated: 2018/08/28 10:06:02 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_libft.h"

static size_t	get_len(intmax_t n)
{
	int			i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = n * -1;
		i++;
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	else if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char			*ft_itoa(intmax_t n)
{
	char		*res;
	int			n_len;
	int			hold;
	intmax_t	l;

	l = n;
	hold = 0;
	res = NULL;
	n_len = get_len(l);
	if (!(res = (char *)malloc(sizeof(char) * (n_len + 1))))
		return (NULL);
	res[n_len--] = '\0';
	if (l < 0)
	{
		hold = 1;
		res[0] = '-';
		l *= -1;
	}
	while (n_len >= hold)
	{
		res[n_len--] = (l % 10) + '0';
		l /= 10;
	}
	return (res);
}
