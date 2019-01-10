/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bzero.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 17:38:17 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 19:16:32 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int					count;
	unsigned	char	*dest;

	count = 0;
	dest = s;
	while (n-- > 0)
		dest[count++] = 0;
}
