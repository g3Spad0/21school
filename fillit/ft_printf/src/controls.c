/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:36:45 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/20 19:36:46 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/info.h"

int		pf_insert_flag(t_flag *flag, int c)
{
	if (c == '-')
	{
		flag->f_1 = '-';
		return (1);
	}
	else if (c == '+')
	{
		flag->f_2 = '+';
		return (1);
	}
	else if (c == ' ')
	{
		flag->f_3 = ' ';
		return (1);
	}
	else if (c == '#')
	{
		flag->f_4 = '#';
		return (1);
	}
	else if (c == '0')
		return ((flag->f_5 = '0'));
	return (0);
}

int		pf_get_num(const char **str, int flag)
{
	int		res;

	if (flag)
		*str += 1;
	res = pf_atoi(*str);
	while (ft_isdigit(**str))
		*str += 1;
	*str -= 1;
	return (res);
}

int		pf_is_mod(const char *str)
{
	if (*str == 'h')
	{
		return (str[1] == 'h' ? 2 : 1);
	}
	else if (*str == 'l')
	{
		return (str[1] == 'l' ? 4 : 3);
	}
	else if (*str == 'L')
	{
		return (5);
	}
	return (0);
}

int		pf_is_type(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f'
			|| c == '%' ? c : 0);
}

t_main	*pf_init(void)
{
	t_main	*new;

	if (!(new = (t_main*)malloc(sizeof(t_main))))
		return (NULL);
	new->len = 0;
	new->pres = 0;
	new->is_pres = 0;
	new->is_null = 0;
	new->is_minus = 0;
	new->is_only_0 = 0;
	new->mod = 0;
	new->type = 0;
	new->sum = 0;
	new->flag = (t_flag*)malloc(sizeof(t_flag));
	new->flag->f_1 = 0;
	new->flag->f_2 = 0;
	new->flag->f_3 = 0;
	new->flag->f_4 = 0;
	new->flag->f_5 = 0;
	return (new);
}
