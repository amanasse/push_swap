/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:20:33 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/03 15:12:27 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_contword(char *str)
{
	int	i;
	int	word;
	int	indic;

	i = 0;
	indic = 1;
	word = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			indic = 1;
		if (str[i] != ' ' && indic == 1)
		{
			word++;
			indic = 0;
		}
		i++;
	}
	return (word);
}

static char	*my_new_word(char *str, int i, int w)
{
	char	*tmp;
	int		j;
	int		size;

	size = i - w;
	j = 0;
	tmp = malloc(sizeof(char) * (w + 1));
	if (tmp == NULL)
		return (NULL);
	while (j < w)
	{
		tmp[j] = str[size];
		size++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static char	**my_make_tab(char *str, char **tab, int m)
{
	int	i;
	int	j;
	int	w;
	int	indic;

	indic = 0;
	w = 0;
	i = -1;
	j = -1;
	while (++i < m)
	{
		while (str[i] && str[i] != ' ' && ++w)
		{
			indic = 1;
			i++;
		}
		if (indic == 1)
		{
			tab[++j] = my_new_word(str, i, w);
			indic = 0;
			w = 0;
		}
	}
	tab[++j] = NULL;
	return (tab);
}

static void	free_tab(char **tab, int count_words)
{
	int	i;

	i = 0;
	while (i < count_words)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

char	**ft_split(char const *s)
{
	char	**tab;
	int		i;
	int		count_words;

	i = 0;
	count_words = my_contword((char *)s);
	while (s[i] != '\0')
		i++;
	tab = malloc(sizeof(char *) * (count_words + 1));
	if (tab == NULL)
		return (NULL);
	tab = my_make_tab((char *)s, tab, i);
	i = 0;
	while (tab[i])
		i++;
	if (i != count_words)
	{
		free_tab(tab, count_words);
		return (NULL);
	}
	return (tab);
}
