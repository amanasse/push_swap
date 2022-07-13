/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:48:45 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/13 14:13:23 by amanasse         ###   ########.fr       */
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
	if ((*a)->content > (*a)->next->content)
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
	else if ((*a)->content < (*a)->next->content)
	{
		if((*a)->next->content < (*a)->next->next->content)
				return ;
		ft_rra(a);
		if ((*a)->content > (*a)->next->content)
			ft_sa(*a);
	}
}

void push_swap_4(t_list **a, t_list **b)
{
	int min;

	min = find_min(a, ft_lstsize(*a));
	printf("min = %d\n", min);
	printf("size = %d\n", ft_lstsize(*a));
	printf("size = %d\n", ft_lstsize(*b));








}