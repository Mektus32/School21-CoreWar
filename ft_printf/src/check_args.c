/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:37:01 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 14:37:05 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_check_dollar(const char *restrict fmt, t_ob *ob)
{
	int		tmp;

	tmp = ob->i;
	if (ISNUM(fmt[tmp]))
	{
		ob->dollar.num = ft_atoi(fmt + tmp);
		while (ISNUM(fmt[tmp]))
			tmp++;
		if (fmt[tmp] == '$')
		{
			ob->dollar.dollar = 1;
			ob->i = tmp + 1;
		}
	}
}

static	void	ft_get_type(const char *restrict fmt, t_ob *ob)
{
	if (fmt[ob->i] == 'h' && fmt[ob->i + 1] != 'h')
		ob->type = type_h;
	else if (fmt[ob->i] == 'h' && fmt[ob->i + 1] == 'h')
	{
		ob->type = type_hh;
		ob->i++;
	}
	else if (fmt[ob->i] == 'l' && fmt[ob->i + 1] != 'l')
		ob->type = type_l;
	else if (fmt[ob->i] == 'l' && fmt[ob->i + 1] == 'l')
	{
		ob->type = type_ll;
		ob->i++;
	}
	else if (fmt[ob->i] == 'j')
		ob->type = type_j;
	else if (fmt[ob->i] == 'z')
		ob->type = type_j;
	else if (fmt[ob->i] == 't')
		ob->type = type_t;
	else if (fmt[ob->i] == 'L')
		ob->type = type_L;
}

static	void	ft_get_prec(const char *restrict fmt, t_ob *ob)
{
	ob->flag.dot = 1;
	if (ISNUM(fmt[ob->i + 1]))
	{
		ob->i++;
		ob->flag.prec = ft_atoi(fmt + ob->i);
		while (ISNUM(fmt[ob->i]))
			ob->i++;
	}
	else if (fmt[ob->i + 1] == '*')
	{
		ob->flag.prec = va_arg(ob->ap[0], int);
		ob->i += 2;
	}
	else
		ob->i++;
}

static	void	ft_get_weight(t_ob *ob)
{
	ob->flag.weight = va_arg(ob->ap[0], int);
	if (ob->flag.weight < 0)
	{
		ob->flag.weight = -ob->flag.weight;
		ob->flag.minus = 1;
	}
}

void			check_args(const char *restrict fmt, t_ob *ob)
{
	while (ft_strchr(FLAGS, fmt[ob->i]))
	{
		ft_check_dollar(fmt, ob);
		fmt[ob->i] == '-' ? ob->flag.minus = 1 : 0;
		fmt[ob->i] == '+' ? ob->flag.plus = 1 : 0;
		fmt[ob->i] == ' ' ? ob->flag.space = 1 : 0;
		fmt[ob->i] == '#' ? ob->flag.hash = 1 : 0;
		fmt[ob->i] == '0' ? ob->flag.zero = 1 : 0;
		fmt[ob->i] == 39 ? ob->flag.quote = 1 : 0;
		fmt[ob->i] == '*' ? ft_get_weight(ob) : 0;
		fmt[ob->i] >= 'L' && fmt[ob->i] <= 'z' ? ft_get_type(fmt, ob) : 0;
		if (fmt[ob->i] == '.')
			ft_get_prec(fmt, ob);
		else if (ISNUM(fmt[ob->i]))
		{
			ob->flag.weight = ft_atoi(fmt + ob->i);
			while (ISNUM(fmt[ob->i]))
				ob->i++;
		}
		else
			ob->i++;
	}
}
