/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_find.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 15:51:44 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	find_cpos_lone(int **i_slv, t_alg *algos, int lvl)
{
	algos->c_pos = find_c_pos(i_slv, algos, lvl);
	algos->l_one = find_l_one(i_slv, algos);
	if (INFO_LEVEL == 3)
	{
		ft_putstr("level[");
		ft_putnbr(lvl);
		ft_putstr("] | c_ref[");
		ft_putnbr(algos->c_ref);
		ft_putstr("}->c_pos[");
		ft_putnbr(algos->c_pos);
		ft_putstr("] | l_one[");
		ft_putnbr(algos->l_one);
		ft_putstr("]->l_ref_o[");
		ft_putnbr(algos->l_ref_o);
		ft_putstr("]\n");
	}
}

int		find_c_pos(int **i_solve, t_alg *algos, int lvl)
{
	int		i_c;
	int		c_sum;
	int		c_sum_min;
	int		c_sum_max;

	if (algos->c_ref_o > 2)
		algos->c_pos = algos->c_pos + 1;
	i_c = algos->c_pos;
	c_sum_min = (algos->tmax < 10) ? 1 : 2;
	c_sum_max = (algos->tmax < 10) ? lvl + 1 : lvl + 4;
	while (i_c < algos->cmax)
	{
		c_sum = col_sum(i_solve, algos, i_c);
		if ((c_sum >= c_sum_min) && (c_sum <= c_sum_max))
		{
			algos->c_ref = i_c;
			return (i_c);
		}
		i_c = i_c + 1;
	}
	return (algos->cmax);
}

int		find_l_one(int **i_solve, t_alg *algos)
{
	int		i_l;

	if (algos->l_ref_o == 0)
		i_l = 0;
	else
	{
		if (algos->l_ref_o >= 2)
			algos->l_ref_o = lone_min_nb(i_solve, algos, algos->c_ref);
		i_l = algos->l_ref + 1;
	}
	if (algos->c_pos == algos->cmax)
		return (-1);
	while (i_l < algos->lmax)
	{
		if (i_solve[i_l][algos->c_pos] == 1)
		{
			algos->l_ref = i_l;
			return (i_l);
		}
		i_l = i_l + 1;
	}
	return (-1);
}

int		line_remind(int **i_solve, t_alg *algos)
{
	int		i_l;
	int		l_sum;
	int		l_opt;

	i_l = 0;
	l_opt = 0;
	l_sum = 0;
	while (i_l < algos->lmax)
	{
		l_sum = lin_sum(i_solve, algos, i_l);
		if (l_sum == 5)
			l_opt = l_opt + 1;
		i_l = i_l + 1;
	}
	return (l_opt);
}

void	ref_option(int **i_solve, t_alg *algos, int lvl)
{
	algos->l_one_nb = line_remind(i_solve, algos);
	if (algos->c_pos == algos->cmax)
		algos->c_pos = algos->cmax;
	else
	{
		if (((algos->l_ref_o < (lone_min_nb(i_solve, algos, algos->c_ref) - 1))
			|| ((algos->l_ref_o == -1) && (algos->l_one_nb - 1 <= 0)))
			&& ((algos->l_ref_o <= 1) && (lvl < 5)))
		{
			algos->c_pos = algos->c_ref;
			algos->c_ref_o = 0;
			algos->l_ref_o = algos->l_ref_o + 1;
		}
		else
		{
			algos->c_pos = algos->c_ref + 1;
			algos->c_ref_o = algos->c_ref_o + 1;
			algos->l_ref_o = 0;
		}
	}
}
