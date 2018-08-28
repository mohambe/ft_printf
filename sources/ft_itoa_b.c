/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:58:35 by msambo            #+#    #+#             */
/*   Updated: 2018/08/21 17:01:11 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static char		*mk_str(char *str, int pos, intmax_t nbr, int base)
{
	while (pos--)
	{
		str[pos] = (nbr % base) + '0';
		nbr /= base;
		if (str[pos] > '9')
			str[pos] += 7;
	}
	return (str);
}

static void		mkneg(intmax_t *nbr, int *negator, int base)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		if (base != 10)
			*nbr = (LONG_MAX) - *nbr;
		else if (base == 10)
			*negator = 1;
	}
}

char			*ft_itoa_b(intmax_t nbr, int base, int *res, char format)
{
	intmax_t	temp;
	int			negator;
	int			pos;
	char		*str;

	temp = nbr;
	if (base < 2 || base > 16)
		return (NULL);
	str = NULL;
	pos = 2;
	negator = 0;
	mkneg(&nbr, &negator, base);
	temp = nbr;
	while (temp /= base)
		pos++;
	pos += negator;
	*res = pos - 1;
	if (!(str = ft_strnew(pos - 1)))
		return (NULL);
	str[--pos] = '\0';
	str = mk_str(str, pos, nbr, base);
	(negator && base == 10) ? str[0] = '-' : 0;
	(format == 'x' || format == 'p') ? ft_tolower(str) : 0;
	(format == 'p') ? str = ft_strjoin("0x", str) : 0;
	return (str);
}
