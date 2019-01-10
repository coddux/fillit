/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_remove.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 10:28:19 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**remove_col(int **i_solve, t_alg *algos, int c_one)
{
	int		i_l;

	i_l = 0;
	while (i_l < algos->lmax)
	{
		i_solve[i_l][c_one] = -1;
		i_l = i_l + 1;
	}
	return (i_solve);
}

int		**remove_line(int **i_solve, t_alg *algos, int i_l)
{
	int		i_c;

	i_c = 0;
	while (i_c < algos->cmax)
	{
		i_solve[i_l][i_c] = -1;
		i_c = i_c + 1;
	}
	return (i_solve);
}

int		**remove_cl(int **i_solve, t_alg *algos)
{
	int		i_c;
	int		i_l;

	i_c = 0;
	while (i_c < algos->cmax)
	{
		if (i_solve[algos->l_one][i_c] == 1)
		{
			i_l = 0;
			while (i_l < algos->lmax)
			{
				if ((i_solve[i_l][i_c] == 1) && (i_l != algos->l_one))
					i_solve = remove_line(i_solve, algos, i_l);
				i_l = i_l + 1;
			}
			if (i_c != algos->c_pos)
				i_solve = remove_col(i_solve, algos, i_c);
		}
		i_c = i_c + 1;
	}
	return (i_solve);
}

int		**algo_rmap(int **i_solve, t_alg *algos)
{
	i_solve = remove_cl(i_solve, algos);
	i_solve = remove_line(i_solve, algos, algos->l_one);
	i_solve = remove_col(i_solve, algos, algos->c_pos);
	return (i_solve);
}
