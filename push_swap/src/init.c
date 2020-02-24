/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:16:33 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/23 18:16:35 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_stack *p)
{
	while (p)
	{
		printf("%d\n", p->num);
		p = p->next;
	}
}

void			die()
{
	ft_putstr("Error\n");
	exit(0);	
}

static	t_stack	**build_structure(char *str, t_stack **adress)
{
	t_stack	*new;
	int		i;
//	проверка на биг инт
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			die();
		i++;
	}
	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		die();
	new->num = ft_atoi(str);
	*adress = new;
	return (&new->next);
}

void			*ps_init(char **arr, int len)
{
	t_stack	**tmp;
	t_main	*main;
	int		i;

	if (len < 2 || !(main = (t_main*)malloc(sizeof(t_main))))
	{
		die();
	}
	i = 0;
	while (++i < len)
	{
		if (i == 1)
		{
			tmp = build_structure(arr[i], &main->a);
			continue ;
		}
		tmp = build_structure(arr[i], tmp);
	}
	main->b = NULL;
	main->size_b = 0;
	main->size_a = i - 1;
	*tmp = NULL;
	return ((void*)main);
}
