/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_memory.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 18:05:58 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:29:38 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	algo_free(t_alg *algo, int **i_solve, int lmax)
{
	free(algo);
	ft_memdelitab(i_solve, lmax);
}

void	ft_freepos(t_pos *lst)
{
	if (lst != NULL)
	{
		ft_freepos(lst->next);
		free(lst);
	}
}

void	ft_freemap(t_map *lst)
{
	if (lst != NULL)
	{
		ft_freemap(lst->next);
		free(lst);
	}
}

void	ft_free_algoman(t_pos *ref, t_pos *pos, t_alg *algos, int **i_solv)
{
	ft_memdelitab(i_solv, algos->lmax);
	free(algos);
	ft_freepos(ref);
	ft_freepos(pos);
}
