/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:25:46 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/25 21:25:47 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/info.h"

static	char	*ft_itoa_costil(void)
{
	char *string;

	if ((string = (char*)malloc(1 * sizeof(char) + 1)) == NULL)
		return (NULL);
	string[0] = '0';
	string[1] = '\0';
	return (string);
}

static	int		ft_itoa_dop_u(unsigned long long int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	int		ft_itoa_dop(long long int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*pf_itoa(long long int n, t_main *main)
{
	size_t	i;
	char	*string;
	char	znak;

	znak = -1;
	if (n == 0)
		return (ft_itoa_costil());
	i = ft_itoa_dop(n);
	if ((string = (char*)malloc(i * sizeof(char) + 1)) == NULL)
		return (NULL);
	if (n < 0)
	{
		main->is_minus = 1;
		znak = 1;
	}
	string[i--] = '\0';
	while (n)
	{
		string[i] = 48 - (znak * (n % 10));
		i--;
		n /= 10;
	}
	return (string);
}

char			*pf_itoa_uns(unsigned long long int n)
{
	size_t	i;
	char	*string;

	if (n == 0)
		return (ft_itoa_costil());
	i = ft_itoa_dop_u(n);
	if ((string = (char*)malloc(i * sizeof(char) + 1)) == NULL)
		return (NULL);
	string[i--] = '\0';
	while (n)
	{
		string[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
	return (string);
}
