/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:00:43 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/24 17:00:45 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/s_push_swap.h"

int				main(int argc, char **argv)
{
	t_main	*main;
	t_sort	*sort;

	main = ps_init(argv, argc);
	if (main->size_a == 1)
		return (0);
	else if (main->size_a == 2)
	{
		if (!is_sort(main, 0))
			ft_putstr("sa\n");
		return (0);
	}
	else if (main->size_a == 3)
	{
		;
		return (0);
	}
	sort = (t_sort*)sorting_init(main);
	bubble_sort(sort);
	sorting(sort);
	sorting(sort);
	return (0);
}
