/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:14:49 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/18 17:52:05 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		controller(char *str, int count)
{
	char	**arr;
	char	**ready;

	if (!(count = handler(str, 0)))
	{
		ft_memdel((void**)&str);
		return (write(1, "error\n", 6));
	}
	arr = fillit_strsplit(str, 'D');
	ft_memdel((void**)&str);
	if (!checker(arr, count))
	{
		cleaner(arr, count);
		return (write(1, "error\n", 6));
	}
	if (!(ready = positions(arr, count)))
	{
		cleaner(arr, count);
		return (write(1, "error\n", 6));
	}
	cleaner(arr, count);
	move(ready, count);
	builder(ready, count);
	cleaner(ready, count);
	return (0);
}

void	reader(int ch)
{
	size_t	tmp;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*temp;

	str = NULL;
	if (!(str = ft_strnew(0)))
		return ;
	while ((tmp = read(ch, buf, BUFF_SIZE)))
	{
		buf[tmp] = '\0';
		if (ft_strlen(buf) < tmp)
			buf[0] = 'x';
		temp = ft_strjoin(str, buf);
		free(str);
		str = temp;
	}
	if (close(ch) == -1)
	{
		write(1, "error\n", 6);
		free(str);
		return ;
	}
	controller(str, 0);
}

int		main(int argc, char **argv)
{
	int		ch;
	char	temp[1];

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if ((ch = open(argv[1], O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (read(ch, temp, 0) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	reader(ch);
	return (0);
}
