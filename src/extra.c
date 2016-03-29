/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:30:17 by ggane             #+#    #+#             */
/*   Updated: 2016/03/28 21:18:16 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node	*forme_prev(t_list *list, t_node *tmp, t_tetri *forme)
{
	while (forme->position != tmp->position && tmp->prev != list->head->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_list	*carre_sup(t_list *list, t_tlist *flist)
{
	int		cote;
	t_node	*tmp;

	tmp = list->head;
	cote = list->cote;
	square_list_delete(&list);
	list = create_square_list(cote + 1);
	list = dessine_carre(list, cote + 1);
	square_converter(flist, cote, cote + 1);
	return (list);
}

void	table_rase(t_list *list, t_tetri *patron)
{
	t_node	*tmp;
	t_tetri *forme;

	tmp = list->head;
	forme = patron;
	while (tmp)
	{
		while (forme)
		{
			if (tmp->data == forme->letter)
				tmp->data = '.';
			forme = forme->next;
		}
		forme = patron;
		tmp = tmp->next;
	}
}

char	*fill_str(char *file)
{
	int		fd;
	int		i;
	char	buf[BUF_SIZE];
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1))
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	str = malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	read(fd, str, i);
	close(fd);
	return (str);
}

int		caracteres(char *schema)
{
	int		i;

	i = 0;
	while (schema[i])
	{
		if (schema[i] != '.' && schema[i] != '\n' && schema[i] != '#')
			return (1);
		i++;
	}
	return (0);
}
