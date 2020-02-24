/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:53:10 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/16 16:26:17 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			move(char **arr, int count)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < count)
	{
		j = 1;
		x = arr[i][1];
		y = arr[i][2];
		while (j < 9)
		{
			arr[i][j] = arr[i][j] - x;
			arr[i][j + 1] = arr[i][j + 1] - y;
			j += 2;
		}
		i++;
	}
}

static	void	fuck_my_code(char **arr, int i, int j, int *k)
{
	arr[i][*k] = j % 4;
	*k += 1;
	arr[i][*k] = j / 4;
	*k += 1;
}

char			**positions(char **array, int count)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	if (!(arr = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (!(arr[i] = (char*)malloc(10)))
			return (NULL);
		j = 0;
		k = 0;
		arr[i][k++] = 'A' + i;
		while (array[i][j++])
			if (array[i][j - 1] == '#')
				fuck_my_code(arr, i, j - 1, &k);
		arr[i][k] = '\0';
		i++;
	}
	arr[count] = NULL;
	return (arr);
}
