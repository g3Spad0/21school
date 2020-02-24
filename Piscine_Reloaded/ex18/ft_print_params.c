/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:41:59 by sjamie            #+#    #+#             */
/*   Updated: 2019/09/02 19:50:25 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **arhv)
{
	int i;
	int j;

	i = 1;
	if (argc > 1)
	{
		while (i != argc)
		{
			j = 0;
			while (arhv[i][j] != '\0')
			{
				ft_putchar(arhv[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
