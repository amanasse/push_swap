/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:56 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/15 13:56:47 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void free_lst(t_list *a)
{
	t_list	*tmp;

    while (a != NULL)
    {
		tmp = a;
		a = a->next;
	    free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = 0;
	b = 0;
	if (argc >= 2)
	{
		if (argc == 2)
			ft_make_a_split(&a, argv);
		if (argc > 2)
			ft_make_a_av(&a, argv);
		if (a == NULL)
			return (0);
		ft_pars(&a, &b);
		
		printf("FINAL\n");
		ft_view_a(a);
		ft_view_b(b);
		free_lst(a);
		free_lst(b);

		// free(b);
	}
	return (0);
}
