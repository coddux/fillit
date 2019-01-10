/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_uinit_isolve.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 16:24:24 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**islv_init(int **i_option, int cmax, int lmax)
{
	int		i;
	int		j;
	int		**i_init;

	if (!(i_init = (int**)malloc(sizeof(int*) * lmax)))
		return (NULL);
	i = 0;
	while (i < lmax)
	{
		if (!(i_init[i] = (int*)malloc(sizeof(int) * cmax)))
			return (NULL);
		j = 0;
		while (j < cmax)
		{
			i_init[i][j] = i_option[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
	return (i_init);
}

int		**islv_cpy(int **i_solv, int cmax, int lmax)
{
	int		i;
	int		j;
	int		**i_solved;

	if (!(i_solved = (int**)malloc(sizeof(int*) * lmax)))
		return (NULL);
	i = 0;
	while (i < lmax)
	{
		if (!(i_solved[i] = (int*)malloc(sizeof(int) * cmax)))
			return (NULL);
		j = 0;
		while (j < cmax)
		{
			i_solved[i][j] = i_solv[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
	return (i_solved);
}

void	display_screen_init(int tmax, int cmax, int step)
{
	char	*screen_clear;
	char	*line_up;

	if (step == 0)
	{
		screen_clear = "\33[2J\33[H";
		ft_putstr(screen_clear);
	}
	if (step == 1)
	{
		line_up = ft_itoa((2 * ft_sqrt(cmax - tmax)) + 10);
		ft_putstr(ft_strjoin(ft_strjoin("\33[", line_up), "A"));
	}
}
