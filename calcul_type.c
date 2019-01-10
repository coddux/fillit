/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calcul_type.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 16:00:06 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 21:17:42 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		calcule_posibility(t_map **list_map, int map)
{
	t_map			*lst_temp;
	unsigned int	count;

	lst_temp = *list_map;
	count = 0;
	while (lst_temp != NULL)
	{
		if (lst_temp->type == 1)
			count += ((map - 1) * (map - 2));
		else if (lst_temp->type == 2)
			count += ((map - 1) * (map - 1));
		else if (lst_temp->type == 3)
			count += (map * (map - 3));
		lst_temp = lst_temp->next;
	}
	return (count);
}

int		calcule_posibility_one(int type, int map)
{
	int	iposible;

	iposible = 0;
	if (type == 1)
		iposible += ((map - 1) * (map - 2));
	else if (type == 2)
		iposible += ((map - 1) * (map - 1));
	else if (type == 3)
		iposible += (map * (map - 3));
	return (iposible);
}

int		index_base(int *tab, int map, int nb_tet, int base)
{
	int j;

	j = 0;
	j = (nb_tet);
	j += (map - 1);
	while (tab[j] == 0 && j < ((map * map) + nb_tet))
		j += map;
	if (tab[j] == 1)
	{
		j = (nb_tet + (map - 1));
		while ((j - nb_tet + 1) <= base)
			j += map;
		return (j - nb_tet + 1);
	}
	else
		base++;
	return (base);
}
