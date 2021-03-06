/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:24:04 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:24:51 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static long	ft_len_nb(long n, int base)
{
	int count;

	count = 0;
	if (n == -2147483648 && base == 10)
		return (11);
	if (n < 0 && base == 10)
	{
		n = n * -1;
		count++;
	}
	while (n >= base)
	{
		count++;
		n = n / base;
	}
	return (count + 1);
}

static char	*ft_itoa_cal(char *str, long n, int len, int base)
{
	if ((n % base) < 10)
		str[len--] = (char)(n % base) + 48;
	else
		str[len--] = (char)(n % base) + 55;
	while (n >= base)
	{
		n = n / base;
		if ((n % base) < 10)
			str[len--] = (char)(n % base) + 48;
		else
			str[len--] = (char)(n % base) + 55;
	}
	return (str);
}

char		*ft_itoa_base(int nb, int base)
{
	int		len;
	char	*str;
	long	n;

	n = (long)nb;
	if (base < 2 || base > 16)
		return (NULL);
	if (n < 0 && base != 10)
		n = -n;
	len = ft_len_nb(n, base);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n < 0 && base == 10)
	{
		if (n == -2147483648)
		{
			str[1] = '2';
			n = -147483648;
		}
		str[0] = '-';
		n = n * -1;
	}
	len--;
	return (ft_itoa_cal(str, n, len, base));
}
