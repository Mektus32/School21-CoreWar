/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:58:36 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/11 13:13:40 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	prec_width(t_ob *ob)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(ob->out) + ob->flag.plus + ob->flag.space;
	if (ob->flag.prec >= 0)
	{
		while (ob->flag.weight - ++i > len)
			ob->ret += ob->flag.zero ? write(ob->fd, "0", 1) :
			write(ob->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(ob->out) < len - ++i)
			ob->ret += write(ob->fd, "0", 1);
	}
	else
		while (ob->flag.weight - ++i > len)
			ob->ret += ob->flag.zero == 1 ? write(ob->fd, "0", 1) :
			write(ob->fd, " ", 1);
}

static	char	*get_prec(char *str, int dot, int end, int hash)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = ft_strnew(ft_strlen(str) + 1);
	while (str[++i] != '\0')
	{
		tmp[j++] = str[i];
		if ((i == dot - 1 && end > 0) || hash == 1)
		{
			tmp[j++] = '.';
			hash = 0;
		}
		if (i >= end)
		{
			tmp[j] = '\0';
			break ;
		}
	}
	return (tmp);
}

static	long	get_num(long double nbr, int prec)
{
	int		neg;
	int		i;

	i = -1;
	neg = nbr < 0 ? -1 : 1;
	nbr *= neg;
	while (++i < prec)
		nbr *= 10;
	nbr += 0.5;
	nbr *= neg;
	return ((long)nbr);
}

static	void	ftoa_f(t_ob *ob, long double nbr)
{
	char	*tmp;
	char	*nb;
	long	num;
	int		prec;

	tmp = ft_ltoa((long)nbr);
	nbr == 0 ? --ob->flag.prec : 0;
	prec = ft_strlen(tmp);
	num = get_num(nbr, ob->flag.prec >= 0 ? ob->flag.prec : 6);
	nb = num == 0 ? ft_strdup("0000000") : ft_ftoa(num);
	if (ob->flag.prec == 0)
		ob->out = ft_strdup(tmp);
	else
		ob->out = get_prec(nb, prec, ob->flag.prec >= 0 ?
		prec + ob->flag.prec : prec + 6, ob->flag.hash);
	free(nb);
	free(tmp);
}

void			print_double(t_ob *ob)
{
	long double		nbr;
	double			d;

	ob->type == type_L ? init_long_double_arg(ob, &nbr) :
	init_double_arg(ob, &d);
	nbr = ob->type == type_L ? nbr : (long double)d;
	ftoa_f(ob, nbr);
	if (ob->flag.minus)
	{
		if (nbr > 0 && (ob->flag.plus || ob->flag.space))
			ob->ret += ob->flag.plus == 1 ? write(ob->fd, "+", 1) :
			write(ob->fd, " ", 1);
		ob->ret += write(ob->fd, ob->out, ft_strlen(ob->out));
		prec_width(ob);
	}
	else
	{
		prec_width(ob);
		if (nbr > 0 && (ob->flag.plus || ob->flag.space))
			ob->ret += (ob->flag.plus == 1 ?
			write(ob->fd, "+", 1) : write(ob->fd, " ", 1));
		ob->ret += write(ob->fd, ob->out, ft_strlen(ob->out));
	}
	++ob->i;
	free(ob->out);
}
