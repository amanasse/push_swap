/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:22:04 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/13 14:06:26 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *nptr)
{
	long int	i;
	long int	nb;
	int			neg;
	char		*str;

	i = 0;
	nb = 0;
	neg = 1;
	str = (char *)nptr;
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
	return (nb * neg);
}

int	check_tab(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_make_a_split(t_list **a, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(argv[1]);
	while (tab[i])
	{
		if (check_tab(tab[i]) == 0)
			return ;
		else
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(tab[i])));
			free(tab[i]);
		}
		i++;
	}
	ft_doublon(*a);
	free(tab);
}

void	ft_make_a_av(t_list **a, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (check_tab(argv[i]) == 0)
			return ;
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	ft_doublon(*a);
}
