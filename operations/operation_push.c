/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:24:12 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/14 16:12:42 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pop(t_list **pile)
{
	int		content;
	t_list	*first;

	content = 0;
	first = *pile;
	content = first->content;
	*pile = first->next;
	free (first);
	return (content);
}

void	ft_pa(t_list **a, t_list **b)
{
	if (b == NULL)
		return ;
	push(a, pop(b));
	write (1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	if (a == NULL)
		return ;
	push(b, pop(a));
	write (1, "pb\n", 3);
}

void	push(t_list **pile, int content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = *pile;
	*pile = new;
}
