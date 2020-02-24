/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 23:33:13 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/16 16:45:25 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		insert(char *field, char *tmino, int pos, int size)
{
	int		i;
	char	c;

	c = tmino[0];
	tmino++;
	i = 0;
	while (i++ < 4)
	{
		if (pos % size + tmino[0] >= 0 && pos / size + tmino[1] >= 0 &&
				pos % size + tmino[0] < size && pos / size + tmino[1] < size &&
				field[pos % size + tmino[0]
				+ size * (pos / size + tmino[1])] == '.')
		{
			field[pos % size + tmino[0]
				+ size * (pos / size + tmino[1])] = c;
			tmino += 2;
		}
		else
			return (0);
	}
	return (1);
}

void	remover(char *field, char *tmino, int pos, int size)
{
	int		i;
	char	c;

	c = tmino[0];
	tmino++;
	i = 0;
	while (i++ < 4)
	{
		if (pos % size + tmino[0] >= 0 && pos / size + tmino[1] >= 0 &&
				pos % size + tmino[0] < size &&
				pos / size + tmino[1] < size)
		{
			if (field[pos % size + tmino[0]
				+ size * (pos / size + tmino[1])] == c)
			{
				field[pos % size + tmino[0]
					+ size * (pos / size + tmino[1])] = '.';
				tmino += 2;
			}
			else
				return ;
		}
		else
			return ;
	}
}

int		check_option(char *field, char *tmino, int pos, int size)
{
	char	*ppos;

	ppos = field + pos;
	while (!insert(field, tmino, pos, size))
	{
		remover(field, tmino, pos, size);
		if (!(ppos = ft_strchr(ppos + 1, '.')))
			return (-1);
		pos = ppos - field;
		if (size - pos / size - 1 < tmino[8])
			return (-1);
		if (size - pos % size - 1 < tmino[7])
			pos += (size - pos % size);
	}
	return (pos);
}

int		recursive(char *field, char **tmino, int size, int pos)
{
	static char	*ppos1 = NULL;

	if (!ppos1 || pos == 0)
		ppos1 = field;
	if (!(*tmino))
		return (1);
	if (pos == size * size)
		return (0);
	if ((pos = check_option(field, *tmino, pos, size)) < 0)
		return (0);
	ppos1 = ft_strchr(ppos1, '.');
	if (recursive(field, tmino + 1, size, ppos1 ? ppos1 - field : size * size))
		return (1);
	remover(field, *tmino, pos, size);
	ppos1 = ft_strchr(field, '.');
	return (recursive(field, tmino, size, pos + 1));
}

void	builder(char **array, int count)
{
	int		size;
	char	*field;

	size = get_min_size(count * 4);
	field = (char *)fillit_memalloc(size * size + 1);
	field[size * size] = 0;
	while (!recursive(field, array, size, 0))
	{
		size++;
		free(field);
		field = (char *)fillit_memalloc(size * size + 1);
		field[size * size] = 0;
	}
	display(field, size);
	free(field);
}
