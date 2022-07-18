/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:19:44 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/18 12:31:08 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//le premier devient le dernier 
void	ft_ra(t_list **a)
{
	t_list	*first;

	first = ft_lstnew(pop(a));
	ft_lstadd_back(a, first);
	first->next = NULL;
	write (1, "ra\n", 3);
}

void	ft_rb(t_list **b)
{
	t_list	*first;

	first = ft_lstnew(pop(b));
	ft_lstadd_back(b, first);
	first->next = NULL;
	write (1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rb(b);
	ft_ra(a);
	write (1, "rrr\n", 4);
}
