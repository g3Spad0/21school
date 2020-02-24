/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 22:06:21 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/23 22:06:23 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	void	rotate_a(t_main *main)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp2 = main->a;
	main->a = main->a->next;
	tmp1 = main->a;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp2;
	tmp1->next->next = NULL;
}

void			ra(t_main *main)
{
	if (main->size_a > 1)
	{
		rotate_a(main);
	}
}

static	void	rotate_b(t_main *main)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp2 = main->b;
	main->b = main->b->next;
	tmp1 = main->b;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
	}
	tmp1->next = tmp2;
	tmp1->next->next = NULL; 
}

void			rb(t_main *main)
{
	if (main->size_b > 1)
	{
		rotate_b(main);
	}
}

void			rr(t_main *main)
{
	ra(main);
	rb(main);
}
