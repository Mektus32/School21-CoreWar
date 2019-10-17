/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:21:21 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/29 16:32:38 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_str_2(char *str2, int len_str, t_print *pr)
{
	if (((*pr).width && len_str <= (*pr).width) ||
		(((*pr).prec < (*pr).width) && (*pr).prec_p))
	{
		str2 = ft_strnew((*pr).width + 1);
		ft_memset(str2, ' ', (*pr).width);
	}
	else if ((*pr).prec_p && (*pr).prec <= len_str)
	{
		str2 = ft_strnew((*pr).prec + 1);
		ft_memset(str2, ' ', (*pr).prec);
	}
	else if ((*pr).format == 9 && (*pr).prec_p && (*pr).prec > 0)
	{
		str2 = ft_strnew((*pr).prec + 1);
		ft_memset(str2, ' ', (*pr).prec);
	}
	else
	{
		str2 = ft_strnew(len_str + 1);
		ft_memset(str2, ' ', len_str);
	}
	return (str2);
}

static char	*ft_st_cat(t_print *pr, char *str, char *str2)
{
	char	*st_cat;

	st_cat = NULL;
	if (ft_strncmp(str, "0x", 2) == 0)
	{
		st_cat = ft_strjoin(str, str2);
	}
	else if ((*pr).prec_p && ((*pr).prec >= 0) && ft_strncmp(str, "%", 1))
	{
		st_cat = ft_strnew((*pr).prec);
		st_cat = ft_strncat(st_cat, str, (*pr).prec);
	}
	else
		st_cat = ft_strdup(str);
	return (st_cat);
}

char		*ft_print_str2(int len_str, t_print *pr)
{
	char	*str2;

	str2 = NULL;
	str2 = ft_str_2(str2, len_str, pr);
	if ((*pr).zero)
		ft_memset(str2, '0', (*pr).width);
	if ((*pr).format == 9 && (*pr).prec_p && (*pr).prec > 0)
		ft_memset(str2, '0', (*pr).prec);
	return (str2);
}

static char	*ft_print_str3(int len_str, char *str, t_print *pr)
{
	char	*st_cat;
	char	*str2;

	str2 = ft_print_str2(len_str, pr);
	st_cat = ft_st_cat(pr, str, str2);
	if ((*pr).minus)
		ft_memcpy(str2, st_cat, ft_strlen(st_cat));
	else
	{
		if (ft_strncmp(str, "0x", 2))
		{
			len_str = ft_strlen(str2) == 0 ? 0 :
			ft_strlen(str2) - ft_strlen(st_cat);
			ft_memcpy(str2 + len_str, st_cat, ft_strlen(st_cat));
		}
		else
		{
			if (str2)
				free(str2);
			str2 = ft_strdup(st_cat);
		}
	}
	free(st_cat);
	return (str2);
}

const char	*ft_print_str(const char *format, char *str, t_print *pr)
{
	char	*str2;
	int		len_str;

	if ((!str || str == NULL))
		str = ft_strdup("(null)");
	else if ((*pr).format == 9 && str[0] == '0')
		str = ft_strdup("0x");
	else if (str[0] == '%')
		str = ft_strdup("%");
	else
		str = ft_strdup(str);
	len_str = ft_strlen(str);
	str2 = ft_print_str3(len_str, str, pr);
	ft_putstr(str2);
	(*pr).len += ft_strlen(str2);
	free(str2);
	free(str);
	return (format);
}
