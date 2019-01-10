/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 18:15:22 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 12:14:13 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**add_possibility(t_map *lst_tmp, int **tab, int map, int i)
{
	int j;
	int a;
	int b;
	int tmpb;
	int ij;

	j = lst_tmp->nb_tet;
	a = square_tet(lst_tmp, 0, 0, 1);
	tmpb = square_tet(lst_tmp, a, 0, 0);
	while (j < ((map * map) + lst_tmp->nb_tet) && a < 4)
	{
		b = tmpb;
		ij = 0;
		while (b < 4)
			tab[i][j + ij++] = lst_tmp->map[a][b++];
		a = square_tet(lst_tmp, a + 1, 0, 1);
		j += map;
	}
	tab = copy_line(lst_tmp, tab, map, i);
	return (tab);
}

void	tab_init_tet(t_map **list_map, int **tab, int map)
{
	t_map	*lst_tmp;
	int		i;

	lst_tmp = *list_map;
	i = 0;
	while (lst_tmp != NULL)
	{
		tab[i][lst_tmp->letter - 'A'] = 1;
		tab = add_possibility(lst_tmp, tab, map, i);
		i += calcule_posibility_one(lst_tmp->type, map);
		lst_tmp = lst_tmp->next;
	}
}

int		**tab_init_manager(t_map **list_map, int map, int lmax)
{
	t_map	*lst_tmp;
	int		**tab;

	lst_tmp = *list_map;
	tab = ft_create_ntab2(lmax, (lst_tmp->nb_tet + (map * map)), 0);
	tab_init_tet(list_map, tab, map);
	return (tab);
}

void	display_tab_map_size(void)
{
	if (INFO_LEVEL == 2)
	{
		ft_putstr("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		ft_putstr("\n!! NO SOLUTION --> increase map size !!");
		ft_putstr("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
}

int		tab_manager(t_map **list_map)
{
	int		map;
	int		lmax;
	int		**tab;
	t_map	*l_tmp;
	int		algo_map;

	algo_map = 0;
	l_tmp = *list_map;
	map = tab_def_map(l_tmp);
	while (algo_map == 0)
	{
		lmax = calcule_posibility(list_map, map);
		tab = tab_init_manager(list_map, map, lmax);
		if (algo_manager(tab, l_tmp->nb_tet,
			(l_tmp->nb_tet + (map * map)), lmax) == -1)
		{
			display_tab_map_size();
			map = map + 1;
			algo_map = 0;
		}
		else
			algo_map = 1;
		ft_memdelitab(tab, lmax);
	}
	return (1);
}
