/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:29:41 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/26 22:29:42 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char			*precision_num(char *str, int pres, int len, int *is_pres)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_strnew(pres);
	while (i < pres)
	{
		if (i + len >= pres)
		{
			new[i] = str[j];
			j++;
		}
		else
		{
			new[i] = '0';
			*is_pres = 2;
		}
		i++;
	}
	new[i] = 0;
	return (new);
}

char			*precision_string(char *str, int pres)
{
	int		i;
	char	*new;

	if (pres <= 0)
		pres = 0;
	new = ft_strnew(pres);
	i = 0;
	while (i < pres)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
