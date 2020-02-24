/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:25:33 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/29 19:25:36 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/s_push_swap.h"

static	int		get_next(t_sort *sort, int from)
{
	t_stack	*tmp;
	int		num;

	num = sort->max;
	tmp = sort->main->a;
	while (tmp)
	{
		if (tmp->num < num && tmp->num > from)
		{
			num = tmp->num;
		}
		tmp = tmp->next;
	}
	return (num);
}

void			bubble_sort(t_sort *sort)
{
	size_t	i;
	int		*arr;

	if (!(arr = (int*)malloc(sort->main->size_a * sizeof(int))))
		die();
	i = 0;
	sort->i = 0;
	sort->count = sort->main->size_a;
	arr[i++] = sort->min;
	while (i < sort->count)
	{
		arr[i] = get_next(sort, arr[i - 1]);
		++i;
	}
	sort->array = arr;
}
