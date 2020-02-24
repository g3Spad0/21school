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

#include "../../includes/push_swap.h"
#include "../../includes/checker.h"

int		main(int argc, char **argv)
{
	t_main	*main;
	char	*line;

	main = ps_init(argv, argc);
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		prolog(main, line);
		ft_memdel((void**)&line);
	}
	epilog(main);
	return (0);
}
