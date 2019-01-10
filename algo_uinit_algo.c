/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_uinit_algo.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:47:21 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_alg	*algo_v_init(int tmax_v, int cmax_v, int lmax_v)
{
	t_alg	*algos;

	if (!(algos = (t_alg*)malloc(sizeof(t_alg))))
		return (NULL);
	algos->tmax = tmax_v;
	algos->cmax = cmax_v;
	algos->lmax = lmax_v;
	algos->c_ref = tmax_v;
	algos->c_ref_o = 0;
	algos->c_pos = tmax_v;
	algos->l_ref = 0;
	algos->l_ref_o = 0;
	algos->l_one = -1;
	algos->l_one_nb = 0;
	algos->solved = 0;
	return (algos);
}

t_alg	*algo_cpy(t_alg *alg_src)
{
	t_alg	*alg_dst;

	if (!(alg_dst = (t_alg*)malloc(sizeof(t_alg))))
		return (NULL);
	alg_dst->tmax = alg_src->tmax;
	alg_dst->cmax = alg_src->cmax;
	alg_dst->lmax = alg_src->lmax;
	alg_dst->c_ref = alg_src->c_ref;
	alg_dst->c_ref_o = alg_src->c_ref_o;
	alg_dst->c_pos = alg_src->c_pos;
	alg_dst->l_ref = alg_src->l_ref;
	alg_dst->l_ref_o = alg_src->l_ref_o;
	alg_dst->l_one = alg_src->l_one;
	alg_dst->l_one_nb = alg_src->l_one_nb;
	alg_dst->solved = alg_src->solved;
	return (alg_dst);
}

void	time_wait(unsigned long int time_delay)
{
	unsigned long int	itime;
	unsigned long int	time_max;

	itime = 0;
	time_max = time_delay * 100000;
	while (itime <= time_max)
		itime = itime + 1;
}
