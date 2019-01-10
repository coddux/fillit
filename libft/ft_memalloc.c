/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:30:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:46:44 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_new;

	if (size > 2147483647)
		return (NULL);
	if (!(mem_new = (void*)malloc(sizeof(void) * size + 1)))
		return (NULL);
	ft_memset(mem_new, 0, size);
	return (mem_new);
}
