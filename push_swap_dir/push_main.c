/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:24:05 by btheia            #+#    #+#             */
/*   Updated: 2019/11/27 18:49:25 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

static void	check2(t_num **a, t_num **b, t_help *hh)
{
	check_dup(*a);
	if (check_sort(*a))
	{
		ft_clear_lst(*a);
		exit(0);
	}
	if (len_stack(*a) == 1)
	{
		free(*a);
		exit(0);
	}
	if (len_stack(*a) == 2)
	{
		(!check_sort(*a)) ? do_ch(a, b, "sa", hh->col) : 0;
		ft_clear_lst(*a);
		exit(0);
	}
}

static void	check_l(t_num **a, t_num **b, t_help *hh)
{
	hh->fa = 0;
	hh->fb = 0;
	hlp(a, b, hh);
	hhelp3(a, b, hh);
}

int			main(int ac, char **av)
{
	t_num	*a;
	t_num	*b;
	t_help	hh;

	b = NULL;
	hh.f = 0;
	hh.col = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		a = check_one(av[1]);
	else
	{
		(!(strcmp(av[1], "-f")) && (++hh.f)) ? (a = re_fi(*(av + 2))) : 0;
		(ac >= 4 && !(strcmp(*(av + hh.f * 2 + 1), "-c"))) ? (hh.col = 2) : 0;
		(!hh.f) ? a = check_two(av, hh.f * 2 + 1 + (hh.col / 2), ac) : 0;
	}
	check2(&a, &b, &hh);
	while (len_stack(a) != 3)
		do_ch(&a, &b, "pb", hh.col);
	m_alg3(&a, &b, &hh);
	hh.len_s = len_stack(b);
	new2algmain(&a, &b, &hh);
	check_l(&a, &b, &hh);
	return (ft_clear_lst(a));
}
