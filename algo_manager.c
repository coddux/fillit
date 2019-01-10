/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 11:16:25 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 11:05:51 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	algo_manager_info(t_alg *algos)
{
	if (INFO_LEVEL == 2)
	{
		display_title_info("initial");
		display_map_info(algos->cmax, algos->tmax);
	}
}

void	algo_solution_node(t_pos **t_solpos, int **i_slv, t_alg *alg)
{
	tpos_add_node(t_solpos);
	tpos_sol(t_solpos, i_slv, alg);
}

void	algo_solution(t_pos **t_solpos, t_alg *algos, t_pos **t_sref)
{
	int		map;
	int		step;

	step = (*t_sref == NULL) ? 0 : 1;
	map = ft_sqrt(algos->cmax - algos->tmax);
	algo_solution_info(*t_solpos, algos, step, 0);
	lst_compare(t_sref, *t_solpos, algos);
	if ((INFO_LEVEL == 1) || (INFO_LEVEL == 2) || (INFO_LEVEL == 3))
	{
		display_title_info("reference");
		display_solution(*t_sref, map);
	}
	tpos_del_first(t_solpos);
}

void	algo_solv(t_pos **t_solpos, int **i_slv, t_alg *ag, t_pos **t_sref)
{
	int		lvl;
	t_alg	*algo;
	int		**i_solve;

	lvl = tpos_level_init(t_solpos, ag);
	while (ag->c_pos < ag->cmax)
	{
		find_cpos_lone(i_slv, ag, lvl);
		if (ag->l_one != -1)
		{
			algo_solution_node(t_solpos, i_slv, ag);
			if (lvl == 1)
				algo_solution(t_solpos, ag, t_sref);
			else
			{
				algo = algo_cpy(ag);
				i_solve = algo_rmap(islv_cpy(i_slv, ag->cmax, ag->lmax), algo);
				algo_solv(t_solpos, i_solve, algo, t_sref);
				algo_free(algo, i_solve, ag->lmax);
			}
		}
		ref_option(i_slv, ag, lvl);
	}
	if (tpos_size(*t_solpos) > 1)
		tpos_del_first(t_solpos);
}

int		algo_manager(int **i_option, int tmax, int cmax, int lmax)
{
	t_alg	*algos;
	int		**i_solv;
	t_pos	*t_solpos;
	t_pos	*t_solref;

	t_solref = NULL;
	t_solpos = NULL;
	algos = algo_v_init(tmax, cmax, lmax);
	algo_manager_info(algos);
	i_solv = islv_init(i_option, cmax, lmax);
	algo_solv(&t_solpos, i_solv, algos, &t_solref);
	if (t_solref != NULL)
	{
		algo_solution_info(t_solref, algos, 0, 2);
		ft_free_algoman(t_solref, t_solpos, algos, i_solv);
		return (1);
	}
	else
	{
		ft_free_algoman(t_solref, t_solpos, algos, i_solv);
		return (-1);
	}
}
