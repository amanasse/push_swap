/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:44:00 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/14 14:18:29 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int tri_a_faire(t_list *a)
{
    while (a->next != NULL)
    {
        if (a->content > a->next->content)
            return(1);
        a = a->next;
    }
    return(0);
}

int	find_min(t_list *a, int size)
{
    int min;
    int i;
    int count;
    t_list *tmp;

    i = 0;
    count = 0;
    tmp = a;
    min = tmp->content;
    printf("size = %d\n", size);
    (void)size;
    while(tmp != NULL)
    {
        if (tmp->content < min)
        {
            min = tmp->content;
            count = i;
        }
        i++;    
        tmp = tmp->next;
    }
    printf("count = %d\n", count);
    return (count);
}

void opti_division(t_list **a, int size, int count_min)
{
	if(count_min <= size / 2)
	{
		while (count_min > 0)
		{
			ft_ra(a);
			count_min--;
		}
	}
	else
	{
		while(count_min < ft_lstsize(*a))
		{
			ft_rra(a);
			count_min++;
		}
	}
}


// * *a

// ptr -> 0x01

// 0x01 -> a

// *a -> 0x02

// 0x02 a[0]