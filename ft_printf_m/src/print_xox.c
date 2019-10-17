/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:12:54 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/11 13:17:19 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define PREC (ob->flag.prec)
#define MNS (ob->flag.minus)
#define WGH (ob->flag.weight)
#define OUT (ob->out)

static	void	xox_next(t_ob *ob, char c, long nbr)
{
	if (ob->flag.hash && nbr)
	{
		OUT = ft_free_strjoin_duo(c == 'x' || c == 'X' ? ft_strdup("0X") :
			ft_strdup("0"), OUT);
		WGH += (c == 'x' || c == 'X') ? 2 : 1;
	}
	if (WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH -
		(int)ft_strlen(OUT)),
		' ', WGH - (int)ft_strlen(OUT)), OUT);
	if (c == 'x' || c == 'o')
		OUT = ft_strtolower(OUT);
	ob->i++;
	ob->ret += write(ob->fd, OUT, (int)ft_strlen(OUT));
}

void			print_xox(t_ob *ob, char c, long nbr)
{
	if (ob->flag.dot && !nbr)
	{
		if ((c == 'o' || c == 'O') && ob->flag.hash)
			c += 0;
		else
		{
			free(ob->out);
			ob->out = ft_strdup("");
		}
	}
	if (ob->flag.hash)
		WGH += (c == 'x' || c == 'X') ? -2 : -1;
	if (ob->flag.dot && PREC > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(PREC -
		(int)ft_strlen(OUT)),
		'0', PREC - (int)ft_strlen(OUT)), OUT);
	if (ob->flag.zero && WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(ft_memset(ft_strnew(WGH -
		(int)ft_strlen(OUT)),
		'0', WGH - (int)ft_strlen(OUT)), OUT);
	if (MNS && WGH > (int)ft_strlen(OUT))
		OUT = ft_free_strjoin_duo(OUT, ft_memset(ft_strnew(WGH -
		(int)ft_strlen(OUT)), ' ', WGH - (int)ft_strlen(OUT)));
	xox_next(ob, c, nbr);
	free(ob->out);
}
