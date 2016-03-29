/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:58:29 by ggane             #+#    #+#             */
/*   Updated: 2016/03/28 20:51:14 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(char *file)
{
	int		fd;
	int		i;
	int		ret;
	char	buf[BUF_SIZE];
	char	*str;

	i = 0;
	if (fichier_existant(file))
		return (1);
	if ((fd = open(file, O_RDONLY)))
		while (read(fd, buf, BUF_SIZE))
			i++;
	close(fd);
	str = (char*)malloc(sizeof(char) * i + 1);
	if (!str)
		return (1);
	fd = open(file, O_RDONLY);
	if ((ret = read(fd, str, i)))
		str[ret] = '\0';
	close(fd);
	if (check_file(str, file))
		return (1);
	free(str);
	return (0);
}

int		fichier_existant(char *file)
{
	int		fd;
	char	buf[BUF_SIZE];

	fd = open(file, O_RDONLY);
	if (read(fd, buf, BUF_SIZE) == -1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int		nb_tetri(char *file)
{
	int		fd;
	int		nbt;
	int		index;
	char	buf[BUF_SIZE];

	index = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, BUF_SIZE))
		if (buf[0] == '\n')
			index++;
	close(fd);
	nbt = (index / 5) + 1;
	return (nbt);
}

int		check_file(char *str, char *file)
{
	int		nbt;
	int		send;
	char	*schema;

	send = 0;
	nbt = nb_tetri(file);
	schema = (char *)malloc(sizeof(char) * 20 + 1);
	if (schema == NULL)
		return (1);
	if (while_checkfile(str, schema, &send))
		return (1);
	if (send != nbt)
		return (1);
	free(schema);
	return (0);
}

int		while_checkfile(char *str, char *schema, int *send)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j <= 19)
			schema[j] = str[i];
		else if (j != 19 && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		if (j == 19 && schema[j] == '\n')
		{
			schema[j + 1] = '\0';
			if (check_forme(schema))
				return (1);
			j = -1;
			if (str[i + 1])
				i++;
			*send = *send + 1;
		}
		i++;
		j++;
	}
	return (0);
}
