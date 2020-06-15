/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:37:08 by btheia            #+#    #+#             */
/*   Updated: 2019/11/27 17:30:13 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_ps.h"

t_num	*dle(char **s, t_num *tmp)
{
	free(*s);
	free(tmp);
	return (NULL);
}

int		ft_clear_lst(t_num *lst)
{
	t_num *p;

	while (lst)
	{
		p = lst->next;
		free(lst);
		lst = NULL;
		lst = p;
	}
	return (0);
}

void	error_my(t_num *head, char *line, int k)
{
	(k) ? free(line) : 0;
	ft_clear_lst(head);
	write(1, "Error\n", 6);
	exit(0);
}

t_num	*re_fi(char *file)
{
	char	*line;
	t_num	*head;
	int		fd;
	t_num	*tmp;
	int		i;

	i = 0;
	line = NULL;
	((fd = open(file, O_RDONLY)) == -1) ? exit(0) : get_next_line(fd, &line);
	if (!(head = creat_el(line, i++)))
		error_my(head, line, 1);
	((tmp = head)) ? free(line) : 0;
	while (get_next_line(fd, &line))
	{
		if (!(tmp->next = creat_el(line, i++)))
			error_my(head, line, 1);
		tmp = tmp->next;
		free(line);
	}
	(line) ? free(line) : 0;
	close(fd);
	return (head);
}

void	print_stack(const t_num *stack_a, const t_num *stack_b, char *c)
{
	ft_printf(ESC "[2J");
	ft_printf(ESC "[H");
	ft_printf("%s%11s %s%11s %s%11s%s\n", "\x1B[40m\x1B[31m\x1B[1m", "STACK_A",
	"\x1B[35m", "STACK_B", "\x1B[33m", "cmd", "\033[0m");
	ft_printf("%s%35s%s\n", "\x1B[40m\x1B[33m\x1B[1m", c, "\x1B[0m");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%s%11d ", "\x1B[40m\x1B[31m", stack_a->num);
			stack_a = stack_a->next;
		}
		else
			ft_printf("%s%13c", "\x1B[40m", '\0');
		if (stack_b)
		{
			ft_printf("%s%11d%13c", "\x1B[40m\x1B[35m", stack_b->num, '\0');
			stack_b = stack_b->next;
		}
		else
			ft_printf("%s%12c%13c", "\x1B[40m\x1B[35m", '\0', '\0');
		ft_printf("%s%s", "\x1B[0m", "\n");
	}
	usleep(500000);
}
