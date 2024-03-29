/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:48:45 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/02 11:46:42 by amanasse         ###   ########.fr       */
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
		opti_division_a(a, ft_lstsize(*a), count_min);
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

void	push_swap_21_to_100(t_list **a, t_list **b)
{
	int	size;
	int	stock_tab_median;
	int	count_max;

	stock_tab_median = ft_lstsize(*a) / 5;
	ft_median_100(a, b, stock_tab_median);
	size = ft_lstsize(*b);
	while (size > 0)
	{
		count_max = find_count_max(*b);
		opti_division_b(b, ft_lstsize(*b), count_max);
		ft_pa(a, b);
		size--;
	}
}

void	push_swap_101_to_infinity(t_list **a, t_list **b)
{
	int	size;
	int	stock_tab_median;
	int	count_max;

	stock_tab_median = ft_lstsize(*a) / 11;
	ft_median_500(a, b, stock_tab_median);
	size = ft_lstsize(*b);
	while (size > 0)
	{
		count_max = find_count_max(*b);
		opti_division_b(b, ft_lstsize(*b), count_max);
		ft_pa(a, b);
		size--;
	}
}
