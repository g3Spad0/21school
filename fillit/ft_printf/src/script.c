/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:57:05 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/22 20:57:07 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/info.h"

static	char	*handler(va_list ap, t_main *main, int tmp)
{
	char	*str;

	str = NULL;
	if (main->type == 's')
		str = ft_strdup((char*)va_arg(ap, char *));
	else if (main->type == 'c')
		str = pf_get_str((char)va_arg(ap, int), main);
	else if (main->type == 'p')
		str = pf_sixteenfold(va_arg(ap, size_t), 87);
	else if (pt_is_numbers(main->type))
	{
		if (main->mod)
			str = handler_mod(ap, main->mod, tmp, main);
		else
			str = numbers_handler(ap, main->type, main);
	}
	else if (main->type == 'f')
		str = floats_hangler(ap, main);
	if (pf_is_for_sharp(main->type) && str[0] == '0' && str[1] == '\0')
		main->is_only_0 = 1;
	return (str);
}

static	void	precision(char **str, t_main *main, int len)
{
	char	*tmp;

	tmp = NULL;
	if (!main->is_pres || main->type == 'f')
		return ;
	if (!main->pres && len == 1 && **str == '0')
	{
		**str = '\0';
		return ;
	}
	if (main->type == 's' && main->pres < len)
	{
		tmp = precision_string(*str, main->pres);
		ft_memdel((void**)str);
		*str = tmp;
	}
	else if ((pt_is_numbers(main->type) || main->type == 'p')
		&& main->pres > len)
	{
		tmp = precision_num(*str, main->pres, len, &main->is_pres);
		ft_memdel((void**)str);
		*str = tmp;
	}
}

static	void	converter(char *str, t_main *main)
{
	t_res	*flags;

	flags = flags_init(str);
	flags_sign(main, flags, str);
	flags_sharp(main, flags);
	flags_items(main, flags);
	flags_calc(main, flags, &str);
	ft_memdel((void**)&flags);
	if (main->type == 'c' && main->is_null && main->len)
		str[ft_strlen(str) - 1] = '\0';
	if (main->type == 'c' && main->is_null && main->flag->f_1)
		pf_putchar(0, &main->sum);
	main->sum += ft_strlen(str);
	ft_putstr(str);
	if (main->type == 'c' && main->is_null && !main->flag->f_1)
		pf_putchar(0, &main->sum);
	ft_memdel((void**)&str);
}

void			pf_script(va_list ap, t_main *main)
{
	char	*res;

	if (main->type == '%')
	{
		res = pf_get_str('%', main);
		main->type = 'c';
	}
	else
		res = handler(ap, main, pf_is_minus(main->type));
	if (main->is_minus)
		main->flag->f_2 = '-';
	if (!res && main->type == 's')
	{
		ft_memdel((void **)&res);
		res = ft_strdup("(null)");
	}
	precision(&res, main, ft_strlen(res));
	if (main->type == 'p')
		main->flag->f_4 = '#';
	converter(res, main);
}
