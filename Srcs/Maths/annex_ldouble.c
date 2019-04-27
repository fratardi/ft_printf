/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_ldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/27 14:29:30 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char *ft_mantissaldouble(long double d)
{
	__uint128_t *temp;
	char *f;
	__uint128_t i;
	__uint128_t pos;
	__uint128_t mask;

	i = -1;
	f = (char *)ft_memalloc(sizeof(char) * 65);
	mask = 0x8000000000000000;
	temp = (__uint128_t *)&d;
	pos = 0;
	while (++i < 64)
	{
		if (i >= 1)
			f[pos++] = ((*temp / mask) ? '1' : '0');
		*temp = *temp % mask;
		mask = mask >> 1;
	}
	//printf("ldouble = %s\n", f);
	return (f);
}

int ft_expldouble(long double a)
{
	__uint128_t *b;
	b = (__uint128_t *)&a;
	*b = *b >> 64;
	*b = (*b & 0x7fff);
	/* ft_printf("%x -- Exp\n", *b); */
	//ft_printf("%d -- Exp\n", (*b - 127));
	return ((long long int)(*b) - 16383);
}

size_t	ft_ldouble(long double a, size_t prec)
{
	char *m;
	int ex;
	char *ent;
	char *dec;
	char *temp;
	size_t ret;
	int b;

	m = ft_mantissaldouble(a);
	ex = ft_expldouble(a);
	b = -1;
	dec = (ex < 0) ? ft_pow2str(0 + ex) : ft_strdup("0");
	ent = (ex >= 0) ? ft_pow2str(0 + ex) : ft_strdup("0");
	while (*m)
	{
		if (*m == '1')
		{
			temp = ft_pow2str(b + ex);
			if (b + ex >= 0)
			{
				ft_adjustpospo(&temp, &ent);
				ent = ft_addstrings(temp, ent);
			}
			else if (b + ex < 0)
			{
				ft_adjustnegpo(&temp, &dec);
				dec = ft_addstrings(temp, dec);
			}
		}
		b--;
		m++;
	}
	ent = ((a < 0) ? ft_strjoinfree(ft_strdup("-"), ent) : ent);
	dec = ft_rounding(dec, (prec) ? prec : 6);
	ft_printf("%s.%s", ent, dec);
	ret = 1 + ft_strlen(ent) + ft_strlen(dec);
	free(ent);
	free(dec);
	return (ret);
}