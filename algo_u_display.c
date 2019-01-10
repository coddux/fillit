/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_display.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 11:16:25 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 08:31:22 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	display_str_square(char **s_solv, int map)
{
	int		i;
	int		space_nb;
	char	*space_str;

	i = 0;
	space_nb = (36 - map) / 2;
	space_str = "";
	while (i < space_nb)
	{
		space_str = ft_strjoin(space_str, " ");
		i = i + 1;
	}
	i = 0;
	while (s_solv[i] != NULL)
	{
		ft_putstr(space_str);
		ft_putstr(s_solv[i]);
		if (s_solv[i][ft_strlen(s_solv[i]) - 1] != '\n')
			ft_putchar('\n');
		i = i + 1;
	}
}

int		display_solution(t_pos *t_solv, int map)
{
	int		ip;
	char	**s_solv;

	if (!(s_solv = ft_createtab(map, '.')))
		return (-1);
	while (t_solv != NULL)
	{
		ip = 0;
		while (ip < 4)
		{
			s_solv[t_solv->pos[ip][0]][t_solv->pos[ip][1]] = t_solv->letter;
			ip = ip + 1;
		}
		t_solv = t_solv->next;
	}
	if (INFO_LEVEL == 1)
		display_str_square(s_solv, map);
	if ((INFO_LEVEL == 0) || (INFO_LEVEL == 2) || (INFO_LEVEL == 3))
		ft_printtab(s_solv);
	ft_memdeltab(s_solv);
	return (1);
}

void	display_map_info(int cmax, int tmax)
{
	if (tmax < 10)
		ft_putstr("|     0");
	else
		ft_putstr("|     ");
	ft_putnbr(tmax);
	if (ft_sqrt(cmax - tmax) < 10)
		ft_putstr(" tetris --> map[0");
	else
		ft_putstr(" tetris --> map[");
	ft_putnbr(ft_sqrt(cmax - tmax));
	if (ft_sqrt(cmax - tmax) < 10)
		ft_putstr("x0");
	else
		ft_putstr("x");
	ft_putnbr(ft_sqrt(cmax - tmax));
	ft_putstr("]     |\n");
	ft_putstr("+----------------------------------+\n");
}

void	display_title_info(char *stitle)
{
	if (ft_strcmp(stitle, "initial") == 0)
	{
		ft_putstr("+----------------------------------+\n");
		ft_putstr("|          I N I T I A L           |\n");
		ft_putstr("|----------------------------------|\n");
	}
	if (ft_strcmp(stitle, "solution") == 0)
	{
		ft_putstr("\n+----------------------------------+");
		ft_putstr("\n|         S O L U T I O N          |");
		ft_putstr("\n|----------------------------------|\n");
	}
	else if (ft_strcmp(stitle, "reference") == 0)
	{
		ft_putstr("+----------------------------------+\n");
		ft_putstr("|        R E F E R E N C E         |\n");
		ft_putstr("+----------------------------------+\n");
	}
	else
	{
		ft_putstr("\n+----------------------------------+");
		ft_putstr("\n|   S O L U T I O N  F I N A L E   |");
		ft_putstr("\n|----------------------------------|\n");
	}
}

void	algo_solution_info(t_pos *t_solution, t_alg *alg, int step, int place)
{
	if (place == 0)
	{
		if (INFO_LEVEL == 1)
			display_screen_init(alg->tmax, alg->cmax, step);
		if ((INFO_LEVEL == 1) || (INFO_LEVEL == 2) || (INFO_LEVEL == 3))
		{
			display_title_info("solution");
			display_map_info(alg->cmax, alg->tmax);
			display_solution(t_solution, ft_sqrt(alg->cmax - alg->tmax));
		}
		if (INFO_LEVEL == 1)
			time_wait(TIME_DELAY);
	}
	if (place == 2)
	{
		if (INFO_LEVEL != 0)
		{
			display_title_info("solution finale");
			display_map_info(alg->cmax, alg->tmax);
		}
		display_solution(t_solution, ft_sqrt(alg->cmax - alg->tmax));
	}
}
