/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:04:11 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 18:22:12 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	rrr(t_num **a, t_num **b, int k)
{
	rra(a, 'a', 0);
	rra(b, 'b', 0);
	(k) ? ft_printf("rrr\n") : 0;
}

void	pa(t_num **a, t_num **b, char *s, int k)
{
	t_num	*tmp;

	(*s != '\0' && k) ? ft_printf("%s\n", s) : 0;
	if (!*a)
		return ;
	if ((*a)->next == NULL)
	{
		(*a)->next = *b;
		(*b) = (*a);
		*a = NULL;
		tmp = (*b)->next;
		while (tmp)
		{
			tmp->pos += 1;
			tmp = tmp->next;
		}
		return ;
	}
	helppa(a, b);
}

void	helppa(t_num **a, t_num **b)
{
	t_num	*tmp;
	t_num	*tmp1;

	tmp1 = (*a);
	tmp = (*a)->next;
	(*a)->next = *b;
	(*a) = tmp;
	(*b) = tmp1;
	tmp = (*a);
	while (tmp->next)
	{
		tmp->pos -= 1;
		tmp = tmp->next;
	}
	tmp->pos -= 1;
	tmp = (*b)->next;
	while (tmp)
	{
		tmp->pos += 1;
		tmp = tmp->next;
	}
}

void	lp(t_num **a, t_num **b)
{
	while (*b)
		pa(b, a, "pa", 1);
}
