/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:51:14 by sjamie            #+#    #+#             */
/*   Updated: 2019/09/02 21:00:34 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstring(char *string)
{
	while (*string)
	{
		ft_putchar(*string);
		string++;
	}
	return ;
}

void	show_file(char *string)
{
	int		ch;
	char	reader[BUF_SIZE + 1];
	int		tmp;

	if ((ch = open(string, O_RDONLY)) == -1)
	{
		write(2, "Open errors\n", 12);
		close(ch);
		return ;
	}
	while ((tmp = read(ch, reader, BUF_SIZE)) != '\0')
	{
		reader[tmp] = '\0';
		ft_putstring(reader);
	}
	if (close(ch) == -1)
		write(2, "Close() errors\n", 15);
	return ;
}

int		main(int argc, char **arhv)
{
	if (argc <= 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	else
		show_file(arhv[1]);
	return (0);
}
