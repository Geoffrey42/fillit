/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:40:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/03/28 19:27:55 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist	*add_tetri1(char *file, t_tlist *list2, char letter)
{
	char	*new_buf;
	char	*schema;
	int		*tab;

	new_buf = fill_str(file);
	schema = malloc(sizeof(char) * 20 + 1);
	if (schema == NULL)
		return (NULL);
	tab = add_tetri2(list2, schema, new_buf, letter);
	free_var_tetri(tab, schema, new_buf);
	return (list2);
}

int		*add_tetri2(t_tlist *list2, char *schema, char *new_buf, char letter)
{
	int		i;
	int		j;
	int		*tab;

	i = 0;
	j = 0;
	while (new_buf[j])
	{
		if (i != 20)
			schema[i] = new_buf[j];
		if (i == 19)
		{
			schema[i + 1] = '\0';
			tab = add_tetri3(schema, tab);
			list2 = append_tetri(list2, tab, letter++);
			i = -1;
			if (new_buf[j + 1])
				j++;
		}
		i++;
		j++;
	}
	return (tab);
}

void	free_var_tetri(int *tab, char *schema, char *new_buf)
{
	free(tab);
	free(schema);
	free(new_buf);
}

int		*add_tetri3(char *schema, int *tab)
{
	int		k;
	int		l;
	int		i;
	int		s;

	k = -1;
	l = 0;
	s = 0;
	i = 0;
	tab = malloc(sizeof(int) * 3);
	while (k != 3)
	{
		if (schema[i] == '#')
		{
			if (s == 1)
				tab = second_if(tab, k, &l);
			++l;
			s = 1;
			k++;
		}
		if (schema[i] != '#' && s == 1)
			l++;
		i++;
	}
	return (tab);
}

int		*second_if(int *tab, int k, int *l)
{
	tab[k] = *l;
	*l = 0;
	return (tab);
}
