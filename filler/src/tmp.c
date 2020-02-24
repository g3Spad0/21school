/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:45:23 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/21 15:45:25 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fl_push_new_result(t_res *res, int y, int x, int score)
{
	res->y = y;
	res->x = x;
	res->flag = 1;
	res->score = score;
}

void	fl_fix_norm(char *str, char flag, int j, int *what)
{
	*what += 1;
	if (str[j] == flag)
	{
		str[j] = '.';
	}
}
