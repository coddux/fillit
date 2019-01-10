/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:29:48 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		col_sum(int **i_solve, t_alg *algos, int i_c)
{
	int		i_l;
	int		c_sum;

	i_l = 0;
	c_sum = 0;
	while (i_l < algos->lmax)
	{
		if (i_solve[i_l][i_c] != -1)
			c_sum = c_sum + i_solve[i_l][i_c];
		i_l = i_l + 1;
	}
	return (c_sum);
}

int		col_min_nb(int **i_option, t_alg *algos)
{
	int		i_c;
	int		c_sum;
	int		c_min_nb;

	c_min_nb = 0;
	i_c = algos->tmax;
	while (i_c < algos->cmax)
	{
		c_sum = col_sum(i_option, algos, i_c);
		if (c_sum != 0)
		{
			if (c_sum <= algos->tmax)
				c_min_nb = c_min_nb + 1;
		}
		i_c = i_c + 1;
	}
	return (c_min_nb);
}

int		lone_min_nb(int **i_solve, t_alg *algos, int c_one)
{
	int		i_l;
	int		l_min_nb;

	l_min_nb = 0;
	i_l = 0;
	while (i_l < algos->lmax)
	{
		if (i_solve[i_l][c_one] == 1)
			l_min_nb = l_min_nb + 1;
		i_l = i_l + 1;
	}
	return (l_min_nb);
}

int		lin_sum(int **i_solve, t_alg *algos, int i_l)
{
	int		i_c;
	int		l_sum;

	i_c = 0;
	l_sum = 0;
	while (i_c < algos->cmax)
	{
		if (i_solve[i_l][i_c] != -1)
			l_sum = l_sum + i_solve[i_l][i_c];
		i_c = i_c + 1;
	}
	return (l_sum);
}
