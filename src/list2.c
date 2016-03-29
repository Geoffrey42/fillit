/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:22:06 by ggane             #+#    #+#             */
/*   Updated: 2016/03/24 11:07:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*create_link(int *data)
{
	t_tetri	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->coordonnees[0] = data[0];
		new->coordonnees[1] = data[1];
		new->coordonnees[2] = data[2];
		new->position = 0;
		new->letter = 'A';
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

t_tlist		*append_tetri(t_tlist *list, int *data, char letter)
{
	t_tetri		*new;

	new = create_link(data);
	new->next = NULL;
	if (list->tail == NULL)
	{
		new->prev = NULL;
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	if (list->head == NULL)
		list->head = new;
	new->letter = letter;
	return (list);
}
