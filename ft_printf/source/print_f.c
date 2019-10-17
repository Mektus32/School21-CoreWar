/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:23:31 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/08 20:23:33 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*fstr_0(t_print *pr)
{
	char		*str_0;

	str_0 = ft_strnew((*pr).prec + 1);
	if ((*pr).prec > 0)
	{
		ft_memset(str_0, '0', (*pr).prec + 1);
		ft_memset(str_0, '.', 1);
	}
	return (str_0);
}

static void		ft_prec_0(char *str_0, int prec, t_print *pr, int num_i)
{
	if (ft_size_int_lu(num_i) > prec)
	{
		ft_memset(str_0, '0', prec);
		str_0[prec] = '\0';
		if ((*pr).pr_5 == 1)
			(*pr).pr_4erez_0 = 1;
	}
	else
		(*pr).pr_4erez_0 = 0;
}

static char		*ft_dtoa(double num, t_print *pr)
{
	long long	num_i;
	char		*str_0;
	char		*str;
	int			prec;

	(*pr).prec = ((*pr).prec_p == 0 ? 6 : (*pr).prec);
	prec = (*pr).prec;
	if (num == 0)
		return (fstr_0(pr));
	else
	{
		while ((*pr).prec > 0)
		{
			num *= 10;
			(*pr).prec--;
		}
		num_i = num + 0.5;
		str_0 = ft_itoa_lu(num_i);
		if (str_0[0] >= '5')
			(*pr).pr_5 = 1;
	}
	ft_prec_0(str_0, prec, pr, num_i);
	str = (str_0[0] == '\0') ? ft_strdup("\0") : ft_strjoin(".", str_0);
	free(str_0);
	return (str);
}

static char		*ft_strjoin_new(char *s1, char *s2)
{
	char		*new;
	int			i;
	int			len1;

	if (!s1 || !s2)
		return (NULL);
	new = NULL;
	new = (char*)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	len1 = i;
	i = 0;
	while (s2[i])
	{
		new[len1 + i] = s2[i];
		i++;
	}
	free(s1);
	free(s2);
	return (new);
}

const char		*ft_print_f(const char *format, va_list ap, t_print *pr)
{
	double		num;
	char		*str;
	char		*str_2;
	long long	str_i;

	num = (double)va_arg(ap, double);
	if (num < 0)
	{
		(*pr).leftzero = 1;
		num = -num;
	}
	str_i = num;
	num = num - str_i;
	str_2 = ft_dtoa(num, pr);
	if ((*pr).pr_4erez_0 == 1 && str_i % 2 == 1)
		str_i += 1;
	str = ft_itoa_lu(str_i);
	str = ft_strjoin_new(str, str_2);
	ft_print_num(str, pr);
	free(str);
	return (format);
}
