/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:21:19 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 23:19:42 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

static void	init_1_h(t_help *hh)
{
	hh->debug = 0;
	hh->f = 0;
	hh->col = 0;
}

int			main(int ac, char **av)
{
	t_num	*a;
	t_num	*b;
	t_help	hh;

	b = NULL;
	init_1_h(&hh);
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		(ft_strncmp(av[1], "-v ", 3) == 0) ? hh.debug = 1 : 0;
		a = check_one(av[1] + 3 * hh.debug);
	}
	else
	{
		(!(strcmp(av[1], "-f")) && (++hh.f)) ? a = re_fi(*(av + 2)) : 0;
		(ac >= 4 && ft_strcmp(*(av + hh.f * 2 + 1), "-v") == 0) ?
			++hh.debug : 0;
		(!hh.f) ? a = check_two(av, hh.f * 2 + 1 + hh.debug, ac) : 0;
	}
	check_dup(a);
	read_inst(&a, &b, &hh);
	return (0);
}

void		read_inst(t_num **a, t_num **b, t_help *hh)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (*line == '\0')
			break ;
		do_ch(a, b, line, 1);
		(hh->debug) ? plist_d(*a, *b, len_stack(*a), len_stack(*b)) : 0;
		(line) ? free(line) : 0;
	}
	(line) ? free(line) : 0;
	if (check_sort(*a) && !(*b))
	{
		ft_clear_lst(*a);
		write(1, "OK\n", 3);
	}
	else
	{
		ft_clear_lst(*a);
		ft_clear_lst(*b);
		write(1, "KO\n", 3);
	}
}
