/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:19:24 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/10 22:19:26 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/filler.h"

void	fl_get_token(t_main *main)
{
	int		i;
	int		j;
	int		k;

	main->token->str = (char*)ft_memalloc((main->piece->count * 2 + 1) *
		sizeof(char));
	i = 0;
	k = 0;
	while (i < main->piece->piece_y)
	{
		j = 0;
		while (j < main->piece->piece_x)
		{
			if (main->piece->piece[i][j] == '*')
			{
				main->token->str[k++] = i - main->piece->first_y;
				main->token->str[k++] = j - main->piece->first_x;
			}
			j++;
		}
		i++;
	}
	main->tmp_last = 0;
	main->token->count = main->piece->count * 2;
	clean_array_2(main->piece->piece, main->piece->piece_y);
}

void	fl_for_map(t_main *main)
{
	int		i;
	int		j;

	i = 0;
	while (i < main->os_y)
	{
		j = 0;
		while (j < main->os_x)
		{
			if ((fl_try_include(main, i, j)))
			{
				fl_include(main, i, j);
				wave_function(main, i, j);
				fl_clean_include(main, i, j);
			}
			j++;
		}
		i++;
	}
	return ;
}

void	fl_controller(t_main *main)
{
	fl_result_to_null(main->res);
	fl_get_token(main);
	fl_for_map(main);
	fl_results(main);
}

int		main(void)
{
	t_main	*main;
	char	*line;
	int		ch;

	line = NULL;
	ch = 0;
	if (!(main = (t_main*)fl_init(get_next_line(ch, &line), line)))
		return (1);
	while (get_next_line(ch, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			fl_tmp(main, line);
			ft_memdel((void**)&line);
			get_next_line(ch, &line);
		}
		else if (ft_isdigit(line[0]))
			fl_map_write(line, main);
		else if (ft_strstr(line, "Piece"))
			fl_piece_set(main, line);
		else if (line[0] == '.' || line[0] == '*')
			fl_piece_write(main, line);
		ft_memdel((void**)&line);
	}
	return (0);
}
