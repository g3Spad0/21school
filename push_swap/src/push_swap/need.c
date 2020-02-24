/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:14:56 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/29 19:14:57 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/s_push_swap.h"

int				check_stack_a(t_sort *sort)
{
	t_stack	*tmp;

	tmp = sort->main->a;
	while (tmp)
	{
		if (tmp->num <= sort->pivat && tmp->num >= sort->array[sort->i])
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int				check_stack_b(t_sort *sort)
{
	t_stack	*tmp;

	tmp = sort->main->b;
	while (tmp)
	{
		if (tmp->num > sort->data->pivat)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
