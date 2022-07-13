/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:43:04 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/13 11:24:31 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pars(t_list **a)
{
	if (ft_lstsize(*a) == 2)
	{
		push_swap_2(*a);
		write (1, "sa\n", 3);
	}
	if (ft_lstsize(*a) == 3)
	{
		printf("COUCOU");
		push_swap_3(a);
	}
	if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
	{
		make_b(a, ft_lstsize(*a));
		push_swap_4_5(a);
	}
}
