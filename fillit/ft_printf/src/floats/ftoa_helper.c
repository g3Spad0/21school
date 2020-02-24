/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:42:46 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/07 18:42:47 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int				floats_pointer(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (!str[i] && str[i - 1] == '.' ? i - 1 : 0);
}

static	void	pf_reverse(char *s)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

char			*ftoa_result_str(unsigned long long int nb, char *res)
{
	char	arr[40];
	int		i;

	i = 0;
	if (!nb)
		arr[i++] = '0';
	while (nb)
	{
		arr[i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	arr[i] = 0;
	pf_reverse(arr);
	return (ft_strjoin(arr, res));
}

void			rounding_str(char *str, int max)
{
	str[max] += 5;
	while (max)
	{
		if (str[max] > '9')
		{
			str[max] = '0';
			str[max - 1] += 1;
		}
		max--;
	}
}
