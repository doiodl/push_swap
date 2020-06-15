/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:51:54 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 20:45:06 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	max_init(t_help *hh, t_num *head)
{
	t_num	*tmp;

	if (!head)
		return ;
	hh->max1 = head->num;
	tmp = head;
	while (tmp)
	{
		if (hh->max1 < tmp->num)
			hh->max1 = tmp->num;
		tmp = tmp->next;
	}
}

void	hlp(t_num **a, t_num **b, t_help *hh)
{
	int i;

	b = b + 0;
	i = -1;
	if (!check_sort(*a))
	{
		min_serch(*a, hh);
		hh->len_s = len_stack(*a);
		if (hh->pos1 <= hh->len_s / 2)
			hh->fa = -hh->pos1;
		else
			hh->fa = len_stack(*a) - hh->pos1;
	}
}

int		sum_2(int a, int b)
{
	if (a >= 0 && b >= 0)
		return (max(a, b));
	if (a < 0 && b >= 0)
		return (-a + b);
	if (a >= 0 && b < 0)
		return (a + -b);
	return (-min(a, b));
}

void	init_hh(t_num **a, t_help *hh)
{
	hh->len_s = len_stack(*a);
	hh->tb = 0;
	hh->ta = 0;
	hh->fb = 0;
	hh->fa = 0;
	hh->suml = 0;
}

void	helpalg(t_help *hh, int *l, int j)
{
	if (hh->suml == 0 && !((*l)++))
	{
		hh->suml = sum_2(hh->ta, hh->tb);
		hh->fa = hh->ta;
		hh->fb = hh->tb;
		hh->um = j;
		return ;
	}
	if (hh->suml > sum_2(hh->ta, hh->tb))
	{
		hh->suml = sum_2(hh->ta, hh->tb);
		hh->fa = hh->ta;
		hh->fb = hh->tb;
		hh->um = j;
	}
}
