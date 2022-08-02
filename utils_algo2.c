/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:47:55 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/02 15:16:33 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pivot(t_list **a, int nb_pivot)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->content <= nb_pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	opti_division_a(t_list **a, int size, int count_min)
{
	if (count_min <= size / 2)
	{
		while (count_min > 0)
		{
			ft_ra(a);
			count_min--;
		}
	}
	else
	{
		while (count_min < ft_lstsize(*a))
		{
			ft_rra(a);
			count_min++;
		}
	}
}

void	opti_division_b(t_list **a, int size, int count_min)
{
	if (count_min <= size / 2)
	{
		while (count_min > 0)
		{
			ft_rb(a);
			count_min--;
		}
	}
	else
	{
		while (count_min < ft_lstsize(*a))
		{
			ft_rrb(a);
			count_min++;
		}
	}
}

void	ft_median_100(t_list **a, t_list **b, int stock_tab_median)
{
	int	i;
	int	*tab;
	int	new_mediane;

	i = -1;
	while (++i < 5 && a != NULL)
	{
		tab = list_in_tab(a, ft_lstsize(*a));
		if (tab == NULL)
			return ;
		if (ft_lstsize(*a) > stock_tab_median)
		{
			new_mediane = tab[stock_tab_median];
			free(tab);
		}
		else
		{
			while (ft_lstsize(*a) > 0)
				ft_pb(a, b);
			free(tab);
			break ;
		}
		empty_pile_test(a, b, new_mediane, ft_lstsize(*a));
	}
}

void	ft_median_500(t_list **a, t_list **b, int stock_tab_median)
{
	int	i;
	int	*tab;
	int	new_mediane;

	i = -1;
	while (++i < 11 && a != NULL)
	{
		tab = list_in_tab(a, ft_lstsize(*a));
		if (tab == NULL)
			return ;
		if (ft_lstsize(*a) > stock_tab_median)
		{
			new_mediane = tab[stock_tab_median];
			free(tab);
		}
		else
		{
			while (ft_lstsize(*a) > 0)
				ft_pb(a, b);
			free(tab);
			break ;
		}
		empty_pile_test(a, b, new_mediane, ft_lstsize(*a));
	}
}
