/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:50:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 11:06:12 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include "libft/libft.h"

/*
** display information detail level
** 0 = only final solution
** 1 = all solution(s)
** 2 = debug information
** 3 = debug detailled
*/
# define INFO_LEVEL 0
# define TIME_DELAY 350

/*
** structure definition
*/
typedef struct s_pos	t_pos;

struct	s_pos
{
	int				pos[4][2];
	char			letter;
	struct s_pos	*next;
};

typedef struct s_map	t_map;

struct	s_map
{
	int				map[4][4];
	char			letter;
	int				type;
	int				nb_tet;
	struct s_map	*next;
};

typedef struct s_alg	t_alg;

struct	s_alg
{
	int				tmax;
	int				cmax;
	int				lmax;
	int				c_ref;
	int				c_ref_o;
	int				c_pos;
	int				l_ref;
	int				l_ref_o;
	int				l_one;
	int				l_one_nb;
	int				solved;
};

/*
** main fonctions
*/
int		main_manager(char *files);
char	*read_files(int fd, char *str);

/*
** tetris map check_files
*/
int		checkfiles(char *str, int a, int b, int c);
int		check_allbloc(char *str);
int		check_bloc(char **tab, int i_c, int i_l);
int		check_tetri(char **tab, int i_c, int i_l);

/*
** tetris map list : init && create
*/
int		lst_create(t_map **list_map, char *str_map);
int		lst_populate(t_map **list_map, char *str_map, int i_c, int i_l);
int		add_digit(char c);

/*
** tetris tab option : init && add posibility
*/
int		tab_manager(t_map **list_map);
int		**tab_init_manager(t_map **list_map, int map, int lmax);
void	tab_init_tet(t_map **list_map, int **tab, int map);
int		**add_posibility(t_map *lst_tmp, int **tab, int map, int i);

/*
** tab option utils
*/
int		**copy_line(t_map *lst_tmp, int **tab, int map, int i);
int		square_tet(t_map *lst_tmp, int a, int b, int index);
int		tab_def_map(t_map *lst_tmp);

/*
** tetris calcul_type
*/
int		calcule_posibility(t_map **list_map, int map);
int		calcule_posibility_one(int type, int map);
int		index_base(int *tab, int map, int nb_tet, int base);

/*
** tetris check_type
*/
int		check_type_line(int map[4][4], int i, int j, int count2);
int		check_type_col(int map[4][4], int i, int j, int count2);
int		check_type(int map[4][4], int i, int j);

/*
** algorithme manager (algo_manager.c)
*/
int		algo_manager(int **i_option, int tmax, int cmax, int lmax);
void	algo_solv(t_pos **t_solpos, int **i_slv, t_alg *alg, t_pos **t_rf);
void	algo_solution(t_pos **t_solpos, t_alg *alg, t_pos **t_sref);
void	algo_solution_node(t_pos **t_solpos, int **i_slv, t_alg *alg);
void	algo_manager_info(t_alg *algos);

/*
** algorithme information display (algo_u_display.c)
*/
void	display_str_square(char **s_solv, int map);
int		display_solution(t_pos *t_solv, int map);
void	display_map_info(int cmax, int tmax);
void	display_title_info(char *stitle);
void	algo_solution_info(t_pos *t_solution, t_alg *alg, int step, int place);

/*
** algorithme init value structure  (algo_uinit_algo.c)
*/
t_alg	*algo_v_init(int tmax_v, int cmax_v, int lmax_v);
t_alg	*algo_cpy(t_alg *alg_src);
void	time_wait(unsigned long int time_delay);

/*
** algorithme initialize tab solve   (algo_uinit_isolve.c)
*/
int		**islv_init(int **i_option, int cmax, int lmax);
int		**islv_cpy(int **i_solv, int cmax, int lmax);
void	display_screen_init(int tmax, int cmax, int step);

/*
** algorithme initialize liste position  (algo_uinit_tpos.c)
*/
int		tpos_size(t_pos *alist);
int		tpos_level_init(t_pos **t_solpos, t_alg *alg);
t_pos	*tpos_new(void);
void	tpos_add(t_pos **alst, t_pos *blst);
t_pos	*tpos_add_node(t_pos **t_solpos);

/*
** algorithme find solution                (algo_u_find.c)
*/
void	find_cpos_lone(int **i_slv, t_alg *alg, int lvl);
int		find_c_pos(int **i_solve, t_alg *algos, int lv);
int		find_l_one(int **i_solve, t_alg *algos);
int		line_remind(int **i_solve, t_alg *algos);
void	ref_option(int **i_solve, t_alg *algos, int lvl);

/*
** algorithme reduce map, rm line && column (algo_u_remove.c)
*/
int		**remove_col(int **i_solve, t_alg *algos, int c_one);
int		**remove_line(int **i_solve, t_alg *algos, int i_l);
int		**remove_cl(int **i_solve, t_alg *algos);
int		**algo_rmap(int **i_solve, t_alg *algos);

/*
** algorithme util populate liste position  (algo_u_tpos.c)
*/
void	tpos_del_first(t_pos **alst);
char	tpos_letter(char alpha, int **i_solve, t_alg *algos);
t_pos	*tpos_value(t_pos *t_solpos, int **i_solve, t_alg *algos);
int		tpos_sol(t_pos **t_solpos, int **i_solve, t_alg *algos);

/*
** algorithme utils                        (algo_utils.c)
*/
int		col_min_nb(int **i_option, t_alg *algos);
int		lone_min_nb(int **i_solve, t_alg *algos, int c_one);
int		col_sum(int **i_solve, t_alg *algos, int i_c);
int		lin_sum(int **i_solve, t_alg *algos, int i_l);

/*
** solution lst_compare
*/
void	lst_compare(t_pos **t_sref, t_pos *t_solp, t_alg *alg);

/*
** utils memory management
*/
void	algo_free(t_alg *algo, int **i_solve, int lmax);
void	ft_freemap(t_map *lst);
void	ft_freepos(t_pos *lst);
void	ft_free_algoman(t_pos *ref, t_pos *pos, t_alg *alg, int **i_solv);

/*
** utils
*/
int		**ft_create_ntab2(int lin, int col, int nb);
int		printlst_final(t_pos *lst, int map);
void	ft_memfree(t_pos *t_solpos, t_pos *t_solref, t_alg *algos);
t_pos	*tpos_cmpnew(t_pos **t_sref, t_pos *t_solp, int tmax);
void	*tpos_cmpcpy(t_pos **t_sref, t_pos *t_solp, int tmax);

#endif
