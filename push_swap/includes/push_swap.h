/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:23:37 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/12 20:23:38 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)

# include "../gnl/get_next_line.h"
# include <stdio.h>

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_main
{
	t_stack			*a;
	size_t			size_a;
	t_stack			*b;
	size_t			size_b;
}					t_main;

void				*ps_init(char **arr, int len);
void				die();

void				sa(t_main *main);
void				sb(t_main *main);
void				ss(t_main *main);

void				pa(t_main *main);
void				pb(t_main *main);

void				ra(t_main *main);
void				rb(t_main *main);
void				rr(t_main *main);

void				rra(t_main *main);
void				rrb(t_main *main);
void				rrr(t_main *main);

void	show(t_stack *p);

#endif
