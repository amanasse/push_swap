/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:33:23 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/14 15:51:26 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	else
		element->content = content;
	element->next = NULL;
	return (element);
}

void	ft_doublon(t_list *a)
{
	t_list	*temp;

	while (a->next != NULL)
	{
		temp = a->next;
		while (temp != NULL)
		{
			if (a->content == temp->content)
			{
				write(2, "Error\n", 6);
				return ;
			}
			temp = temp->next;
		}
		a = a->next;
	}
}
