/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prolog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:14:23 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/23 19:14:25 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	prolog(t_main *main, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(main);
	else if (!ft_strcmp(line, "sb"))
		sb(main);
	else if (!ft_strcmp(line, "ss"))
		ss(main);
	else if (!ft_strcmp(line, "pa"))
		pa(main);
	else if (!ft_strcmp(line, "pb"))
		pb(main);
	else if (!ft_strcmp(line, "ra"))
		ra(main);
	else if (!ft_strcmp(line, "rb"))
		rb(main);
	else if (!ft_strcmp(line, "rr"))
		rr(main);
	else if (!ft_strcmp(line, "rra"))
		rra(main);
	else if (!ft_strcmp(line, "rrb"))
		rrb(main);
	else if (!ft_strcmp(line, "rrr"))
		rrr(main);
	else
		die();
}

void	epilog(t_main *main)
{
	t_stack	*tmp;
	int		num;

	if (main->size_b)
	{
		ft_putstr("KO\n");
		return ;
	}
	tmp = main->a->next;
	num = main->a->num;
	while (tmp)
	{
		if (num > tmp->num)
		{
			ft_putstr("KO\n");
			return ;			
		}
		num = tmp->num;
		tmp = tmp->next;
	}
	ft_putstr("OK\n");
}
