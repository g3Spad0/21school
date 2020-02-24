/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:09:45 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/24 19:09:47 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PUSH_SWAP_H
# define S_PUSH_SWAP_H

typedef struct		s_sort
{
	int				pivat;
	int				min;
	int				max;
	int				num;
	struct s_main	*main;
	struct s_data	*data;
	int				*array;
	size_t			count;
	size_t			i;
}					t_sort;

typedef struct		s_data
{
	int				pivat;
	int				min;
	int				max;
}					t_data;

int					is_sort(t_main *main, int b_flag);
void				sorting(t_sort *sort);
void				*sorting_init(t_main *main);
void				bubble_sort(t_sort *sort);
int					check_stack_a(t_sort *sort);
int					check_stack_b(t_sort *sort);
int					is_needle(t_sort *sort);
int					calc_to_top(t_sort *sort);

#endif
