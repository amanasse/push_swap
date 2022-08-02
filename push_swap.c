/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:06:56 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/02 14:52:38 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		free_lst(a);
		free_lst(b);
	}
	return (0);
}
