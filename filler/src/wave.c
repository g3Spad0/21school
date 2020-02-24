/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:01:19 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/21 13:01:21 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/filler.h"

static	int		check_item(t_main *main, int who, int item)
{
	if (who == main->me)
	{
		return (fl_char_check(item, main->me) ||
			fl_char_check(item, main->me + 2) ||
			item == '1' || item == '3' ? 1 : 0);
	}
	return (fl_char_check(item, main->enemy) || item == '4' ? 1 : 0);
}

static	int		include_item(t_main *main, int y, int x, int what)
{
	int		count;

	count = 0;
	if (y - 1 >= 0 && main->map[y - 1][x] == '.')
	{
		main->map[y - 1][x] = what + 2;
		count += 1;
	}
	if (y + 1 < main->os_y && main->map[y + 1][x] == '.')
	{
		main->map[y + 1][x] = what;
		count += 1;
	}
	if (x - 1 >= 0 && main->map[y][x - 1] == '.')
	{
		main->map[y][x - 1] = what + 2;
		count += 1;
	}
	if (x + 1 < main->os_x && main->map[y][x + 1] == '.')
	{
		main->map[y][x + 1] = what;
		count += 1;
	}
	return (count);
}

static	int		wave_pushing(t_main *main, int who)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	i = main->os_y;
	while (i--)
	{
		j = main->os_x;
		while (j--)
		{
			if (main->map[i][j] != '.' && check_item(main, who,
				main->map[i][j]))
			{
				x += include_item(main, i, j, who == main->me ? '3' : '4');
			}
			else if (main->map[i][j] == '5' || main->map[i][j] == '6')
			{
				main->map[i][j] -= 2;
			}
		}
	}
	return (x);
}

static	void	arfer_wave(t_main *main, int y, int x)
{
	int		enemy;
	int		me;
	int		i;
	int		j;

	enemy = 0;
	me = 0;
	i = main->os_y;
	while (i--)
	{
		j = main->os_x;
		while (j--)
		{
			if (check_item(main, main->me, main->map[i][j]))
				fl_fix_norm(main->map[i], '3', j, &me);
			else if (check_item(main, main->enemy, main->map[i][j]))
				fl_fix_norm(main->map[i], '4', j, &enemy);
		}
	}
	if (!main->res->flag || main->res->score < me - enemy)
		fl_push_new_result(main->res, y, x, me - enemy);
}

void			wave_function(t_main *main, int i, int j)
{
	return ((wave_pushing(main, main->me) + wave_pushing(main,
	main->enemy)) ? wave_function(main, i, j) : arfer_wave(main, i, j));
}
