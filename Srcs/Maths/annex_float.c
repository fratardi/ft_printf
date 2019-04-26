/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:06 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/26 19:17:36 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char *ft_mantissabin(float d)
{
	unsigned int *temp;
	char *f;
	unsigned int i;
	unsigned int pos;
	unsigned int mask;

	i = -1;
	f = (char *)malloc(sizeof(char) * 33);
	mask = 0x80000000;
	temp = (unsigned int *)&d;
	pos = 0;
	while (++i < 32)
	{
		if (i >= 9)
			f[pos++] = ((*temp / mask) ? '1' : '0');
		*temp = *temp % mask;
		mask = mask >> 1;
	}
	return (f);
}

int ft_expfloat(float a)
{
	unsigned int *b;
	b = (unsigned int *)&a;
	*b = (*b & 0x7f800000) >> 23;
	/* ft_printf("%x -- Exp\n", *b); */
	//ft_printf("%d -- Exp\n", (*b - 127));
	return ((int)(*b) - 127);
}

unsigned int ft_get_sig(float d)
{
	return (d ? (((unsigned int)d & (0x00000001 << 31)) >> 31) : 0);
}


char *ft_fillbig(char *s1, char *s2)
{
	while (ft_strlen(s1) < ft_strlen(s2))
		s1 = ft_strjoinfree(s1, ft_strdup("0"));
	return (s1);
}

void ft_hexfloat(void *content, size_t n)
{
	char tab[17] = "0123456789abcdef";
	char *str;

	str = (char *)content;
	ft_putstr("0x");
	while (0 < n--)
	{
		ft_putchar(tab[((unsigned char)str[n] / 16)]);
		ft_putchar(tab[((unsigned char)str[n] % 16)]);
	}
}

size_t digitlen(unsigned long long int i)
{
	size_t ret;
	
	ret = 0;
	while (i)
	{
		i = i/10;
		ret++;
	}
	return (ret);
}