/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:36:25 by ggane             #+#    #+#             */
/*   Updated: 2016/03/28 21:20:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 1
# define SIZE 16
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct			s_node
{
	char				data;
	int					position;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef	struct			s_list
{
	int					cote;
	struct s_node		*head;
	struct s_node		*tail;
}						t_list;

typedef	struct			s_tlist
{
	struct s_tetri		*head;
	struct s_tetri		*tail;
}						t_tlist;

typedef struct			s_tetri
{
	int					coordonnees[3];
	int					position;
	char				letter;
	struct s_tetri		*next;
	struct s_tetri		*prev;
}						t_tetri;

int						taille_premier_carre(char *file);
void					fillit(char *file, int res);
t_list					*dessine_carre(t_list *list, int res);
int						ft_sqrt(int nb);

void					ft_putchar(char c);
void					display_square(t_list *list);
void					ft_putstr(char *str);

t_list					*create_square_list(int res);
t_tlist					*create_forme_list(void);
t_list					*append_node(t_list *list, int position, char data);
void					square_list_delete(t_list **list);
void					forme_list_delete(t_tlist **list);

t_tlist					*append_tetri(t_tlist *list, int *data, char letter);
t_tetri					*create_link(int *data);

t_tlist					*add_tetri1(char *file, t_tlist *list2, char letter);
int						*add_tetri2(t_tlist *list2, char *schema,
						char *new_buf, char letter);
void					free_var_tetri(int *tab, char *schema, char *new_buf);
int						*add_tetri3(char *schema, int *tab);
int						*second_if(int *tab, int k, int *l);

void					square_converter(t_tlist *list, int cote1, int cote2);
int						test(t_node *elem, t_tetri *forme, char c);
void					dessine_forme(t_node *tmp, t_tetri *forme, char letter);
int						backtracking(t_list *list, t_tlist *flist,
						t_node *tmp, t_tetri *forme);
void					display_and_delete(t_list **list);

int						check(char *file);
int						fichier_existant(char *file);
int						nb_tetri(char *file);
int						check_file(char *str, char *file);
int						while_checkfile(char *str, char *schema, int *send);

int						*check_cardinaux(char *str, int i,
						int **l, int *tab);
int						check_tab(int *tab, int i);
void					rempli_tab(int **tab);
int						tetri(char *schema);
int						*diese_one(char *schema, int *tab, int *l, int i);

int						check_forme(char *schema);
int						nb_diese(char *schema);
int						*cas_special(int ***l, int i, int *tab);
int						diese_plus(char *schema, int **tab, int *l, int i);

t_node					*forme_prev(t_list *list, t_node *tmp, t_tetri *forme);
t_list					*carre_sup(t_list *list, t_tlist *flist);
void					table_rase(t_list *list, t_tetri *patron);
char					*fill_str(char *file);
int						caracteres(char *schema);

#endif
