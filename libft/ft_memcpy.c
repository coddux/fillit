/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 19:19:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:48:17 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*src_uc;
	unsigned char	*dst_uc;

	count = 0;
	src_uc = (unsigned char *)src;
	dst_uc = (unsigned char *)dst;
	while (count < n)
	{
		dst_uc[count] = src_uc[count];
		count++;
	}
	return (dst);
}
