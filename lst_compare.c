/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_compare.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 14:37:03 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:05:22 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		lst_compare_pos(t_pos *lst_ref, t_pos *lst_pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (lst_ref->pos[i][0] < lst_pos->pos[i][0])
			return (-1);
		else if (lst_ref->pos[i][0] > lst_pos->pos[i][0])
			return (1);
		if (lst_ref->pos[i][1] < lst_pos->pos[i][1])
			return (-1);
		else if (lst_ref->pos[i][1] > lst_pos->pos[i][1])
			return (1);
		i++;
	}
	return (0);
}

static void		lst_compare_init(t_pos **t_sref, t_pos **lst_ref, int i_c)
{
	t_pos	*lst_tmp;

	lst_tmp = *t_sref;
	while ((lst_tmp != NULL) && (lst_tmp->letter != 'A' + i_c))
		lst_tmp = lst_tmp->next;
	*lst_ref = lst_tmp;
}

static	int		lst_position(t_pos **t_sref, t_pos *t_solp, int i_c)
{
	int		position;
	t_pos	*lst_ref;
	t_pos	*lst_pos;

	lst_compare_init(t_sref, &lst_ref, i_c);
	lst_compare_init(&t_solp, &lst_pos, i_c);
	position = lst_compare_pos(lst_ref, lst_pos);
	return (position);
}

void			lst_compare(t_pos **t_sref, t_pos *t_solp, t_alg *alg)
{
	int		i_c;
	int		position;

	i_c = 0;
	if (t_solp == NULL)
		return ;
	if (*t_sref == NULL)
	{
		*t_sref = tpos_cmpnew(t_sref, t_solp, alg->tmax);
		return ;
	}
	while (i_c < alg->tmax)
	{
		position = lst_position(t_sref, t_solp, i_c);
		if (position == -1)
			return ;
		else if (position == 1)
		{
			tpos_cmpcpy(t_sref, t_solp, alg->tmax);
			return ;
		}
		else
			i_c++;
	}
}
