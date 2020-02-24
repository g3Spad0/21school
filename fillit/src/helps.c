/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:19:08 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/12 21:19:10 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	cleaner(char **array, int count)
{
	int		i;

	i = 0;
	while (i < count)
		free(array[i++]);
	free(array);
	array = NULL;
}

void	display(char *field, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(field[i * size + j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	*fillit_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size)
	{
		if (!(ptr = (unsigned char *)malloc(size)))
			return (NULL);
		while (size)
			ptr[--size] = '.';
	}
	return ((void *)ptr);
}

int		get_min_size(int count)
{
	int min_size;

	min_size = 1;
	while (min_size * min_size < count)
		min_size++;
	return (min_size);
}
