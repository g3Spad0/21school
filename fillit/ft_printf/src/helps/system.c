/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:20:22 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/25 21:20:23 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/info.h"

void	mod_update(const char **str, int type)
{
	if (type % 2 == 0)
	{
		*str += 1;
	}
}

void	pf_putchar(char c, int *sum)
{
	write(1, &c, 1);
	*sum += 1;
}

char	*pf_get_str(int c, t_main *main)
{
	char	*new;

	new = ft_strnew(1);
	new[0] = c;
	new[1] = 0;
	if (!c)
	{
		main->is_null = 1;
	}
	return (new);
}

int		pf_flags_len(t_main *main, t_res *res)
{
	if (res->sharp)
	{
		return (main->type == 'x' || main->type == 'p'
				|| main->type == 'X' ? 2 : 1);
	}
	return (res->sign ? 1 : 0);
}
