/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:09:38 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/23 21:09:42 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	void	push_a(t_main *main)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = main->b->next;
	tmp2 = main->a;
	main->a = main->b;
	main->a->next = tmp2;
	main->b = tmp1;
	main->size_b -= 1;
	main->size_a += 1;
}

void			pa(t_main *main)
{
	if (main->size_b)
	{
		push_a(main);
	}
}

static	void	push_b(t_main *main)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = main->a->next;
	tmp2 = main->b;
	main->b = main->a;
	main->b->next = tmp2;
	main->a = tmp1;
	main->size_a -= 1;
	main->size_b += 1;
}

void			pb(t_main *main)
{
	if (main->size_a)
	{
		push_b(main);
	}
}
