/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:33:23 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/18 13:12:21 by amanasse         ###   ########.fr       */
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

int	ft_doublon(t_list *a)
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
				return (0);
			}
			temp = temp->next;
		}
		a = a->next;
	}
	return (1);
}

void	free_lst(t_list *a)
{
	t_list	*tmp;

	while (a != NULL)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}