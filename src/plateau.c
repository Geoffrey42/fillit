/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:53:06 by ggane             #+#    #+#             */
/*   Updated: 2016/03/28 21:20:30 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		taille_premier_carre(char *file)
{
	int		nbt;
	int		res;

	nbt = nb_tetri(file);
	res = ft_sqrt(nbt * 4);
	fillit(file, res);
	return (0);
}

void	fillit(char *file, int res)
{
	t_list	*list1;
	t_tlist	*list2;
	t_node	*tmp;
	t_tetri *forme;
	char	letter;

	letter = 'A';
	list1 = create_square_list(res);
	list2 = create_forme_list();
	list1 = dessine_carre(list1, res);
	list2 = add_tetri1(file, list2, letter);
	square_converter(list2, 4, res);
	tmp = list1->head;
	forme = list2->head;
	backtracking(list1, list2, tmp, forme);
	forme_list_delete(&list2);
}

t_list	*dessine_carre(t_list *list, int res)
{
	int		i;
	int		l;

	i = 0;
	l = 1;
	while (i < (res * res))
	{
		list = append_node(list, i, '.');
		if (l == res)
		{
			list = append_node(list, i, '\n');
			l = 0;
		}
		l++;
		i++;
	}
	return (list);
}

int		ft_sqrt(int nb)
{
	int		count;

	count = 0;
	while (count * count < nb)
		count++;
	if (count * count == nb)
		return (count);
	else
		return (ft_sqrt(nb + 1));
	return (0);
}
