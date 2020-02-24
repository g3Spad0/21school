/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:58:30 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/22 20:58:31 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef	struct		s_res
{
	char			sign;
	char			items;
	char			left;
	char			sharp;
	char			*str;
}					t_res;

typedef	struct		s_flag
{
	char			f_1;
	char			f_2;
	char			f_3;
	char			f_4;
	char			f_5;
}					t_flag;

typedef	struct		s_main
{
	struct s_flag	*flag;
	int				len;
	int				pres;
	int				is_pres;
	char			is_null;
	char			is_minus;
	char			is_only_0;
	int				mod;
	int				sum;
	char			type;
}					t_main;

void				pf_putchar(char c, int *sum);
void				pf_script(va_list ap, t_main *main);
int					pf_is_num(int c);
int					pt_is_numbers(int c);
int					pf_is_minus(int c);
int					pf_is_for_sharp(int c);
int					pf_flags_len(t_main *main, t_res *res);
char				*pf_eightfold(size_t num);
char				*pf_get_str(int c, t_main *main);
char				*pf_itoa(long long int n, t_main *main);
char				*pf_itoa_uns(unsigned long long int n);
char				*pf_sixteenfold(size_t num, int let);
char				*pf_for_sharp(char **str, char type);
char				*handler_mod(va_list ap, int mod, int minus, t_main *main);
char				*numbers_handler(va_list ap, char type, t_main *main);
char				*precision_num(char *str, int pres, int len, int *is_pres);
char				*precision_string(char *str, int pres);
char				*floats_hangler(va_list ap, t_main *main);
int					pf_atoi(const char *str);
t_res				*flags_init(char *s);
void				flags_sign(t_main *main, t_res *res, char *str);
void				flags_sharp(t_main *main, t_res *res);
void				flags_items(t_main *main, t_res *res);
void				flags_calc(t_main *main, t_res *res, char **str);
char				*ftoa_result_str(unsigned long long int nb, char *res);
void				rounding_str(char *str, int max);
char				*pf_ftoa(double num, int pres, t_main *main);
int					floats_pointer(char *str);
char				*pf_dltoa(long double num, int pres, t_main *main);
int					flags_for_minus(int type);

#endif
