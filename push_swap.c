/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:56 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/01 17:41:47 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_view_a(t_list *a)
{
	int	i;

	i = 1;
    while (a->next != NULL)
    {
	    printf("a[%d] = %ld. Son adresse : %p\n", i, a->content, a);
		a = a->next;
		i++;
	}
	printf("a[%d] = %ld. Son adresse : %p\n", i, a->content, a);
	printf("-------PREV----------\n");
	while (a != NULL)
    {
	    printf("a[%d] = %ld. Son adresse : %p\n", i, a->content, a);
		a = a->prev;
		i--;
	}
	printf("-----------------\n");
}
void ft_view_b(t_list *b)
{
	int	i;
	
	i = 1;
	while (b->next != NULL)
	{
		printf("b[%d] = %ld. Son adresse : %p\n", i, b->content, b);
		b = b->next;
		i++;
	}
	printf("b[%d] = %ld. Son adresse : %p\n", i, b->content, b);
	printf("-------PREV----------\n");
	while (b != NULL)
    {
	    printf("b[%d] = %ld. Son adresse : %p\n", i, b->content, b);
		b = b->prev;
		i--;
	}
	printf("-----------------\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = 0;
	b = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
			ft_make_a_split(&a, argv);
		if (argc > 2)
			ft_make_a_av(&a, argv);
		if (a == NULL)
			return (0);
		if (ft_doublon(a) == 0)
		{
			free_lst(a);
			return (0);
		}
		ft_pars(&a, &b);
		// ft_view_a(a);
		// ft_view_b(b);
		free_lst(a);
		free_lst(b);
	}
	return (0);
}
