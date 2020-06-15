/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:20:34 by btheia            #+#    #+#             */
/*   Updated: 2019/11/22 21:16:31 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PS_H
# define HEADER_PS_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/includes/header.h"
# include "../libft/libft/libft.h"
# define BUFF_SIZE 4
# define ESC "\x1b"

typedef struct		s_num
{
	struct s_num	*next;
	long			num;
	int				pos;
}					t_num;

typedef struct		s_help
{
	int				suml;
	int				fa;
	int				fb;
	int				ta;
	int				tb;
	int				len_s;
	int				max_div;
	int				debug;
	int				col;
	int				f;
	int				big;
	int				max1;
	int				um;
	int				min_num1;
	int				pos1;
}					t_help;

t_num				*creat_el(char *av, int pos_el);
void				error_my(t_num *head, char *line, int k);
t_num				*check_one(char *av);
long				ft_atoi_new(char *av, int pos);
t_num				*check_two(char **av, int k, int ac);
int					check_sort(t_num *head);
int					len_stack(t_num *head);
void				min_serch(t_num *head, t_help *hh);
void				sa(t_num *head, char c, int k);
void				ss(t_num **a, t_num **b, int k);
void				ra(t_num **a, char c, int k);
void				rr(t_num **a, t_num **b, int k);
void				rra(t_num **a, char c, int k);
void				pa(t_num **a, t_num **b, char *s, int k);
void				malg(t_num **a, t_num **b, t_help *hh);
void				lp(t_num **a, t_num **b);
void				plist(t_num *head, char c);
void				reback_but1(t_num **a, t_num **b, t_help *hh, char c);
void				reback_but(t_num **a, t_help *hh);
void				init_hh(t_num **a, t_help *hh);
void				plist_d(t_num *a, t_num *b, int len1, int len2);
void				m_alg3(t_num **h, t_num **k, t_help *hh);
void				m_alg5(t_num **a, int len);
void				check_dup(t_num *a);
int					get_next_line(const int fd, char **line);
void				do_ch(t_num **a, t_num **b, char *s, int k);
void				rrr(t_num **a, t_num **b, int k);
int					ft_printf(const char *format, ...);
void				max_init(t_help *hh, t_num *head);
void				new_init(t_num **a, t_num **b, t_help *hh, int k);
int					can_re(t_num **a, t_num **b, t_help *hh);
void				re_a(t_num **a, t_help *hh);
void				top_rev(t_num **a, t_num **b, t_help *hh);
void				new_alg(t_num **a, t_num **b, t_help *hh);
int					max(int a, int b);
int					min(int a, int b);
void				init_start(t_num **a, t_num **b, t_help *hh);
void				read_inst(t_num **a, t_num **b, t_help *hh);
void				hprintf(t_num *tmp1, t_num *tmp2);
void				new2alg_d(t_num **a, t_num **b, t_help *hh, int l);
void				new2algmain(t_num **a, t_num **b, t_help *hh);
void				hlp(t_num **a, t_num **b, t_help *hh);
void				helppa(t_num **a, t_num **b);
void				new2algmain2(t_num **a, t_num **b, t_help *hh);
void				new2alg_d4(t_num *tmp, t_num *fm, t_help *hh, int *midl);
void				new2alg_d3(t_num **a, t_num **b, t_help *hh, int *midl);
void				helpalg(t_help *hh, int *l, int j);
int					ft_clear_lst(t_num *lst);
t_num				*dle(char **s, t_num *tmp);
t_num				*re_fi(char *file);
void				print_stack(const t_num *stack_a,
					const t_num *stack_b, char *c);
void				hhelp3(t_num **a, t_num **b, t_help *hh);

#endif
