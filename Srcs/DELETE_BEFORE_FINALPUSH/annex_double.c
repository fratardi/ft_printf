/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:40:27 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/27 13:44:16 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char *ft_mantissadouble(double d)
{
	unsigned long long int *temp;
	char *f;
	unsigned long long int i;
	unsigned long long int pos;
	unsigned long long int mask;

	i = -1;
	f = (char *)ft_memalloc(sizeof(char) * 65);
	mask = 0x8000000000000000;
	temp = (unsigned long long int *)&d;
	pos = 0;
	while (++i < 64)
	{
		if (i >= 12)
			f[pos++] = ((*temp / mask) ? '1' : '0');
		*temp = *temp % mask;
		mask = mask >> 1;
	}
	return (f);
}

int ft_expdouble(double a)
{
	unsigned long long int *b;
	b = (unsigned long long int *)&a;
	*b = (*b & 0x7ff0000000000000) >> 52;
	/* ft_printf("%x -- Exp\n", *b); */
	//ft_printf("%d -- Exp\n", (*b - 127));
	return ((long long int)(*b) - 1023);
}

/* unsigned int ft_get_sig_double(double d)
{
	return (d ? (((unsigned long long int)d & (0x1 << 52)) >> 52) : 0);
} */

char *ft_double(double a)
{
	char *m;
	int ex;
	char *ent;
	char *dec;
	char *temp;
	int b;

	m = ft_mantissadouble(a);
	ex = ft_expdouble(a);
	b = -1;
	dec = (ex < 0) ? ft_pow2str(0 + ex) : ft_strdup("0");
	ft_printf("ex = %d et mantissa = %s\n", ex, m);
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
				// printf("ent = %s\n", ent);
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
}