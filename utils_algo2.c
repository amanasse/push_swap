/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:47:55 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/01 18:38:56 by amanasse         ###   ########.fr       */
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

void	empty_pile_test(t_list **a, t_list **b, int nb_pivot)
{
	int	count_next;
	int	count_prev;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size && check_pivot(a, nb_pivot) == 1 && nb_pivot != 0)
	{
		count_next = count_min_next(a, nb_pivot);
		count_prev = count_min_prev(a, nb_pivot);
		if (count_next == 0)
			ft_pb(a, b);
		else if (count_next <= count_prev)
		{
			while (count_next > 0)
			{
				ft_ra(a);
				count_next--;
			}
			ft_pb(a, b);
		}
		else if (count_prev < count_next)
		{
			while (count_prev > -1)
			{
				ft_rra(a);
				count_prev--;
			}
			ft_pb(a, b);
		}
		i++;
	}
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
