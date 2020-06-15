/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:31:40 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 21:15:46 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

t_num	*creat_el(char *av, int pos_el)
{
	t_num	*tmp;
	char	*p;
	char	*l;

	p = NULL;
	if (!(tmp = (t_num*)malloc(sizeof(t_num))))
		return (NULL);
	tmp->num = ft_atoi(av);
	l = ft_itoa(tmp->num);
	if ((p = ft_strchr(av, ' ')))
	{
		if (ft_strncmp(av, l, p - av))
			return (dle(&l, tmp));
	}
	else
	{
		if (ft_strcmp(av, l))
			return (dle(&l, tmp));
	}
	free(l);
	tmp->pos = pos_el;
	tmp->next = NULL;
	return (tmp);
}

int		check_sort(t_num *head)
{
	t_num	*tmp;
	int		i;

	if (!head)
		return (0);
	tmp = head;
	i = head->num;
	while (tmp->next)
	{
		if (i > tmp->next->num)
			return (0);
		tmp = tmp->next;
		i = tmp->num;
	}
	return (1);
}

int		len_stack(t_num *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	new2alg_d3(t_num **a, t_num **b, t_help *hh, int *midl)
{
	init_hh(b, hh);
	((midl[0] = hh->len_s / 2) && hh->len_s % 2) ? (++midl[0]) : 0;
	(!midl[0]) ? (midl[0]++) : 0;
	((midl[1] = len_stack(*a) / 2) && len_stack(*a) % 2) ? (++midl[1]) : 0;
	midl[2] = len_stack(*b);
	midl[3] = len_stack(*a);
}

void	do_ch(t_num **a, t_num **b, char *s, int k)
{
	int	i;

	i = 0;
	(k == 2) ? print_stack(*a, *b, "") : 0;
	(!(ft_strcmp(s, "sa"))) ? sa(*a, 'a', !k) : ++i;
	(!(ft_strcmp(s, "sb\0"))) ? sa(*b, 'b', !k) : ++i;
	(!(ft_strcmp(s, "ss\0"))) ? ss(a, b, !k) : ++i;
	(!(ft_strcmp(s, "ra\0"))) ? ra(a, 'a', !k) : ++i;
	(!(ft_strcmp(s, "rb\0"))) ? ra(b, 'b', !k) : ++i;
	(!(ft_strcmp(s, "rr\0"))) ? rr(a, b, !k) : ++i;
	(!(ft_strcmp(s, "rra\0"))) ? rra(a, 'a', !k) : ++i;
	(!(ft_strcmp(s, "rrb\0"))) ? rra(b, 'b', !k) : ++i;
	(!(ft_strcmp(s, "rrr\0"))) ? rrr(a, b, !k) : ++i;
	(!(ft_strcmp(s, "pa\0"))) ? pa(b, a, "pa", !k) : ++i;
	(!(ft_strcmp(s, "pb\0"))) ? pa(a, b, "pb", !k) : ++i;
	if (i == 11)
	{
		free(s);
		ft_clear_lst(*b);
		error_my(*a, "", 0);
	}
	(k == 2) ? print_stack(*a, *b, s) : 0;
}
