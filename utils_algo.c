/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:44:00 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/13 17:43:17 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *a, int size)
{
    int min;
    int i;
    int swap;
    t_list *tmp;

    tmp = a;
    i = 0;
    printf("size = %d\n", size);
    while(tmp || i < size)
    {
        while (tmp->content > tmp->next->content)
        {
            swap = tmp->content;
            tmp->content = tmp->next->content;
            tmp->next->content = swap;
            i = -1;
        }
        i++;

    }

    return (min);




}