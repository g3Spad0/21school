/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:40:49 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/19 18:51:58 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void	helper(char **array, int i, int j, short *flag)
{
	if (j + 1 < 16 && j / 4 == (j + 1) / 4 && array[i][j + 1] == '#')
		*flag += 1;
	if (j - 1 >= 0 && j / 4 == (j - 1) / 4 && array[i][j - 1] == '#')
		*flag += 1;
	if (j + 4 < 16 && array[i][j + 4] == '#')
		*flag += 1;
	if (j - 4 >= 0 && array[i][j - 4] == '#')
		*flag += 1;
}

int				checker(char **array, int count)
{
	short	len;
	short	flag;
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		flag = 0;
		j = 0;
		len = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#' && ++len)
				helper(array, i, j, &flag);
			j++;
		}
		if ((flag != 6 && flag != 8) || len != 4)
			return (0);
		i++;
	}
	return (1);
}
