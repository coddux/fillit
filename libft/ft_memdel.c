/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:34:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 10:42:48 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}

void	ft_memdeltab(char **ap)
{
	int count;

	count = 0;
	while (ap[count] != NULL)
	{
		free(ap[count]);
		ap[count] = NULL;
		count++;
	}
	free(ap);
	ap = NULL;
}

void	ft_memdelitab(int **ap, int lmax)
{
	int count;

	count = 0;
	while (count < lmax)
	{
		free(ap[count]);
		ap[count] = NULL;
		count++;
	}
	free(ap);
	ap = NULL;
}
