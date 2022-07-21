/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:43:04 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/21 17:37:54 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pars(t_list **a, t_list **b)
{
	if (tri_a_faire(*a) == 1)
	{	
		if (ft_lstsize(*a) == 2)
			push_swap_2(*a);
		if (ft_lstsize(*a) == 3)
			push_swap_3(a);
		if (ft_lstsize(*a) >= 4 && ft_lstsize(*a) <= 20)
			push_swap_4_to_20(a, b);
		if (ft_lstsize(*a) >= 21 && ft_lstsize(*a) <= 100)
			push_swap_101_to_infinity(a, b);
		if (ft_lstsize(*a) >= 101)
			push_swap_101_to_infinity(a, b);
	}
	else
		return ;
}
