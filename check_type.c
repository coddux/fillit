/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_type.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 16:00:06 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 14:00:19 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		check_type_line(int map[4][4], int mi, int mj, int i_c)
{
	int		i;

	i = 0;
	while (mi != 4)
	{
		if (map[mi][mj] == 1)
			i++;
		mj++;
		if (mj == 4)
		{
			if (((i_c == 0 || ((i < i_c) && i != 0)) && i_c != 4) || i == 4)
				i_c = i;
			mi++;
			mj = 0;
			i = 0;
		}
	}
	return (i_c);
}

int		check_type_col(int map[4][4], int mi, int mj, int icl)
{
	int i;

	i = 0;
	while (mj != 4)
	{
		if (map[mi][mj] == 1)
			i++;
		mi++;
		if (mi == 4)
		{
			if (((icl == 0 || ((i < icl) && i != 0)) && icl != 4) || i == 4)
				icl = i;
			mj++;
			mi = 0;
			i = 0;
		}
	}
	return (icl);
}

int		check_type(int map[4][4], int mi, int mj)
{
	int t_type;

	t_type = check_type_col(map, mi, mj, 0);
	t_type = check_type_line(map, mi, mj, t_type);
	if ((t_type == 1) || (t_type == 2))
		return (t_type);
	else
		return (3);
}
