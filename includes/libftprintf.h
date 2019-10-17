/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:08:36 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/29 16:46:37 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define MIN_LL -9223372036854775807
# define MIN_INT -2147483648
# define F format

typedef struct	s_len
{
	int			len_str;
	int			l;
	int			len_z;
	int			len_0;
}				t_len;

typedef struct	s_print
{
	int			len;
	int			width;
	int			rr : 2;
	int			space : 2;
	int			plus : 2;
	int			minus : 2;
	int			zero : 2;
	int			prec;
	int			prec_p : 2;
	int			mod : 4;
	int			net : 2;
	int			leftzero : 2;
	int			format : 5;
	int			pr_x : 2;
	int			pr_0 : 2;
	int			pr_4erez_0 : 2;
	int			pr_5 : 2;
}				t_print;

const char		*ft_format(const char *format, va_list ap, t_print *pr);

int				ft_str_format(t_print *pr, char *st_cat);
void			num_set(t_print *pr, t_len *len_l, char *st_cat, char *str);

int				ft_printf(const char *format, ...);
int				ft_strlen_num(int num);
char			*ft_itoa_ll(unsigned long long int n);
char			*ft_itoa_lu(unsigned long long int n);
char			*ft_int_base(unsigned long long one, int base);

const char		*ft_flag_check(const char *format, t_print *pr);
const char		*ft_width_check(const char *format, t_print *pr, va_list ap);
const char		*ft_precision_check(const char *format, t_print *pr,
	va_list ap);
const char		*ft_mod_check(const char *format, t_print *pr);
const char		*ft_format_check(const char *format, t_print *pr);

char			*ft_print_str2(int len_str, t_print *pr);
const char		*ft_print_str(const char *format, char *str, t_print *pr);

const char		*ft_print_d(const char *format, va_list ap, t_print *pr);
const char		*ft_print_c(const char *format, va_list ap, t_print *pr);
const char		*ft_print_u(const char *format, va_list ap, t_print *pr);
void			ft_print_o(const char *format, va_list ap, t_print *pr);
const char		*ft_print_x(const char *format, va_list ap, t_print *pr);

void			ft_print_num(char *str, t_print *pr);
const char		*ft_print_f(const char *format, va_list ap, t_print *pr);

int				ft_size_int_lu(unsigned long long n);
#endif
