/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 16:06:55 by ggane             #+#    #+#             */
/*   Updated: 2016/03/26 19:40:42 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_forme(char *schema)
{
	int		i;

	i = 0;
	if (nb_diese(schema))
		return (1);
	if (caracteres(schema))
		return (1);
	if (tetri(schema))
		return (1);
	return (0);
}

int		nb_diese(char *schema)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (schema[i])
	{
		if (schema[i] == '#')
			d++;
		i++;
	}
	if (d != 4)
		return (1);
	return (0);
}

int		*cas_special(int ***l, int i, int *tab)
{
	***l = ***l + 1;
	tab[***l] = i + 4;
	return (tab);
}

int		diese_plus(char *schema, int **tab, int *l, int i)
{
	if (check_tab(*tab, i))
		return (1);
	else
		*tab = check_cardinaux(schema, i, &l, *tab);
	return (0);
}
