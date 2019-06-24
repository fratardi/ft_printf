/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:06 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/20 18:17:38 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

char	*ft_fillbig(char *s1, char *s2)
{
	while (ft_strlen(s1) < ft_strlen(s2))
		s1 = ft_joinfree(s1, ft_strdup("0"));
	return (s1);
}

void	ft_hexfloat(void *content, size_t n)
{
	static char tab[16] = "0123456789abcdef";
	char		*str;

	str = (char *)content;
	ft_putstr("0x");
	while (0 < n--)
	{
		ft_putchar(tab[((unsigned char)str[n] / 16)]);
		ft_putchar(tab[((unsigned char)str[n] % 16)]);
	}
}

size_t	digitlen(unsigned long long int i)
{
	size_t ret;

	ret = 0;
	while (i)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

/*
**Get binary mantissa from long double
*/

char	*ft_mantissaldouble(long double d)
{
	__int128_t	*temp;
	char		*f;
	__int128_t	i;
	__int128_t	pos;
	__int128_t	mask;

	i = -1;
	if (!(f = (char *)ft_memalloc(sizeof(char) * 66)))
		return (NULL);
	mask = 0x8000000000000000;
	temp = (__int128_t *)&d;
	pos = 0;
	while (++i < 64)
	{
		if (i >= 1)
			f[pos++] = ((*temp / mask) ? '1' : '0');
		*temp = *temp % mask;
		mask = mask >> 1;
	}
	return (f);
}

/*
**Get exp from long double
*/

int		ft_expldouble(long double a)
{
	__int128_t *b;

	b = (__int128_t *)&a;
	*b = *b >> 64;
	*b = (*b & 0x7fff);
	return ((int)(*b) - 16383);
}
