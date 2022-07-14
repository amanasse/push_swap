/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:06:24 by amanasse          #+#    #+#             */
/*   Updated: 2022/07/14 15:49:16 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <unistd.h>

// typedef struct s_ope 
// {
//   	int	count;
// } 					t_ope;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				size;
}					t_list;

void	ft_bzero(void *s, int n);
char	**ft_split(char const *s);
int		ft_count_words(char *str);
int		ft_atoi(char *nptr);

void	ft_make_a_split(t_list **a, char **argv);
void	ft_make_a_av(t_list **a, char **argv);
int		check_tab(char *str);
void	ft_doublon(t_list *a);
void	free_split(char **tab, int count);

//listes chainees :

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		tri_a_faire(t_list *a);

//tri de 2 a 5 :

void	ft_pars(t_list **a, t_list **b);
void	push_swap_2(t_list *a);
void	push_swap_3(t_list **a);
void	push_swap_4(t_list **a, t_list **b);
void	push_swap_5(t_list **a, t_list **b);

//calculs :

void	ft_sa(t_list *a);
void	ft_sb(t_list *b);
void	ft_ss(t_list *a, t_list *b);

void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);

void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);

void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	push(t_list **pile, int content);
int		pop(t_list **pile);

//algo :

void	ft_view_a(t_list *a);
void	ft_view_b(t_list *b);
int		find_min(t_list *a);
void	opti_division(t_list **a, int size, int count_min);

#endif
