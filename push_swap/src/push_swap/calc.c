/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:09:00 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/29 19:09:01 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/s_push_swap.h"

static	size_t	search_neadle(t_sort *sort)
{
	t_stack	*tmp;
	size_t	i;
	int		find;
	int		num;

	tmp = sort->main->b;
	i = sort->i;
	while (sort->array[i] != sort->main->a->num)
		i++;
	num = sort->array[++i];
	i = 0;
	find = 0;
	while (tmp)
	{
		if (tmp->num == num && (find = 1))
			break ;
		tmp = tmp->next;
		++i;
	}
	return (!find ? 1000 : i);
}

static	void	calc_from_end(t_sort *sort, size_t end)
{
	size_t	tmp;

	tmp = end - 1;
	while (end--)
	{
		if (tmp != end && is_needle(sort))
			return ;
		rrb(sort->main);
	}
	pa(sort->main);
}

static	void	calc_from_start(t_sort *sort, size_t start)
{
	size_t	tmp;

	tmp = start - 1;
	while (start--)
	{
		if (tmp != start && is_needle(sort))
			return ;
		rb(sort->main);
	}
	pa(sort->main);
}

int				calc_to_top(t_sort *sort)
{
	size_t	end;
	size_t	start;

	start = search_neadle(sort);
	end = sort->main->size_b - start;
	if (end <= start && end < 3)
	{
		calc_from_end(sort, end);
		return (1);
	}
	if (start < end && start < 3)
	{
		calc_from_start(sort, start);
		return (1);
	}
	return (0);
}
