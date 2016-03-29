/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 16:01:40 by ggane             #+#    #+#             */
/*   Updated: 2016/03/27 12:10:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*check_cardinaux(char *str, int i, int **l, int *tab)
{
	if (str[i - 1] == '#' && i - 1 >= 0 && check_tab(tab, i - 1))
	{
		**l = **l + 1;
		tab[**l] = i - 1;
	}
	if (str[i + 1] == '#' && str[i + 1] != '\0' && check_tab(tab, i + 1))
	{
		**l = **l + 1;
		tab[**l] = i + 1;
	}
	if (str[i - 5] == '#' && i - 5 >= 0 && check_tab(tab, i - 5))
	{
		**l = **l + 1;
		tab[**l] = i - 5;
	}
	if (str[i + 5] == '#' && str[i + 5] != '\0' && check_tab(tab, i + 5))
	{
		**l = **l + 1;
		tab[**l] = i + 5;
		if (str[i + 4] == '#' && str[i + 4] != '\0' && check_tab(tab, i - 4))
			tab = cas_special(&l, i, tab);
	}
	return (tab);
}

int		check_tab(int *tab, int i)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (tab[j] == i)
			return (0);
		j++;
	}
	return (1);
}

void	rempli_tab(int **tab)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		(*tab)[i] = -1;
		i++;
	}
}

int		tetri(char *schema)
{
	int	i;
	int	l;
	int	diese;
	int *tab;

	i = 0;
	diese = 0;
	l = 0;
	tab = malloc(sizeof(int) * 4);
	rempli_tab(&tab);
	while (schema[i])
	{
		if (schema[i] == '#')
		{
			diese++;
			if (diese == 1)
				tab = diese_one(schema, tab, &l, i);
			if (diese > 1)
				if (diese_plus(schema, &tab, &l, i))
					return (1);
		}
		i++;
	}
	return (0);
}

int		*diese_one(char *schema, int *tab, int *l, int i)
{
	tab[*l] = i;
	tab = check_cardinaux(schema, i, &l, tab);
	return (tab);
}
