/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:00:59 by msambo            #+#    #+#             */
/*   Updated: 2018/08/25 17:01:04 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
void	ft_tolower(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);

#endif
