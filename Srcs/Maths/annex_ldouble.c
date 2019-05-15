/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_ldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/15 19:35:42 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Get binary mantissa from long double
*/

char	*ft_mantissaldouble(long double d)
{
	__uint128_t		*temp;
	char			*f;
	__uint128_t		i;
	__uint128_t		pos;
	__uint128_t		mask;

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

int		ft_expldouble(long double a)
{
	__uint128_t		*b;

	b = (__uint128_t *)&a;
	*b = *b >> 64;
	*b = (*b & 0x7fff);
	/* ft_printf("%x -- Exp\n", *b); */
	//ft_printf("%d -- Exp\n", (*b - 127));
	return ((long long int)(*b) - 16383);
}

/*
**Main function to calculate and transform mant&exp to str long double
*/

char	*ft_ldouble(long double a, size_t prec)
{
	char	*m;
	int		ex;
	char	*ent;
	char	*dec;
	char	*temp;
	char	*tempent;
	char	*tempdec;
	size_t	i;
	int		b;

	i = 0;
	b = -1;
	ex = ft_expldouble(a);
	dec = (ex < 0) ? ft_pow2str(0 + ex) : ft_strdup("0");
	ent = (ex >= 0) ? ft_pow2str(0 + ex) : ft_strdup("0");
	m = ft_mantissaldouble(a);
	while (m[i])
	{
		if (m[i] == '1')
		{
			temp = ft_pow2str(b + ex);
			if (b + ex >= 0)
			{
				ft_adjustpospo(&temp, &ent);
				tempent = ft_addstrings(temp, ent);
				free(ent);
				ent = ft_strdup(tempent);
				free(tempent);
			}
			else if (b + ex < 0)
			{
				// ft_adjustnegpo(&temp, &dec);
				tempdec = ft_addstrings(temp, dec);
				free(dec);
				dec = ft_strdup(tempdec);
				free(tempdec);
			}
			free(temp);
		}
		b--;
		i++;
	}
	ent = ((a < 0) ? ft_joinfree(ft_strdup("-"), ent) : ent);
	dec = ft_rounding(dec, (prec) ? prec : 6);
	//ft_printf("%s.%s", ent, dec);
	ent = ft_joinfree(ent, ft_strdup("."));
	ent = ft_joinfree(ent, dec);
	// free(dec);
	// free(temp);
	free(m);
	// free(ent);
	return (ent);
}
