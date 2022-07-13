/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:56 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/13 12:09:55 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list *tmp;
	// t_list	*b;
	a = 0;
	if (argc >= 2)
	{
		if (argc == 2)
			ft_make_a_split(&a, argv);
		if (argc > 2)
		{
			printf("DEBUG\n");
			ft_make_a_av(&a, argv);
		}
		if (a == NULL)
			return (0);
	}

	ft_pars(&a);
	tmp = a;
	while (tmp != NULL)
	{
		printf("tmp %d = %p\n", tmp->content, tmp);
		tmp = tmp->next;
	}



		printf("tmp %p\n", tmp);
		printf("-----------------\n");

	return (0);
}
