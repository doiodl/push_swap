/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:52:11 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 20:47:03 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	new2alg_d4(t_num *tmp, t_num *fm, t_help *hh, int *midl)
{
	while (fm)
	{
		if (fm->num > tmp->num && (!(hh->max_div) ||
			hh->max_div > fm->num - tmp->num))
		{
			hh->max_div = fm->num - tmp->num;
			hh->ta = (fm->pos < midl[3] - fm->pos) ?
				-(fm->pos) : (midl[3] - fm->pos);
		}
		fm = fm->next;
	}
}

void	new2alg_d(t_num **a, t_num **b, t_help *hh, int l)
{
	t_num	*tmp;
	int		midl[4];
	t_num	*fm;

	l = 0;
	new2alg_d3(a, b, hh, midl);
	tmp = *b;
	hh->max_div = 0;
	while (tmp)
	{
		hh->tb = ((tmp->pos >= midl[0]) ? (midl[2] - tmp->pos) : (-tmp->pos));
		fm = *a;
		hh->ta = 0;
		new2alg_d4(tmp, fm, hh, midl);
		helpalg(hh, &l, tmp->num);
		hh->max_div = 0;
		tmp = tmp->next;
	}
}

void	hhelp3(t_num **a, t_num **b, t_help *hh)
{
	if (hh->fa < 0)
	{
		while (hh->fa++ < 0)
			do_ch(a, b, "ra", hh->col);
	}
	else
	{
		while ((hh->fa)-- > 0)
			do_ch(a, b, "rra", hh->col);
	}
	if (hh->fb < 0)
	{
		while ((hh->fb)++ < 0)
			do_ch(a, b, "rb", hh->col);
	}
	else
	{
		while ((hh->fb)-- > 0)
			do_ch(a, b, "rrb", hh->col);
	}
}

void	new2algmain2(t_num **a, t_num **b, t_help *hh)
{
	int		i;
	int		m;

	if (hh->fa > 0 && hh->fb > 0)
	{
		i = -1;
		m = min(hh->fa, hh->fb);
		while (++i < m)
		{
			do_ch(a, b, "rrr", hh->col);
			--(hh->fa);
			--(hh->fb);
		}
	}
	else if (hh->fa < 0 && hh->fb < 0)
	{
		m = max(hh->fa, hh->fb);
		while (m++ < 0)
		{
			do_ch(a, b, "rr", hh->col);
			++(hh->fa);
			++(hh->fb);
		}
	}
}

void	new2algmain(t_num **a, t_num **b, t_help *hh)
{
	int l;

	l = 0;
	if (!(*b))
		return ;
	new2alg_d(a, b, hh, l);
	max_init(hh, *a);
	(hh->um > hh->max1) ? hlp(a, b, hh) : 0;
	new2algmain2(a, b, hh);
	hhelp3(a, b, hh);
	do_ch(a, b, "pa", hh->col);
	return (new2algmain(a, b, hh));
}
