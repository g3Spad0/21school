/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:37:53 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/15 18:37:55 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/filler.h"

void	fl_map_info(t_main *main, char *str)
{
	char	**arr;
	char	*tmp;
	int		i;

	tmp = ft_strchr(str, ' ');
	tmp++;
	if (!(main->os_y = ft_atoi(tmp)))
		exit(1);
	tmp = ft_strchr(tmp, ' ');
	tmp++;
	if (!(main->os_x = ft_atoi(tmp)))
		exit(1);
	arr = (char**)ft_memalloc(sizeof(char*) * (main->os_y + 1));
	i = 0;
	while (i < main->os_y)
	{
		arr[i++] = (char*)ft_memalloc(sizeof(char) * (main->os_x + 1));
	}
	arr[main->os_y] = NULL;
	main->map = arr;
}

void	fl_piece_set(t_main *main, char *str)
{
	char	**arr;
	char	*tmp;
	int		i;

	tmp = ft_strchr(str, ' ');
	tmp++;
	main->piece->piece_y = ft_atoi(tmp);
	tmp = ft_strchr(tmp, ' ');
	tmp++;
	main->piece->piece_x = ft_atoi(tmp);
	arr = (char**)ft_memalloc(sizeof(char*) *
		(main->piece->piece_y + 1));
	i = 0;
	while (i < main->piece->piece_y)
	{
		arr[i++] = (char*)ft_memalloc(sizeof(char) *
			(main->piece->piece_x + 1));
	}
	arr[main->piece->piece_y] = NULL;
	main->piece->piece = arr;
	main->tmp_last = 0;
}

void	fl_map_write(char *str, t_main *main)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(str, ' ');
	tmp++;
	while (tmp[i])
	{
		main->map[main->tmp_last][i] = tmp[i];
		i++;
	}
	main->tmp_last += 1;
}

void	fl_piece_write(t_main *main, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
		{
			if (!main->piece->flag)
			{
				main->piece->first_y = main->tmp_last;
				main->piece->first_x = i;
				main->piece->flag = 1;
			}
			main->piece->count += 1;
		}
		main->piece->piece[main->tmp_last][i] = str[i];
		i++;
	}
	main->tmp_last += 1;
	if (main->piece->piece_y == main->tmp_last)
		fl_controller(main);
}

void	*fl_init(int res, char *str)
{
	t_main	*new;

	if (res < 1 || !str || !str[0] || (str[10] != '1' && str[10] != '2') ||
		!(new = (t_main*)malloc(sizeof(t_main))))
		return (NULL);
	new->enemy = str[10] == '1' ? 'X' : 'O';
	new->me = str[10] == '1' ? 'O' : 'X';
	new->os_x = 0;
	new->os_y = 0;
	new->map = NULL;
	new->tmp_last = 0;
	new->piece = (t_piece*)malloc(sizeof(t_piece));
	new->piece->first_x = 0;
	new->piece->first_y = 0;
	new->piece->piece_x = 0;
	new->piece->piece_y = 0;
	new->piece->count = 0;
	new->token = (t_token*)malloc(sizeof(t_token));
	new->token->str = NULL;
	new->token->count = 0;
	new->res = (t_res*)malloc(sizeof(t_res));
	ft_memdel((void**)&str);
	return ((void*)new);
}
