/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:10:15 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/11 13:17:56 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define PREC (ob->flag.prec)
#define MNS (ob->flag.minus)
#define WGH (ob->flag.weight)
#define OUT (ob->out)
#define NBR nbr < 0

void			print_percent(t_ob *ob)
{
	if (ob->flag.minus)
	{
		ob->ret += write(ob->fd, "%", 1);
		while (--ob->flag.weight > 0)
			ob->ret += write(ob->fd, " ", 1);
	}
	else
	{
		while (--ob->flag.weight > 0)
			ob->ret += (ob->flag.zero) ?
			write(ob->fd, "0", 1) : write(ob->fd, " ", 1);
		ob->ret += write(ob->fd, "%", 1);
	}
	ob->i++;
}

void			print_str(t_ob *ob)
{
	char	*tmp;

	init_str_arg(ob, &tmp);
	OUT = tmp == NULL ? ft_strdup("(null)") : ft_strdup(tmp);
	if (ob->flag.zero && ob->flag.weight > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH -
		(int)ft_strlen(OUT)),
		'0', WGH - (int)ft_strlen(OUT)), OUT);
	if (PREC < (int)ft_strlen(OUT) && ob->flag.dot)
		OUT = ft_free_strncpy(ft_strnew(PREC < 0 ? 0 : PREC), OUT,
			PREC < 0 ? 0 : PREC);
	if (MNS && WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(OUT, ft_memset(ft_strnew(WGH -
			(int)ft_strlen(OUT)), ' ', WGH - (int)ft_strlen(OUT)));
	if (!MNS && WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH -
			(int)ft_strlen(OUT)), ' ', WGH -
			(int)ft_strlen(OUT)), OUT);
	ob->i++;
	ob->ret += write(ob->fd, OUT, (int)ft_strlen(OUT));
	free(OUT);
}

void			print_char(t_ob *ob)
{
	int		c;

	init_char_arg(ob, &c);
	ob->i++;
	if (c == 0)
	{
		while (--WGH > 0)
			ob->ret += write(ob->fd, " ", 1);
		ob->ret += write(ob->fd, "\0", 1);
		return ;
	}
	OUT = ft_memset(ft_strnew(1), c, 1);
	if (ob->flag.zero && WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH -
		(int)ft_strlen(OUT)),
		'0', WGH - (int)ft_strlen(OUT)), OUT);
	if (MNS && WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(OUT, ft_memset(ft_strnew(WGH -
			(int)ft_strlen(OUT)), ' ', WGH - (int)ft_strlen(OUT)));
	if (WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH -
		(int)ft_strlen(OUT)),
			' ', WGH - (int)ft_strlen(OUT)), OUT);
	ob->ret += write(ob->fd, OUT, (int)ft_strlen(OUT));
	free(OUT);
}

static	void	int_next(t_ob *ob, long nbr)
{
	if (ob->type == type_notype)
	{
		OUT = (int)NBR ? ft_itoa(-(int)nbr) : ft_itoa((int)nbr);
		ob->flag.negativ = (int)NBR ? 1 : 0;
	}
	else if (ob->type == type_j || ob->type == type_t || ob->type == type_l ||
		ob->type == type_ll)
	{
		OUT = (long)NBR ? ft_ltoa(-(long)nbr) : ft_ltoa((long)nbr);
		ob->flag.negativ = (long)NBR ? 1 : 0;
	}
}

void			print_int(t_ob *ob, const char *restrict fmt)
{
	long	nbr;

	init_int_arg(ob, &nbr);
	ob->flag.minus ? ob->flag.zero = 0 : 0;
	ob->flag.plus ? ob->flag.space = 0 : 0;
	ob->flag.prec >= 0 ? ob->flag.zero = 0 : 0;
	fmt[ob->i] == 'D' ? ob->type = type_l : 0;
	if (nbr == LLONG_MIN || nbr == LONG_MIN)
		ob->out = ft_strdup("-9223372036854775808");
	else if (ob->type == type_hh)
	{
		OUT = (char)NBR ? ft_itoa(-(char)nbr) : ft_itoa((char)nbr);
		ob->flag.negativ = (char)NBR ? 1 : 0;
	}
	else if (ob->type == type_h)
	{
		OUT = (short)NBR ? ft_itoa(-(short)nbr) : ft_itoa((short)nbr);
		ob->flag.negativ = (short)NBR ? 1 : 0;
	}
	else
		int_next(ob, nbr);
	print_digit(ob);
}
