/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:57:48 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/07 20:57:49 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/info.h"

int				flags_for_minus(int type)
{
	return (type == 'd' || type == 'i' || type == 'f' ? 1 : 0);
}

t_res			*flags_init(char *s)
{
	t_res	*new;

	new = (t_res*)malloc(sizeof(t_res));
	new->sign = 0;
	new->left = 0;
	new->items = 0;
	new->sharp = 0;
	new->str = s;
	return (new);
}

void			flags_sign(t_main *main, t_res *res, char *str)
{
	if (flags_for_minus(main->type) && str[0] != '-')
	{
		if (main->flag->f_2)
		{
			res->sign = main->flag->f_2;
		}
		else if (!main->flag->f_2 && main->flag->f_3)
		{
			res->sign = ' ';
		}
	}
}

void			flags_sharp(t_main *main, t_res *res)
{
	if (main->flag->f_4 && pf_is_for_sharp(main->type) && !main->is_only_0 &&
		!(main->type == 'o' && main->is_pres == 2))
	{
		res->sharp = 1;
	}
	if (main->type == 'o' && main->flag->f_4 && main->is_pres && !main->pres)
	{
		res->sharp = 1;
	}
	if (main->flag->f_4 && main->type == 'p')
	{
		res->sharp = 1;
	}
}

void			flags_items(t_main *main, t_res *res)
{
	res->items = ' ';
	if (!main->flag->f_1 && main->flag->f_5 && !main->is_pres)
	{
		res->items = '0';
		return ;
	}
	else if (main->flag->f_1)
	{
		res->left = 1;
		return ;
	}
}
