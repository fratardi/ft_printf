/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_ldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/18 03:07:39 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Get binary mantissa from long double
*/

char *ft_mantissaldouble(long double d)
{
	__uint128_t *temp;
	char *f;
	__uint128_t i;
	__uint128_t pos;
	__uint128_t mask;

	i = -1;
	f = (char *)ft_memalloc(sizeof(char) * 66);
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

/*
**Get exp from long double
*/

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

t_double	ft_doublesign(t_double dble)
{
	dble.temp = ft_pow2str(dble.b + dble.ex);
	if (dble.b + dble.ex >= 0)
	{
		ft_adjustpospo(&dble.temp, &dble.ent);
		dble.tempent = ft_addstrings(dble.temp, dble.ent);
		free(dble.ent);
		dble.ent = ft_strdup(dble.tempent);
		free(dble.tempent);
	}
	else if (dble.b + dble.ex < 0)
	{
		ft_adjustnegpo(&dble.temp, &dble.dec);
		dble.tempdec = ft_addstrings(dble.temp, dble.dec);
		free(dble.dec);
		dble.dec = ft_strdup(dble.tempdec);
		free(dble.tempdec);
	}
	free(dble.temp);
	return (dble);
}

/*
**Main function to calculate and transform mant&exp to str long double
*/

char *ft_ldouble(long double a, size_t prec)
{
	t_double dble;
	int i;

	i = 0;
	dble.b = -1;
	dble.ex = ft_expldouble(a);
	dble.dec = (dble.ex < 0) ? ft_pow2str(0 + dble.ex) : ft_strdup("0");
	dble.ent = (dble.ex >= 0) ? ft_pow2str(0 + dble.ex) : ft_strdup("0");
	dble.m = ft_mantissaldouble(a);
	while (dble.m[i])
	{
		if (dble.m[i] == '1')
			dble = ft_doublesign(dble);
		dble.b--;
		i++;
	}
	dble.ent = ((a < 0) ? ft_joinfree(ft_strdup("-"), dble.ent) : dble.ent);
	dble.dec = ft_rounding(dble.dec, (prec) ? prec : 6);
	//ft_printf("%s.%s", ent, dec);
	dble.ent = ft_joinfree(dble.ent, ft_strdup("."));
	dble.ent = ft_joinfree(dble.ent, dble.dec);
	free(dble.m);
	return (dble.ent);
}
