/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:04:01 by msambo            #+#    #+#             */
/*   Updated: 2018/06/14 14:09:04 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		appended;
	char	*strjoin;
	int		str1;
	int		str2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	appended = str1 + str2;
	strjoin = (char *)malloc(sizeof(strjoin) * (appended + 1));
	if (strjoin == NULL)
		return (NULL);
	ft_strcpy(strjoin, s1);
	ft_strcat(strjoin, s2);
	return (strjoin);
}
