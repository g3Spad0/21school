/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 22:43:55 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/23 22:43:57 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	void	reverse_rotate_a(t_main *main)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;

	tmp1 = main->a;
	while (tmp1->next)
	{
		if (!tmp1->next->next)
		{
			tmp3 = tmp1;
		}
		tmp1 = tmp1->next;
	}
	tmp2 = main->a;
	main->a = tmp1;
	main->a->next = tmp2;
	tmp3->next = NULL;
}

void			rra(t_main *main)
{
	if (main->size_a > 1)
	{
		reverse_rotate_a(main);
	}
}

static	void	reverse_rotate_b(t_main *main)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;

	tmp1 = main->b;
	while (tmp1->next)
	{
		if (!tmp1->next->next)
		{
			tmp3 = tmp1;
		}
		tmp1 = tmp1->next;
	}
	tmp2 = main->b;
	main->b = tmp1;
	main->b->next = tmp2;
	tmp3->next = NULL;
}

void			rrb(t_main *main)
{
	if (main->size_b > 1)
	{
		reverse_rotate_b(main);
	}
}

void			rrr(t_main *main)
{
	rra(main);
	rrb(main);
}
