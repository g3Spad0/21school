/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:14:49 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/18 17:52:05 by matruman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/info.h"
#include "../includes/controls.h"

static	int		controller_free(t_main *main)
{
	int		i;

	i = main->sum;
	free(main->flag);
	free(main);
	main = NULL;
	return (i);
}

int				pf_controller(const char **str, va_list ap)
{
	t_main	*main;

	main = pf_init();
	while (**str)
	{
		if (pf_insert_flag(main->flag, **str))
			;
		else if (**str != '0' && ft_isdigit(**str))
			main->len = pf_get_num(str, 0);
		else if (**str == '.' && (main->is_pres = 1))
			main->pres = pf_get_num(str, 1);
		else if (pf_is_type(**str))
		{
			main->type = **str;
			pf_script(ap, main);
			*str += 1;
			break ;
		}
		else if ((main->mod = pf_is_mod(*str)))
			mod_update(str, main->mod);
		else
			return (controller_free(main));
		*str += 1;
	}
	return (controller_free(main));
}

int				ft_printf(const char *title, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, title);
	while (*title)
	{
		if (title[0] == '%')
		{
			title++;
			i += pf_controller(&title, ap);
			continue ;
		}
		i += 1;
		ft_putchar(*title);
		title++;
	}
	va_end(ap);
	return (i);
}
