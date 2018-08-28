/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:13:09 by msambo            #+#    #+#             */
/*   Updated: 2018/05/31 15:18:10 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = malloc(size + 1);
	if (s == '\0')
		return (NULL);
	else
		ft_bzero(s, size + 1);
	return (s);
}
