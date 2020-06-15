/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:46:54 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 18:22:09 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

void	sa(t_num *head, char c, int k)
{
	int	tmp;

	if (!head || head->next == NULL)
		return ;
	tmp = head->num;
	head->num = head->next->num;
	head->next->num = tmp;
	(c != ' ' && k) ? ft_printf("s%c\n", c) : 0;
}

void	ss(t_num **a, t_num **b, int k)
{
	sa(*a, ' ', k);
	sa(*b, ' ', k);
	(k) ? ft_printf("ss\n") : 0;
}

void	ra(t_num **a, char c, int k)
{
	int		len;
	t_num	*tmp;
	t_num	*tmp1;

	if (!(*a) || (*a)->next == NULL)
		return ;
	len = 0;
	tmp = (*a);
	tmp1 = (*a)->next;
	while (tmp->next)
	{
		tmp->pos -= 1;
		++len;
		tmp = tmp->next;
	}
	tmp->pos -= 1;
	(*a)->pos = len;
	tmp->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp1;
	(c != ' ' && k) ? ft_printf("r%c\n", c) : 0;
}

void	rr(t_num **a, t_num **b, int k)
{
	ra(a, ' ', k);
	ra(b, ' ', k);
	(k) ? ft_printf("rr\n") : 0;
}

void	rra(t_num **a, char c, int k)
{
	int		len;
	t_num	*tmp;
	t_num	*tmp1;

	if (!*a || !((*a)->next))
		return ;
	len = 0;
	tmp = (*a);
	tmp1 = (*a)->next;
	while (tmp->next->next)
	{
		tmp->pos += 1;
		++len;
		tmp = tmp->next;
	}
	tmp->pos += 1;
	tmp->next->pos = 0;
	tmp->next->next = (*a);
	(*a) = tmp->next;
	tmp->next = NULL;
	(c != ' ' && k) ? ft_printf("rr%c\n", c) : 0;
}
