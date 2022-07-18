/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:48:45 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/18 18:30:23 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_2(t_list *a)
{
	if (a->content > a->next->content)
		ft_sa(a);
}

void	push_swap_3(t_list **a)
{
	if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->next->content < (*a)->next->next->content)
			return ;
		ft_rra(a);
		if ((*a)->content > (*a)->next->content)
			ft_sa(*a);
	}
	else if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			ft_sa(*a);
			ft_rra(a);
		}
		else if ((*a)->next->content < (*a)->next->next->content)
		{
			if ((*a)->content < (*a)->next->next->content)
				ft_sa(*a);
			else
				ft_ra(a);
		}
	}
}

void	push_swap_4_to_20(t_list **a, t_list **b)
{
	int	count_min;
	int	size;
	int	size_tmp;

	size_tmp = ft_lstsize(*a);
	size = ft_lstsize(*a);
	while (size > 3)
	{
		count_min = find_min(*a);
		opti_division(a, ft_lstsize(*a), count_min);
		ft_pb(a, b);
		size--;
	}
	push_swap_3(a);
	while (size < size_tmp)
	{
		ft_pa(a, b);
		size++;
	}
}

void	push_swap_21_to_1000(t_list **a, t_list **b)
{
	int	nb_pivot;
	int	size;
	int	i;
	int	count_max;

	i = 0;
	size = ft_lstsize(*a);
	nb_pivot = nombre_pivot((a), size);
	printf("pivot = %d\n", nb_pivot);
	while (i < size)
	{
		if ((*a)->content <= nb_pivot)
			ft_pb(a, b);
		else if ((*a)->content > nb_pivot)
			ft_ra(a);
		i++;
	}
	ft_view_a(*a);
	ft_view_b(*b);
	if (ft_lstsize(*a) > 2)
		push_swap_21_to_1000(a, b);
	size = ft_lstsize(*b);
	while (size > 0)
	{
		count_max = find_max(*b);
		opti_division(b, ft_lstsize(*b), count_max);
		ft_pa(a, b);
		size--;
	}
}