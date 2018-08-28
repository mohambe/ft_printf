/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:28:42 by msambo            #+#    #+#             */
/*   Updated: 2018/08/20 18:03:57 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*ft_itoa(intmax_t n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
void	ft_tolower(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
int		ft_isdigit(char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s1, const char *s2);
void	ft_strdel(char **as);
void	ft_memdel(void **ap);
char	*ft_strdup(const char *src);

#endif
