/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_tpos.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 16:30:07 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	tpos_del_first(t_pos **alst)
{
	t_pos	*tpos_tmp;
	t_pos	*tpos_l;

	if (!alst)
		return ;
	else
	{
		tpos_l = (*alst)->next;
		tpos_tmp = tpos_l;
		free(*alst);
		*alst = tpos_tmp;
		return ;
	}
}

char	tpos_letter(char alpha, int **i_solve, t_alg *algos)
{
	int		i_c;

	i_c = 0;
	while (i_c < algos->tmax)
	{
		if (i_solve[algos->l_one][i_c] == 1)
			alpha = 'A' + i_c;
		i_c = i_c + 1;
	}
	return (alpha);
}

t_pos	*tpos_value(t_pos *t_solpos, int **i_solve, t_alg *algos)
{
	int		i;
	int		t;
	int		i_c;

	i = 0;
	i_c = algos->tmax;
	t = ft_sqrt(algos->cmax - algos->tmax);
	while (i_c < algos->cmax)
	{
		if (i_solve[algos->l_one][i_c] == 1)
		{
			t_solpos->pos[i][0] = (i_c - algos->tmax) / t;
			t_solpos->pos[i][1] = (i_c - algos->tmax) % t;
			i = i + 1;
		}
		i_c = i_c + 1;
	}
	return (t_solpos);
}

int		tpos_sol(t_pos **t_solpos, int **i_solve, t_alg *algos)
{
	t_pos	*tmp_sol;

	tmp_sol = *t_solpos;
	tmp_sol->letter = tpos_letter(' ', i_solve, algos);
	if ((tmp_sol->letter == ' ')
		|| (tmp_sol->letter < 'A') || (tmp_sol->letter > 'Z'))
	{
		algos->l_one = -1;
		return (-1);
	}
	tmp_sol = tpos_value(tmp_sol, i_solve, algos);
	return (1);
}
