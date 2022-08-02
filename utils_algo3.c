/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:45:46 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/02 11:40:49 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_pile_test(t_list **a, t_list **b, int nb_pivot, int size)
{
	int	count_next;
	int	count_prev;
	int	i;

	i = -1;
	while (++i < size && check_pivot(a, nb_pivot) == 1)
	{
		count_next = count_min_next(a, nb_pivot);
		count_prev = count_min_prev(a, nb_pivot);
		if (count_next == 0)
			ft_pb(a, b);
		else if (count_next <= count_prev)
		{
			while (count_next-- > 0)
				ft_ra(a);
			ft_pb(a, b);
		}
		else if (count_prev < count_next)
		{
			while (count_prev-- > -1)
				ft_rra(a);
			ft_pb(a, b);
		}
	}
}

void	ft_sort_int_tab(int *tab, int size)
{	
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{	
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	*list_in_tab(t_list **a, int size)
{
	int		*tab;
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_sort_int_tab(tab, size);
	return (tab);
}

int	count_min_next(t_list **a, int nb_pivot)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->content <= nb_pivot)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	count_min_prev(t_list **a, int nb_pivot)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->content <= nb_pivot)
			break ;
		i++;
		tmp = tmp->prev;
	}
	return (i);
}
