/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:21:22 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/15 19:21:23 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/filler.h"

void	fl_update_res(t_res *main, t_res *res)
{
	main->x = res->x;
	main->y = res->y;
	main->flag = res->flag;
	main->score = res->score;
}

void	fl_result_to_null(t_res *res)
{
	res->x = 0;
	res->y = 0;
	res->flag = 0;
	res->score = 0;
}

void	clean_array_2(char **array, int count)
{
	int		i;

	i = 0;
	while (i < count)
		free(array[i++]);
	free(array);
	array = NULL;
}

void	fl_tmp(t_main *main, char *line)
{
	main->piece->count = 0;
	main->piece->flag = 0;
	main->token->count = 0;
	fl_map_info(main, line);
}

int		fl_char_check(char what, char need)
{
	return (what == need || what - 32 == need ? 1 : 0);
}
