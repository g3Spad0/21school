/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:31:00 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/23 19:31:01 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	void	s_sort(t_stack **list)
{
	t_stack	*a;
	t_stack	*b;

	a = *list;
	b = a->next;
	*list = b;
	a->next = b->next;
	b->next = a;
}

void			sa(t_main *main)
{
	if (main->size_a > 1)
	{
		s_sort(&main->a);
	}
}

void			sb(t_main *main)
{
	if (main->size_b > 1)
	{
		s_sort(&main->b);
	}
}

void			ss(t_main *main)
{
	sa(main);
	sb(main);
}
