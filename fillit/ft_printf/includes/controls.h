/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:43:45 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/22 20:43:46 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

int		pf_insert_flag(t_flag *flag, int c);
int		pf_get_num(const char **str, int flag);
int		pf_is_mod(const char *str);
int		pf_is_type(int c);
void	mod_update(const char **str, int type);
t_main	*pf_init(void);

#endif
