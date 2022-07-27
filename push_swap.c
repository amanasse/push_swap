/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:56 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/27 12:06:14 by amanasse         ###   ########.fr       */
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
	// printf("a %p\n", a);
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
	    // printf("a = %ld. Son adresse : %p\n", a->content, a);
	    // printf("a->next = %ld. Son adresse : %p\n", a->next->content, a->next);
	    // printf("a->prev. Son adresse : %p\n", a->prev);
		// ft_view_a(a);
		// ft_rra(&a);
		ft_pb(&a, &b);
		ft_pb(&a, &b);
		ft_pb(&a, &b);
		// printf("a = %ld. Son adresse : %p\n", a->content, a);
	    // printf("a->next = %ld. Son adresse : %p\n", a->next->content, a->next);
	    // printf("a->prev. Son adresse : %p\n", a->prev);
		// a = a->next;
		// ft_view_a(a);
		// printf("b = %ld. Son adresse : %p\n", b->content, b);
		// b = b->prev;
		// printf("b = %ld. Son adresse : %p\n", b->content, b);

	    // printf("a->next = %ld. Son adresse : %p\n", a->next->content, a->next);
	    // printf("a->prev = %ld. Son adresse : %p\n", a->prev->content, a->prev);

		ft_view_a(a);

		ft_view_b(b);

		// ft_pars(&a, &b);
		// printf("FINAL\n");
		// ft_view_a(a);
		// ft_view_b(b);
		free_lst(a);
		free_lst(b);
	}
	return (0);
}
