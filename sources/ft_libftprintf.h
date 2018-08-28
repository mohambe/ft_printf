/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:24:47 by msambo            #+#    #+#             */
/*   Updated: 2018/08/25 17:29:51 by msambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../includes/ft_libft.h"
# define LONG_MAX 4294967296
# include <stdio.h>
# define ABS(x) ((x) >= 0 ?(x) :-(x))

typedef struct	s_info
{
	va_list	*types;
	char	*form;
	int		num;
	char	chara;
	char	cs;
	int		index;
	int		res;
	int		has_hash;
	int		has_minus;
	int		has_plus;
	int		has_space;
	int		format_len;
	int		zero;
}				t_info;

int				ft_printf(const char *format, ...);
int				ft_print_str(char const *str);
int				ft_print_char(char c);
int				ps(char const *str);
void			print_dd(t_info *info, int holder, long int nb);
void			more_datatype(char c, t_info *info);
int				ft_print_nbr(long int n);
int				ft_multi_datatype(char const *str, t_info *info);
int				ft_datatype(char c, t_info *info);
int				ft_print_hex(long hex, t_info *info, char c, int w);
int				ft_print_oct(int oct, t_info *info, char c, int w);
int				ft_print_hash(int oct, t_info *info, char c, int w);
int				ft_print_hex_hash(long hex, t_info *info, char c, int w);
int				actual_width(t_info *info, long int nb);
void			reset_var(t_info *info);
void			format_type(t_info *info);
void			is_negative(t_info *info);
void			is_positive(t_info *info);
void			is_space(t_info *info);
void			is_hashtag(t_info *info);
void			apply_str(t_info *info);
void			apply_digits(t_info *info);
void			apply_char(t_info *info);
void			apply_oct(t_info *info);
void			apply_oct_hash(t_info *info);
void			apply_hex(t_info *info);
void			apply_hex_hash(t_info *info);
void			apply_u(t_info *info);
char			*ft_itoa_b(long nbr, int base, int *res, char format);
void			print_digits(t_info *info, int nbr, int holder);
int				ft_digit(int nbr, t_info *info, char c);
void			ft_more_data(char c, t_info *info);
void			apply_percentage(t_info *info);
void			ft_print_unsigned(t_info *info, int holder, long long int nb);
void			apply_unsigned(t_info *info);
void			apply_ld(t_info *info);

#endif
