/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:20:23 by ggane             #+#    #+#             */
/*   Updated: 2016/03/28 21:20:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*create_square_list(int res)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list)
	{
		list->cote = res;
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}

t_tlist		*create_forme_list(void)
{
	t_tlist	*list;

	list = malloc(sizeof(*list));
	if (list)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}

t_list		*append_node(t_list *list, int position, char data)
{
	t_node	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->data = data;
		new->position = position;
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
	}
	return (list);
}

void		square_list_delete(t_list **list)
{
	t_node	*tmp;
	t_node	*del;

	tmp = (*list)->head;
	while (tmp)
	{
		del = tmp;
		free(del);
		tmp = tmp->next;
	}
	free(*list);
	*list = NULL;
}

void		forme_list_delete(t_tlist **list)
{
	t_tetri	*tmp;
	t_tetri	*del;

	tmp = (*list)->head;
	while (tmp)
	{
		del = tmp;
		free(del);
		tmp = tmp->next;
	}
	free(*list);
	*list = NULL;
}
