/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:42:16 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/07 18:42:19 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/info.h"

static	char	*get_result(double num, int pres,
							unsigned long long int *result)
{
	long double	res;
	long double	nb;
	char		arr[pres + 3];
	int			i;

	arr[0] = '1';
	i = 0;
	res = num - (unsigned long long int)num;
	nb = 10.0;
	while (i++ < pres + 1)
	{
		arr[i] = ((unsigned long long int)(res * nb) % 10) + 48;
		nb *= 10.0;
	}
	arr[pres + 2] = 0;
	rounding_str(arr, pres + 1);
	if (arr[0] == '2')
		*result += 1;
	arr[0] = '.';
	arr[pres + 1] = 0;
	return (ftoa_result_str(*result, arr));
}

static	char	*get_result_ld(long double num, int pres,
							unsigned long long int *result)
{
	long double	res;
	long double	nb;
	char		arr[pres + 3];
	int			i;

	arr[0] = '1';
	i = 0;
	res = num - (unsigned long long int)num;
	nb = 10.0;
	while (i++ < pres + 1)
	{
		arr[i] = ((unsigned long long int)(res * nb) % 10) + 48;
		nb *= 10.0;
	}
	arr[pres + 2] = 0;
	rounding_str(arr, pres + 1);
	if (arr[0] == '2')
		*result += 1;
	arr[0] = '.';
	arr[pres + 1] = 0;
	return (ftoa_result_str(*result, arr));
}

char			*pf_ftoa(double num, int pres, t_main *main)
{
	unsigned long long int	nb;

	if (num < 0)
	{
		num *= -1;
		main->is_minus = 1;
	}
	nb = (unsigned long long int)num;
	return (get_result(num, pres, &nb));
}

char			*pf_dltoa(long double num, int pres, t_main *main)
{
	unsigned long long int	nb;

	if (num < 0)
	{
		num *= -1;
		main->is_minus = 1;
	}
	nb = (unsigned long long int)num;
	return (get_result_ld(num, pres, &nb));
}
