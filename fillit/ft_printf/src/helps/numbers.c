/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:43:14 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/26 17:43:16 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/info.h"

static	char	*handler_result(long long int ps,
								unsigned long long int ms,
								char type, t_main *main)
{
	if (!ms)
		return (pf_itoa(ps, main));
	if (type == 'u')
		return (pf_itoa_uns(ms));
	else if (type == 'o')
		return (pf_eightfold(ms));
	else if (type == 'X' || type == 'x')
		return (pf_sixteenfold(ms, type - 33));
	return (NULL);
}

char			*handler_mod(va_list ap, int mod,
							int minus, t_main *main)
{
	unsigned long long int	ms;
	long long int			ps;

	ps = 0;
	ms = 0;
	if (mod == 1)
		minus ? (ms = (unsigned short int)va_arg(ap, unsigned int))
			: (ps = (short int)va_arg(ap, int));
	else if (mod == 2)
		minus ? (ms = (unsigned char)va_arg(ap, unsigned int))
			: (ps = (char)va_arg(ap, int));
	else if (mod == 3)
		minus ? (ms = va_arg(ap, unsigned long int))
			: (ps = va_arg(ap, long int));
	else if (mod == 4)
		minus ? (ms = va_arg(ap, unsigned long long int))
			: (ps = va_arg(ap, long long int));
	return (handler_result(ps, ms, main->type, main));
}

char			*numbers_handler(va_list ap, char type, t_main *main)
{
	unsigned int	ms;
	int				ps;

	ms = 0;
	ps = 0;
	if (type == 'd' || type == 'i')
	{
		ps = va_arg(ap, int);
		return (handler_result(ps, ms, type, main));
	}
	ms = va_arg(ap, unsigned int);
	return (handler_result(ps, ms, type, main));
}

char			*floats_hangler(va_list ap, t_main *main)
{
	char	*str;
	int		pres;

	pres = !main->is_pres ? 6 : main->pres;
	if (main->mod == 5)
		str = pf_dltoa(va_arg(ap, long double), pres, main);
	else
		str = pf_ftoa(va_arg(ap, double), pres, main);
	main->is_pres = 0;
	if (!main->flag->f_4 && (pres = floats_pointer(str)))
		str[pres] = 0;
	return (str);
}
