/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:25:47 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/15 19:25:48 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/filler.h"

static	void	for_norm(t_res *res, int y, int x)
{
	res->x = x;
	res->y = y;
	res->flag = 1;
}

void			fl_clean_include(t_main *main, int y, int x)
{
	char	*str;
	int		i;

	i = 0;
	str = main->token->str;
	while (i < main->token->count)
	{
		if (main->map[str[i] + y][str[i + 1] + x] == '1')
		{
			main->map[str[i] + y][str[i + 1] + x] = '.';
			i += 2;
			continue ;
		}
		main->map[str[i] + y][str[i + 1] + x] -= 2;
		i += 2;
	}
}

int				fl_try_include(t_main *main, int y, int x)
{
	t_res	tmp;
	char	*str;
	int		i;

	i = 0;
	fl_result_to_null(&tmp);
	str = main->token->str;
	while (i < main->token->count)
	{
		if ((str[i] + y >= main->os_y || str[i] + y < 0) ||
			(str[i + 1] + x >= main->os_x || str[i + 1] + x < 0) ||
			fl_char_check(main->map[str[i] + y][str[i + 1] + x], main->enemy))
			return (0);
		if (main->map[str[i] + y][str[i + 1] + x] == '.')
			tmp.score += 1;
		if (tmp.flag < 2 && fl_char_check(main->map[str[i] + y]
			[str[i + 1] + x], main->me))
		{
			for_norm(&tmp, y, x);
		}
		i += 2;
	}
	return (tmp.flag && tmp.score == main->token->count / 2 - 1 ? 1 : 0);
}

void			fl_results(t_main *main)
{
	clean_array_2(main->map, main->os_y);
	ft_memdel((void**)&main->token->str);
	if (!main->res->flag)
	{
		ft_putstr("0 0\n");
		exit(0);
	}
	ft_putnbr(main->res->y - main->piece->first_y);
	ft_putchar(' ');
	ft_putnbr(main->res->x - main->piece->first_x);
	ft_putchar('\n');
}

void			fl_include(t_main *main, int y, int x)
{
	char	*str;
	int		i;

	i = 0;
	str = main->token->str;
	while (i < main->token->count)
	{
		if (main->map[str[i] + y][str[i + 1] + x] == '.')
		{
			main->map[str[i] + y][str[i + 1] + x] = '1';
			i += 2;
			continue ;
		}
		main->map[str[i] + y][str[i + 1] + x] += 2;
		i += 2;
	}
}
