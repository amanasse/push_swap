/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:47:55 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/25 12:07:35 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_pile_a (t_list **a, t_list **b)
{
    int	nb_pivot;
	int	size;
	int	i;
	
	i = 0;
	size = ft_lstsize(*a);
	nb_pivot = nombre_pivot((a), size);
    while (i < size)
	{
		if ((*a)->content <= nb_pivot)
			ft_pb(a, b);
		else
			ft_ra(a);
		i++;
	}
	if (ft_lstsize(*a) > 2)
		empty_pile_a(a, b);
}

void	empty_pile_test (t_list **a, t_list **b)
{
	int count_min;
	int count_min2;
	int	size;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		count_min = find_min(*a);
		count_min2 = find_min2(*a);
		if (count_min < count_min2)
		{
			opti_division_a(a, ft_lstsize(*a), count_min);
			ft_pb(a, b);
			size--;
		}
		else
		{
			opti_division_a(a, ft_lstsize(*a), count_min2);
			ft_pb(a, b);
			size--;
		}
	}
	push_swap_3(a);
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