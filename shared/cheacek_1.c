/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheacek_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:20:22 by btheia            #+#    #+#             */
/*   Updated: 2019/11/27 18:48:10 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

t_num	*check_one(char *av)
{
	t_num		*head;
	size_t		i;
	char		*space;
	t_num		*tmp;

	i = 1;
	if (!(space = strchr(av, ' ')))
	{
		(!(head = creat_el(av, 1))) ? error_my(head, "", 0) : 0;
		return (head);
	}
	(!(head = creat_el(av, 0))) ? error_my(head, "", 0) : 0;
	tmp = head;
	av = space + 1;
	space = strchr(av, ' ');
	while (space)
	{
		(!(tmp->next = creat_el(av, i++))) ? error_my(head, "", 0) : 0;
		av = space + 1;
		space = strchr(av, ' ');
		tmp = tmp->next;
	}
	tmp->next = creat_el(av, i);
	return (head);
}

t_num	*check_two(char **av, int k, int ac)
{
	t_num		*head;
	size_t		i;
	t_num		*tmp;

	i = 0;
	if (ac == k)
		error_my(NULL, "", 0);
	if (!(head = creat_el(av[k++], i++)))
		error_my(head, "", 0);
	tmp = head;
	while (k < ac)
	{
		if (!(tmp->next = creat_el(av[k++], i++)))
			error_my(head, "", 0);
		tmp = tmp->next;
	}
	return (head);
}

void	plist(t_num *head, char c)
{
	t_num *tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("num %ld, pos %d\n", tmp->num, tmp->pos);
		tmp = tmp->next;
	}
	ft_printf("-\n");
	ft_printf("%c\n", c);
}

void	plist_d(t_num *a, t_num *b, int len1, int len2)
{
	t_num	*tmp1;
	t_num	*tmp2;

	tmp1 = a;
	tmp2 = b;
	ft_printf("--\n");
	if (len1 >= len2)
		hprintf(tmp1, tmp2);
	else
	{
		while (tmp2)
		{
			if (!(tmp1))
				ft_printf("%c	%ld\n", ' ', tmp2->num);
			else
			{
				ft_printf("%ld	%ld\n", tmp1->num, tmp2->num);
				tmp1 = tmp1->next;
			}
			tmp2 = tmp2->next;
		}
	}
	ft_printf("-	-\n");
	ft_printf("a	b\n\n");
	return ;
}

void	hprintf(t_num *tmp1, t_num *tmp2)
{
	while (tmp1)
	{
		if (!(tmp2))
			ft_printf("%ld	%c\n", tmp1->num, ' ');
		else
		{
			ft_printf("%ld	%ld\n", tmp1->num, tmp2->num);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
