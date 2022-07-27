/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:44:00 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/27 15:04:36 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tri_a_faire(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}

int	find_min(t_list *a)
{
	int		min;
	int		i;
	int		count;
	t_list	*tmp;

	i = 0;
	count = 0;
	tmp = a;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			count = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (count);
}

int	find_min2(t_list *a)
{
	int		min;
	int		min2;
	int		i;
	int		count;
	t_list	*tmp;
	t_list	*tmp2;

	i = 0;
	count = 0;
	tmp = a;
	tmp2 = a;
	min = tmp->content;
	min2 = tmp2->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			count = i;
		}
		i++;
		tmp = tmp->next;
	}
	i = 0;
	count = 0;
	while (tmp2 != NULL)
	{
		if (tmp2->content < min2 && tmp2->content != min)
		{
			min2 = tmp2->content;
			count = i;
		}
		i++;
		tmp2 = tmp2->next;
	}
	return (count);
}

int	find_max(t_list *a)
{
	int		max;
	int		i;
	int		count;
	t_list	*tmp;

	i = 0;
	count = 0;
	tmp = a;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			count = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (count);
}

int	nombre_pivot(t_list **a, int size)
{
	t_list	*tmp;
	int		resultat;

	tmp = *a;
	resultat = 0;
	while (tmp != NULL)
	{
		resultat += tmp->content;
		tmp = tmp->next;
	}
	resultat = resultat / size;
	return (resultat);
}