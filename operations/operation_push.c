/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:24:12 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/03 11:18:42 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pop(t_list **pile)
{
	int		content;
	t_list	*first;
	t_list	*tmp;

	content = 0;
	first = *pile;
	content = first->content;
	tmp = first;
	*pile = first->next;
	if (*pile != NULL)
		(*pile)->prev = NULL;
	free(tmp);
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

	new = ft_lstnew(content);
	if (new == NULL)
		return ;
	new->next = *pile;
	new->prev = NULL;
	if (*pile != NULL)
		(*pile)->prev = new;
	*pile = new;
}
