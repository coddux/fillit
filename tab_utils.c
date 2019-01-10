/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 12:23:41 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 12:22:32 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**copy_line(t_map *lst_tmp, int **tab, int map, int i)
{
	int		j;
	int		tmpi;
	int		base;
	int		pos_max;

	pos_max = (calcule_posibility_one(lst_tmp->type, map) - 1);
	base = 0;
	tmpi = i;
	while (pos_max--)
	{
		base = index_base(tab[i], map, lst_tmp->nb_tet, base);
		j = (lst_tmp->nb_tet);
		tab[i + 1][lst_tmp->letter - 'A'] = 1;
		while ((j + base) < ((map * map) + lst_tmp->nb_tet))
		{
			tab[i + 1][j + base] = tab[tmpi][j];
			j++;
		}
		i++;
	}
	return (tab);
}

int		square_tet(t_map *lst_tmp, int a, int b, int index)
{
	if (index == 1)
	{
		while (lst_tmp->map[a][b] != 1 && a < 4)
		{
			while (lst_tmp->map[a][b] != 1 && b < 4)
				b++;
			if (b != 4)
				return (a);
			a++;
			b = 0;
		}
		return (a);
	}
	while (lst_tmp->map[a][b] != 1 && b < 4)
	{
		while (lst_tmp->map[a][b] != 1 && a < 4)
			a++;
		if (a != 4)
			return (b);
		b++;
		a = 0;
	}
	return (b);
}

int		tab_def_map(t_map *lst_t)
{
	int		map;
	int		tet_nb;
	int		tet_type;
	t_map	*lst_tmp;

	lst_tmp = lst_t;
	tet_type = 0;
	tet_nb = 0;
	while (lst_tmp != NULL)
	{
		if (lst_tmp->type == 3)
			tet_type = 1;
		lst_tmp = lst_tmp->next;
		tet_nb++;
	}
	map = 0;
	while ((map * map) < (tet_nb * 4))
		map++;
	if ((tet_type == 1) && (map < 4))
		map = 4;
	return (map);
}
