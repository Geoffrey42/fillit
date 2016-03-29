/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:33:31 by ggane             #+#    #+#             */
/*   Updated: 2016/03/28 20:37:29 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test(t_node *tmp, t_tetri *forme, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (tmp->data != c && tmp->data != '.')
		return (0);
	while (tmp)
	{
		if (forme->coordonnees[j] == i)
		{
			if ((tmp->data != c && tmp->data != '.') || tmp == NULL)
				return (0);
			i = 0;
			j++;
		}
		if (j == 3)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL && j < 3)
		return (0);
	return (1);
}

void	square_converter(t_tlist *list, int cote1, int cote2)
{
	t_tetri		*tmp;
	int			i;

	tmp = list->head;
	i = 0;
	while (tmp)
	{
		while (i < 3)
		{
			if (tmp->coordonnees[i] > 1 && cote2 != cote1)
				tmp->coordonnees[i] = tmp->coordonnees[i] + (cote2 - cote1);
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

void	dessine_forme(t_node *tmp, t_tetri *forme, char letter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp->data = letter;
	forme->position = tmp->position;
	while (tmp)
	{
		if (forme->coordonnees[j] == i)
		{
			tmp->data = letter;
			i = 0;
			j++;
		}
		if (j == 3)
			break ;
		tmp = tmp->next;
		i++;
	}
}

int		backtracking(t_list *list, t_tlist *flist, t_node *tmp, t_tetri *forme)
{
	if (forme == NULL)
	{
		display_and_delete(&list);
		return (0);
	}
	while (test(tmp, forme, '.'))
	{
		dessine_forme(tmp, forme, forme->letter);
		return (backtracking(list, flist, list->head, forme->next));
	}
	if (test(tmp, forme, '.') == 0 && tmp->next != NULL)
		return (backtracking(list, flist, tmp->next, forme));
	if (test(tmp, forme, '.') == 0 && tmp->next == NULL && forme->letter == 'A')
	{
		list = carre_sup(list, flist);
		return (backtracking(list, flist, list->head, forme));
	}
	if (test(tmp, forme, '.') == 0 && tmp->next == NULL)
	{
		table_rase(list, forme->prev);
		tmp = forme_prev(list, tmp, forme->prev);
		if (tmp->next != NULL && forme->prev != flist->head->prev)
			return (backtracking(list, flist, tmp->next, forme->prev));
	}
	return (1);
}

void	display_and_delete(t_list **list)
{
	display_square(*list);
	square_list_delete(list);
}
