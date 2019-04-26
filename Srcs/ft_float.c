/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:03:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/26 18:46:16 by tpacaud          ###   ########.fr       */
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
	ret = (y == 0 && diff) ? ft_strjoinfree(ft_strdup("1"), ret) : ret;
	if (y == 0)
		return (ret);
	s2p--;
	y -= (s2p) ? 1 : 0;
	while (s1p >= 0 || s2p >= 0)
		diff = ft_addchar("0", (s1p >= 0) ? &s1[s1p--] : &s2[s2p--],
						  &ret[y--], diff);
	ret = (diff) ? ft_strjoinfree(ft_strdup("1"), ret) : ret;
	return (ret);
}

void ft_adjustnegpo(char **s1, char **s2)
{
	size_t i1;
	size_t i2;
	char *tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_strjoinfree(*s1, tojoin);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_strjoinfree(*s2, tojoin);
	}
}

void ft_adjustpospo(char **s1, char **s2)
{
	size_t i1;
	size_t i2;
	char *tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_strjoinfree(tojoin, *s1);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_strjoinfree(tojoin, *s2);
	}
}

/* char *ft_floatt(float a)
{
	char *m;
	int ex;

	char *ent;
	char *dec;

	//char *base;
	char *temp;

	int b;

	m = ft_mantissabin(a);
	ex = ft_expfloat(a);
	b = -1;
	dec = (ex < 0) ? ft_pow2str(0 + ex) : ft_strdup("0");
	// ft_printf("ex = %d et mantissa = %s\n", ex, m);
	ent = (ex >= 0) ? ft_pow2str(0 + ex) : ft_strdup("0");
	// printf("__%s.%s\n", ent, dec);
	while (*m)
	{
		if (*m == '1')
		{
			if (b + ex >= 0)
			{
				temp = ft_pow2str(b + ex);
				ft_adjustpospo(&temp, &ent);
				ent = ft_addstrings(temp, ent);
				printf("ent = %s\n", ent);
			}
			else if (b + ex < 0)
			{
				temp = ft_pow2str(b + ex);
				ft_adjustnegpo(&temp, &dec);
				dec = ft_addstrings(temp, dec);
			}
		}
		b--;
		m++;
	}
	printf("Nous__%s.%s\n", ent, dec);
	ent = ft_strjoinfree(ent, ft_strdup("."));
	ent = ft_strjoinfree(ent, dec);
	return (ent);
} */

void ft_floatEdispneg(char *str, int prec)
{
	int i;
	int y;
	int puiss;

	i = 2;
	y = 0;
	puiss = 0;
	if (str[0] != '0')
		return;
	while (str[i] && str[i] == '0')
		i++;
	puiss = i - 1;
	ft_printf("Nous__%c.", str[i]);
	while (y++ < prec)
		ft_putchar(str[i++]);
	ft_printf("E-%d\n", puiss);
}

char *ft_rounding(char *str, size_t prec)
{
	int i;

	i = 0;
/* 	while (str[i] && str[i] != '.')
		i++; */
	if (prec > ft_strlen(str))
	{
		while(prec > ft_strlen(str))
			str = ft_strjoinfree(str, ft_strdup("0"));
		return(str);
	}
	i += prec - 1;
	if (str[i] == '5')
		while (str[i] && str[i] == '5')
			i++;
	if (str[i] == 0 || str[i] > '5')
	{
		str[prec] = 0;
		str = ft_addstrings(str, ft_strdup("1"));
		//str[prec - 1] += 1;
	}
	str[prec] = 0;
	return (str);
}