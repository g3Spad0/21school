/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:09:24 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/24 22:09:26 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/s_push_swap.h"

static	void	min_max(t_sort *sort)
{
	t_stack	*tmp;
	int		min;
	int		max;

	tmp = sort->main->a->next;
	min = sort->main->a->num;
	max = sort->main->a->num;
	while (tmp)
	{
		if (tmp->num > max)
		{
			max = tmp->num;
		}
		else if (tmp->num < min)
		{
			min = tmp->num;
		}
		tmp = tmp->next;
	}
	sort->min = min;
	sort->max = max;
}

void			*sorting_init(t_main *main)
{
	t_sort	*new;
	t_data	*data;

	if (!(new = (t_sort*)malloc(sizeof(t_sort))))
		die();
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		die();
	new->main = main;
	min_max(new);
	new->num = new->min;
	new->data = data;
	new->pivat = (new->num + new->max) / 2;
	return ((void*)new);
}
