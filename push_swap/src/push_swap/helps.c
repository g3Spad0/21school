/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:06:47 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/24 19:06:49 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/s_push_swap.h"

int				is_needle(t_sort *sort)
{
	if (sort->main->b->num == sort->array[sort->i])
	{
		pa(sort->main);
		ra(sort->main);
		sort->i += 1;
		return (1);
	}
	return (0);
}

int				is_sort(t_main *main, int b_flag)
{
	t_stack	*tmp;
	int		num;

	if (b_flag && main->size_b)
	{
		return (0);
	}
	tmp = main->a->next;
	num = main->a->num;
	while (tmp)
	{
		if (num > tmp->num)
		{
			return (0);			
		}
		num = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}
