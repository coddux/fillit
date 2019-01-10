/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_uinit_tpos.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 10:43:41 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		tpos_size(t_pos *alist)
{
	int		i;
	t_pos	*scanlist;

	i = 0;
	if (alist != NULL)
	{
		i = 1;
		scanlist = alist;
		while (scanlist != NULL)
		{
			scanlist = scanlist->next;
			i = i + 1;
		}
	}
	return (i);
}

int		tpos_level_init(t_pos **t_solpos, t_alg *algos)
{
	int	lvl;

	if (tpos_size(*t_solpos) == 0)
		lvl = algos->tmax - tpos_size(*t_solpos);
	else
		lvl = algos->tmax - tpos_size(*t_solpos) + 1;
	return (lvl);
}

t_pos	*tpos_new(void)
{
	int		i;
	t_pos	*t_new;

	i = 0;
	if (!(t_new = (t_pos*)malloc(sizeof(t_pos))))
		return (NULL);
	t_new->letter = ' ';
	while (i < 4)
	{
		t_new->pos[i][0] = 0;
		t_new->pos[i][1] = 0;
		i = i + 1;
	}
	t_new->next = NULL;
	return (t_new);
}

void	tpos_add(t_pos **alst, t_pos *blst)
{
	if ((!alst) || (!blst))
		return ;
	else
	{
		blst->next = *alst;
		*alst = blst;
		return ;
	}
}

t_pos	*tpos_add_node(t_pos **t_solpos)
{
	t_pos	*tmp_sol;

	tmp_sol = tpos_new();
	tpos_add(t_solpos, tmp_sol);
	return (tmp_sol);
}
