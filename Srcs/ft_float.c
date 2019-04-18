/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:03:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/18 18:55:22 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char ft_addchar(char *s1, char *s2, char *ret, char carry)
{
	if (*s1 + *s2 + carry - (2 * '0') <= 9)
	{
		*ret = *s1 + *s2 + carry - '0';
		return (0);
	}
	*ret = (*s1 + *s2) + carry - 10 - '0';
	return (1);
}

char *ft_addstrings(char *s1, char *s2)
{
	int s1p;
	int s2p;
	int y;
	char diff;
	char *ret;

	s1p = ft_strlen(s1);
	s2p = ft_strlen(s2);
	if (!(ret = (char *)ft_memalloc((s1p >= s2p) ? s1p + 1 : s2p + 1)))
		return (NULL);
	ft_memset(ret, '0', (s1p >= s2p) ? s1p - 1 : s2p - 1);
	diff = 0;
	y = (s1p >= s2p) ? s1p : s2p;
	while (s1p-- && s2p-- && y--)
		diff = ft_addchar(&s1[s1p], &s2[s2p], &ret[y], diff);
	ret = (y== 0 && diff) ? ft_strjoinfree(ft_strdup("1"), ret) : ret;
	if (y == 0)
		return(ret);
	s2p--;
	y -= (s2p) ? 1 : 0;
	while(s1p >= 0 || s2p >= 0)
		diff = ft_addchar("0", (s1p >= 0) ? &s1[s1p--] : &s2[s2p--],
		 &ret[y--], diff);
	ret = (diff) ? ft_strjoinfree(ft_strdup("1"), ret) : ret;
	return (ret);
}

char *ft_pow5(int po)
{
	char *base;
	char *ret;
	size_t p;
	int i;

	p = (size_t)po;
	if (po == 0)
		return (ft_strdup("1"));
	if (po < 0)
		po = -po;
	ret = ft_strdup("5");
	while (po > 1)
	{
		i = 4;
		base = ft_strdup(ret);
		while (i--)
			ret = ft_addstrings(ret, base);
		free(base);
		po--;
	}
	return (ret);
}


char 	*ft_pow2neg(int n)
{
	char *ret;
	char *fill;
	size_t i;
	
	ret = ft_pow5(n);
	i = n - ft_strlen(ret);
	if(!(fill = (char *)ft_memalloc((sizeof(char)) * (i + 1))))
		return(NULL);
	ft_memset(fill , '0', i);
	return(ft_strjoinfree(fill, ret));
}


void	ft_adjustnegpo(char **s1, char **s2)
{
	size_t i1;
	size_t i2;
	char *tojoin;
	
	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if(i1 == i2)
		return ;
	if(i1 < i2)
	{	
		if(!(tojoin = (char *)ft_memalloc(sizeof(char ) * (i2 - i1 + 1))))
			return;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_strjoinfree(*s1, tojoin);
	}
	if(i1 > i2)
	{
		if(!(tojoin = (char *)ft_memalloc(sizeof(char ) * (i1 - i2 + 1))))
				return;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_strjoinfree(*s2, tojoin);
	}
}






/* char *ft_floatt(float a)
{
	char *m;
	char *temp;
	char *ret;
	char *base;
	//int i;
	int ex;
	unsigned long long int positiv;
	size_t b;

	m = ft_mantissabin(a);
	ex = ft_expfloat(a);
	printf("ex = %d et mantissa = %s\n", ex, m);
	positiv = (ex > 0) ? ft_pow2(ex) : 0;
	if (ex < 0)
		positiv = (unsigned long long int)ft_pow(5, -ex);
	b = (ex > 0) ? digitlen(positiv) : 0;
	ex = 1;
	temp = ft_memalloc(2048);
	ft_bzero(temp, 2048);
	temp[0] = 48;
	while(*m)
	{
		if (*m == '1')
		{
			temp = ft_fillbig(temp, ft_pow2neg(ex));
			temp = ft_addstrings(ft_pow2neg(ex), temp);
		}
		m++;
		ex++;
	}
	temp = ft_strjoinfree(ft_strdup("1"), temp);
	//printf("neg = %s\n", temp);
	ret = ft_memalloc(2048);
	ft_bzero(ret, 2048);
	ret[0] = 48;
	while(positiv--)
	{
		base = ft_strdup(temp);
		//printf("{%s + %s}\n", ret, base);
		ret = ft_addstrings(ret, base);
		//printf("{%s} -- {%s}\n", ret, base);
	}
	while(b > 0)
	{
		printf("%c", *ret);
		ret++;
		b--;
	}
	return(ret);
} */
