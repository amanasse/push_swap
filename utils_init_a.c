/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:22:04 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/03 12:24:06 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long int	i;
	long int	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	nb = nb * neg;
	return (nb);
}

int	check_tab(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

void	ft_make_a_split(t_list **a, char **argv)
{
	char		**tab;
	int			i;
	t_list		*content;

	i = 0;
	tab = ft_split(argv[1]);
	if (tab == NULL || check_errors(tab) == 0)
		return ;
	while (tab[i])
	{
		content = ft_lstnew(ft_atoi(tab[i]));
		if (content == NULL)
			return ;
		ft_lstadd_back(a, content);
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_make_a_av(t_list **a, char **argv)
{
	int		i;
	long	u;
	t_list	*content;

	i = 1;
	while (argv[i])
	{
		u = ft_atoi(argv[i]);
		if (check_tab(argv[i]) == 0 || u > 2147483647 || u < -2147483648)
		{
			write(2, "Error\n", 6);
			return ;
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		content = ft_lstnew(ft_atoi(argv[i]));
		if (content == NULL)
			return ;
		ft_lstadd_back(a, content);
		i++;
	}
}

int	check_errors(char **tab)
{
	int		i;
	long	u;

	i = 0;
	while (tab[i])
	{
		u = ft_atoi(tab[i]);
		if (check_tab(tab[i]) == 0 || u > 2147483647 || u < -2147483648)
		{
			i = 0;
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
			free (tab);
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
