/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:53:03 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/24 20:53:05 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/s_push_swap.h"

void			min_max_b(t_sort *sort)
{
	t_stack	*tmp;
	int		min;
	int		max;

	// if (!sort->main->size_b)
	// 	die();
	tmp = sort->main->b->next;
	min = sort->main->b->num;
	max = sort->main->b->num;
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
	sort->data->min = min;
	sort->data->max = max;
	sort->data->pivat = (min + max) / 2;
}

void			from_b_to_a(t_sort *sort)
{
	if (is_needle(sort))
		return ;
	if (sort->main->b->num <= sort->data->pivat)
	{
		rb(sort->main);
		return ;
	}
	pa(sort->main);
}

void			start_sort_b(t_sort *sort)
{
	while (sort->main->size_b)
	{
		if (is_needle(sort))
			continue ;
		if (calc_to_top(sort))
			return ;
		rb(sort->main);
	}
}

void			sorting_b(t_sort *sort)
{
	if (sort->main->size_b <= 14)
	{
		start_sort_b(sort);
		if ((int)sort->i >= sort->pivat)
			sort->pivat = -1;
		return ;
	}
	min_max_b(sort);
	while (!check_stack_b(sort))
		from_b_to_a(sort);
	sorting_b(sort);
}

void			from_a_to_b(t_sort *sort)
{
	while (!check_stack_a(sort))
	{
		printf(">%d %d %zu\n", sort->main->a->num, sort->pivat, sort->i);
		if (sort->main->a->num <= sort->pivat &&
			sort->main->a->num >= sort->array[sort->i])
		{
			pb(sort->main);
			continue ;
		}
		ra(sort->main);
	}
}

void			sorting(t_sort *sort)
{
	if (is_sort(sort->main, 1))
		return ;
	if (sort->pivat == -1)
		sort->pivat = (sort->i + sort->max) / 2;
	from_a_to_b(sort);
	sorting_b(sort);
	show(sort->main->a);
	printf("\n\n");
	show(sort->main->b);
//	sorting(sort);
}
