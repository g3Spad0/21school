/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:29:14 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/31 19:29:21 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/info.h"

static	void	pf_for_concat_memdel(char **new, char *tmp)
{
	if (tmp)
	{
		ft_memdel((void**)new);
		*new = tmp;
	}
}

void			pf_for_concat(char **new, t_main *main, t_res *res)
{
	char	*tmp;

	tmp = NULL;
	if (res->sharp && main->type != 'f')
	{
		if (main->type == 'x' || main->type == 'p')
			tmp = ft_strjoin("0x", *new);
		else if (main->type == 'X')
			tmp = ft_strjoin("0X", *new);
		else if (main->type == 'o')
			tmp = ft_strjoin("0", *new);
		pf_for_concat_memdel(new, tmp);
		return ;
	}
	if (res->sign == '+' && flags_for_minus(main->type))
		tmp = ft_strjoin("+", *new);
	else if (res->sign == '-' && flags_for_minus(main->type))
		tmp = ft_strjoin("-", *new);
	else if (res->sign == ' ' && flags_for_minus(main->type))
		tmp = ft_strjoin(" ", *new);
	pf_for_concat_memdel(new, tmp);
}

char			*pf_flags_new_str(char *str, int size, char what, int left)
{
	char	*new;
	int		i;
	int		j;

	new = (char*)ft_strnew(size);
	new[size] = '\0';
	i = 0;
	j = ft_strlen(str);
	if (left)
	{
		while (size-- > j)
			new[size] = what;
		while (j--)
			new[j] = str[j];
		return (new);
	}
	while (i++ < size - j)
		new[i - 1] = what;
	while (*str)
	{
		new[i++ - 1] = *str;
		str++;
	}
	return (new);
}

void			flags_calc(t_main *main, t_res *res, char **str)
{
	char	*new;
	int		count;
	int		tmp;

	tmp = pf_flags_len(main, res);
	count = ft_strlen(*str) + tmp;
	if (count >= main->len)
	{
		pf_for_concat(str, main, res);
		return ;
	}
	if (res->items == '0' && !main->is_pres)
	{
		new = pf_flags_new_str(*str, main->len - tmp, res->items, 0);
		pf_for_concat_memdel(str, new);
	}
	pf_for_concat(str, main, res);
	if (res->items == ' ')
	{
		new = pf_flags_new_str(*str, main->len, res->items, res->left);
		pf_for_concat_memdel(str, new);
	}
}
