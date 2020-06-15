/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:31:51 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 20:54:06 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

int		max(int a, int b)
{
	return (a > b) ? a : b;
}

int		min(int a, int b)
{
	return (a < b) ? a : b;
}

void	min_serch(t_num *head, t_help *hh)
{
	t_num	*tmp;

	hh->min_num1 = head->num;
	hh->pos1 = head->pos;
	tmp = head;
	while (tmp->next)
	{
		if (hh->min_num1 > tmp->next->num)
		{
			hh->min_num1 = tmp->next->num;
			hh->pos1 = tmp->next->pos;
		}
		tmp = tmp->next;
	}
}

void	m_alg3(t_num **h, t_num **k, t_help *hh)
{
	int a;
	int b;
	int c;

	a = (*h)->num;
	b = (*h)->next->num;
	c = (*h)->next->next->num;
	if (check_sort(*h))
		return ;
	if (a < b && b > c && c > a)
	{
		do_ch(h, k, "rra", hh->col);
		do_ch(h, k, "sa", hh->col);
	}
	else if (a > b && b < c && c > a)
		do_ch(h, k, "sa", hh->col);
	else if (a < b && b > c && c < a)
		do_ch(h, k, "rra", hh->col);
	else if (a > b && b < c && a > c)
		do_ch(h, k, "ra", hh->col);
	else if (a > b && b > c && a > c)
	{
		do_ch(h, k, "ra", hh->col);
		do_ch(h, k, "sa", hh->col);
	}
}

void	check_dup(t_num *a)
{
	int		i;
	t_num	*tmp;
	t_num	*tmp1;

	tmp = a;
	while (tmp)
	{
		i = tmp->num;
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (i == tmp1->num)
				error_my(a, NULL, 0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
