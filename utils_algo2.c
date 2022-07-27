/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:47:55 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/27 17:22:36 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_min_next(t_list **a, int nb_pivot)
{
	t_list *tmp;
	int i;

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
	t_list *tmp;
	int i;

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

void	empty_pile_a(t_list **a, t_list **b)
{
	int	nb_pivot;
	int	size;
	int	i;

	printf("TEST\n");
	i = 0;
	size = ft_lstsize(*a);
	nb_pivot = nombre_pivot((a), size);
	while (i < size)
	{
		if ((*a)->content <= nb_pivot)
			ft_pb(a, b);
		else
			ft_ra(a);
		i++;
	}
	if (ft_lstsize(*a) > 2)
		empty_pile_a(a, b);
}

int	check_pivot(t_list **a, int nb_pivot)
{
	t_list *tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->content <= nb_pivot)
			return(1);
		tmp = tmp->next;
	}
	return (0);


}
void	empty_pile_test(t_list **a, t_list **b)
{
	int	count_next;
	int	count_prev;
	// int	size;

	// size = ft_lstsize(*a);
	// while (size > 3)
	// {
	// 	count_min = find_min(*a);
	// 	count_min2 = find_min2(*a);
	// 	if (count_min < count_min2)
	// 	{
	// 		opti_division_a(a, ft_lstsize(*a), count_min);
	// 		ft_pb(a, b);
	// 		size--;
	// 	}`
	// 	else
	// 	{
	// 		opti_division_a(a, ft_lstsize(*a), count_min2);
	// 		ft_pb(a, b);
	// 		size--;
	// 	}
	// }
	// push_swap_3(a);
	int	nb_pivot;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*a);
	nb_pivot = nombre_pivot(a, size);
	// printf("nb_pivot = %d\n", nb_pivot);
	while (i < size && check_pivot(a, nb_pivot) == 1)
	{
		count_next = count_min_next(a, nb_pivot);
		count_prev = count_min_prev(a, nb_pivot);
		// printf("count_next = %d\n", count_next);
		// printf("count_prev = %d\n", count_prev);
		// ft_view_a(*a);
		if (count_next == 0)
		{
			ft_pb(a, b);
			i++;
			break;
		}
		else if (count_next <= count_prev)
		{
			while (count_next > 0)
			{
				ft_ra(a);
				count_next--;
			}
		} 
		else if (count_prev < count_next)
		{
			while (count_prev > -1)
			{
				ft_rra(a);
				count_prev--;
			}
		}
		ft_pb(a, b);
		i++;
	}
	if (ft_lstsize(*a) > 3)
		empty_pile_test(a, b);
	
}

void	opti_division_a(t_list **a, int size, int count_min)
{
	if (count_min <= size / 2)
	{
		while (count_min > 0)
		{
			ft_ra(a);
			count_min--;
		}
	}
	else
	{
		while (count_min < ft_lstsize(*a))
		{
			ft_rra(a);
			count_min++;
		}
	}
}

void	opti_division_b(t_list **a, int size, int count_min)
{
	if (count_min <= size / 2)
	{
		while (count_min > 0)
		{
			ft_rb(a);
			count_min--;
		}
	}
	else
	{
		while (count_min < ft_lstsize(*a))
		{
			ft_rrb(a);
			count_min++;
		}
	}
}
