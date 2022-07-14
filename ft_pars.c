/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:43:04 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/14 14:17:19 by amanasse         ###   ########.fr       */
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
		if (ft_lstsize(*a) == 4)
			push_swap_4(a, b);
		if (ft_lstsize(*a) == 5)
			push_swap_5(a, b);
	}
	else	
		return ;
}
