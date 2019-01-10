/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkfiles.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 14:32:21 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 10:26:03 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetri(char **tab, int i_c, int i_l)
{
	int nb_tet;

	nb_tet = 0;
	if (i_l < 4 && tab[i_c][i_l + 1] == '#')
		nb_tet++;
	if (i_l > 0 && tab[i_c][i_l - 1] == '#')
		nb_tet++;
	if (i_c > 0 && tab[i_c - 1][i_l] == '#')
		nb_tet++;
	if (tab[i_c + 1] != NULL && tab[i_c + 1][i_l] == '#')
		nb_tet++;
	return (nb_tet);
}

int		check_bloc(char **str_tetri, int i_c, int i_l)
{
	int tmax;
	int	bloc_c;
	int	bloc_l;

	tmax = 0;
	bloc_c = 0;
	bloc_l = 0;
	while (bloc_c != 4)
	{
		if (str_tetri[i_c][i_l] == '#')
		{
			bloc_l++;
			tmax += check_tetri(str_tetri, i_c, i_l);
		}
		i_l++;
		if (i_l == 4)
		{
			bloc_c++;
			i_c++;
			i_l = 0;
		}
	}
	if (bloc_l != 4)
		tmax = -1;
	return (tmax);
}

int		check_allbloc(char *str_map)
{
	char	**str_tetri;
	int		i_c;
	int		i_l;

	i_c = 0;
	i_l = 0;
	str_tetri = ft_strsplit(str_map, '\n');
	while (str_tetri[i_c] != '\0')
	{
		if ((check_bloc(str_tetri, i_c, i_l)) < 6)
			return (-1);
		i_c += 4;
	}
	ft_memdeltab(str_tetri);
	if ((i_c / 4) > 26)
		return (-1);
	return (1);
}

int		checkfiles(char *str_map, int i, int i_c, int i_l)
{
	while (str_map[i] != '\0')
	{
		while (str_map[i] == '#' || str_map[i] == '.')
		{
			i++;
			i_c++;
		}
		if (str_map[i] == '\n' && str_map[i + 1] != '\n' && i_c == 4)
		{
			i_l++;
			i++;
		}
		else if (str_map[i] == '\n' && str_map[i + 1] == '\n'
				&& i_l == 3 && i_c == 4)
		{
			i += 2;
			i_l = 0;
		}
		else if ((i_l != 3 || i_c != 4) && str_map[i] != '\0')
			return (-1);
		i_c = 0;
	}
	if (i_l != 4 || i_c != 0)
		return (-1);
	return (check_allbloc(str_map));
}
