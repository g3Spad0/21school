/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:15:06 by sjamie            #+#    #+#             */
/*   Updated: 2019/10/05 17:15:07 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 256
# define FD_MAX 4864

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

char			**fillit_strsplit(char const *str, char c);
void			algoritm(int **arr, int count);
void			builder(char **array, int count);
int				get_min_size(int count);
void			display(char *field, int size);
void			*fillit_memalloc(size_t size);
void			cleaner(char **array, int count);
int				checker(char **array, int count);
char			**positions(char **array, int count);
void			move(char **arr, int count);
int				handler(char *str, int i);

#endif
