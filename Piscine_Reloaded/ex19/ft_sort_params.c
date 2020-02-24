/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:50:37 by sjamie            #+#    #+#             */
/*   Updated: 2019/09/02 22:15:45 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *string)
{
	while (*string)
	{
		ft_putchar(*string);
		string++;
	}
	return ;
}

char	**ft_sort(char **stack, int len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i <= len)
	{
		j = 1;
		while (j <= len - i - 1)
		{
			if (ft_strcmp(stack[j], stack[j + 1]) > 0)
			{
				tmp = stack[j];
				stack[j] = stack[j + 1];
				stack[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (stack);
}

int		main(int argc, char **arhv)
{
	char	**string;
	int		i;

	i = 1;
	if (argc == 1)
		return (0);
	string = ft_sort(arhv, argc - 1);
	while (i < argc)
	{
		ft_putstr(string[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
