/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 16:00:06 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:02:31 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_create_ntab2(int lin, int col, int nb)
{
	int		i;
	int		j;
	int		**tab;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * lin)))
		return (NULL);
	while (i < lin)
	{
		j = 0;
		if (!(tab[i] = (int *)malloc(sizeof(int) * col)))
			return (NULL);
		while (j < col)
			tab[i][j++] = nb;
		i++;
	}
	return (tab);
}

int		printlst_final(t_pos *lst, int map)
{
	int		i;
	char	**tab;

	if (!(tab = ft_createtab(map, '.')))
		return (-1);
	while (lst != NULL)
	{
		i = 0;
		while (i < 4)
		{
			tab[lst->pos[i][0]][lst->pos[i][1]] = lst->letter;
			i++;
		}
		lst = lst->next;
	}
	ft_printtab(tab);
	ft_memdeltab(tab);
	return (1);
}

void	ft_memfree(t_pos *t_solpos, t_pos *t_solref, t_alg *algos)
{
	free(t_solref);
	free(algos);
	free(t_solpos);
}

t_pos	*tpos_cmpnew(t_pos **t_sref, t_pos *t_solp, int tmax)
{
	int		it;
	int		ip;
	t_pos	*tmp_ref;

	tmp_ref = *t_sref;
	it = 0;
	while ((it < tmax) && (t_solp != NULL))
	{
		tpos_add_node(&tmp_ref);
		tmp_ref->letter = t_solp->letter;
		ip = 0;
		while (ip < 4)
		{
			tmp_ref->pos[ip][0] = t_solp->pos[ip][0];
			tmp_ref->pos[ip][1] = t_solp->pos[ip][1];
			ip = ip + 1;
		}
		t_solp = t_solp->next;
		it = it + 1;
	}
	return (tmp_ref);
}

void	*tpos_cmpcpy(t_pos **t_sref, t_pos *t_solp, int tmax)
{
	int		it;
	int		ip;
	t_pos	*tmp_ref;

	tmp_ref = *t_sref;
	it = 0;
	while ((it <= tmax) && (t_solp != NULL))
	{
		tmp_ref->letter = t_solp->letter;
		ip = 0;
		while (ip < 4)
		{
			tmp_ref->pos[ip][0] = t_solp->pos[ip][0];
			tmp_ref->pos[ip][1] = t_solp->pos[ip][1];
			ip = ip + 1;
		}
		t_solp = t_solp->next;
		tmp_ref = tmp_ref->next;
		it = it + 1;
	}
	return (tmp_ref);
}
