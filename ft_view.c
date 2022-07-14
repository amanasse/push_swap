/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:21:45 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/14 14:29:40 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_view_a(t_list *a)
{
	int i;

    i = 1;
    while (a != NULL)
    {
	    printf("a[%d] = %d. Son adresse : %p\n", i, a->content, a);
		a = a->next;
		i++;
	}
	printf("a %p\n", a);
	printf("-----------------\n");
}
void ft_view_b(t_list *b)
{
	int	i;
	
	i = 1;
	while (b != NULL)
	{
		printf("b[%d] = %d. Son adresse : %p\n", i, b->content, b);
		b = b->next;
		i++;
	}
	printf("b %p\n", b);
	printf("-----------------\n");
}
