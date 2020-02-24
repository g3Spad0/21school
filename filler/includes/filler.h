/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:23:37 by sjamie            #+#    #+#             */
/*   Updated: 2019/11/12 20:23:38 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef	struct		s_main
{
	char			me;
	char			enemy;
	int				os_x;
	int				os_y;
	char			**map;
	int				tmp_last;
	struct s_piece	*piece;
	struct s_token	*token;
	struct s_res	*res;
}					t_main;

typedef	struct		s_piece
{
	char			**piece;
	int				first_x;
	int				first_y;
	int				piece_x;
	int				piece_y;
	int				count;
	int				flag;
}					t_piece;

typedef	struct		s_token
{
	char			*str;
	int				count;
}					t_token;

typedef	struct		s_res
{
	int				x;
	int				y;
	int				flag;
	int				score;
}					t_res;

void				fl_map_info(t_main *main, char *str);
void				fl_piece_set(t_main *main, char *str);
void				fl_map_write(char *str, t_main *main);
void				fl_piece_write(t_main *main, char *str);
void				*fl_init(int res, char *str);

void				fl_result_to_null(t_res *res);
void				clean_array_2(char **array, int count);
void				fl_update_res(t_res *main, t_res *res);
int					fl_char_check(char what, char need);
void				fl_tmp(t_main *main, char *line);

int					fl_try_include(t_main *main, int i, int j);
void				fl_include(t_main *main, int y, int x);
void				fl_clean_include(t_main *main, int y, int x);
void				fl_results(t_main *main);

void				fl_controller(t_main *main);

void				fl_(t_main *main);

void				wave_function(t_main *main, int i, int j);

void				fl_fix_norm(char *str, char flag, int j, int *what);
void				fl_push_new_result(t_res *res, int y,
						int x, int score);

#endif
