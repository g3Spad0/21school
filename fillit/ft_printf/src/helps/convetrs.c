/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convetrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:20:45 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/25 21:20:46 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char				*pf_eightfold(size_t num)
{
	char	arr[16];
	char	*rew;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!num)
		arr[i++] = 0;
	while (num)
	{
		arr[i++] = num % 8;
		num /= 8;
	}
	rew = ft_strnew(i);
	while (i)
		rew[j++] = arr[--i] + 48;
	rew[j] = 0;
	return (rew);
}

static	char		to_sixteenfold(int c, int let)
{
	return (c >= 10 ? c + let : c + 48);
}

char				*pf_sixteenfold(size_t num, int let)
{
	char	arr[16];
	char	*rew;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!num)
		arr[i++] = 48;
	while (num)
	{
		arr[i++] = to_sixteenfold(num % 16, let);
		num /= 16;
	}
	rew = ft_strnew(i);
	while (i)
		rew[j++] = arr[--i];
	rew[j] = 0;
	return (rew);
}
