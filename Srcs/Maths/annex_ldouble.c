/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_ldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/24 05:41:24 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**If float == 0
*/

char		*ft_float_zero(int prec, unsigned int is_ten)
{
	char *ret;

	ret = ft_strdup("0.0000000");
	if (is_ten && prec > 0)
		ret = ft_floatexp(ret, prec);
	if (prec == -2)
		return (ret);
	if (prec > 0)
		ret = ft_rounding(ret, prec + 2);
	if (prec == 0)
		ret[2] = 0;
	return (ret);
}

/*
**Conditions according to the sign of exposant
*/

t_double	ft_doublesign(t_double dble)
{
	dble.temp = ft_pow2str(dble.b + dble.ex);
	if (dble.b + dble.ex >= 0)
	{
		ft_adjustpospo(&dble.temp, &dble.ent);
		dble.tempent = ft_addstrings(dble.temp, dble.ent);
		free(dble.ent);
		dble.ent = dble.tempent;
	}
	else if (dble.b + dble.ex < 0)
	{
		ft_adjustnegpo(&dble.temp, &dble.dec);
		dble.tempdec = ft_addstrings(dble.temp, dble.dec);
		free(dble.dec);
		dble.dec = dble.tempdec;
	}
	free(dble.temp);
	return (dble);
}

/*
**Main function to calculate and transform mant&exp to str long double
*/

void		ft_init_double(t_double *dble, long double a)
{
	dble->b = -1;
	dble->ex = ft_expldouble(a);
	dble->dec = (dble->ex < 0) ? ft_pow2str(0 + dble->ex) : ft_strdup("0");
	dble->ent = (dble->ex >= 0) ? ft_pow2str(0 + dble->ex) : ft_strdup("0");
	dble->m = ft_mantissaldouble(a);
}

char		*ft_ldouble(long double a, int prec, unsigned int is_ten)
{
	t_double	dble;
	int			i;

	i = 0;
	if (a == 0)
		return (ft_float_zero(prec, is_ten));
	ft_init_double(&dble, a);
	while (dble.m[i])
	{
		if (dble.m[i++] == '1')
			dble = ft_doublesign(dble);
		dble.b--;
	}
	dble.ent = ((a < 0) ? ft_joinfree(ft_strdup("-"), dble.ent) : dble.ent);
	if (!is_ten)
		dble.dec = ft_rounding(dble.dec, (prec > 0) ? prec : 6);
	dble.ent = ft_joinfree(dble.ent, ft_strdup("."));
	dble.ent = ft_joinfree(dble.ent, dble.dec);
	free(dble.m);
	if (is_ten)
		dble.ent = ft_floatexp(dble.ent, (prec > 0) ? prec : 6);
	return (dble.ent);
}
