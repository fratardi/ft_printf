/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_ldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/11 04:07:59 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**If float == 0
*/

char		*ft_float_zero(int prec, unsigned int is_ten, long double a)
{
	char *ret;
	int temp;
	int i;
	char *bin;

	temp = 0;
	bin = ft_binary(&a, 10);
	ret = ft_strdup((ft_strchr(bin, '1')) ? "-0.0000000" : "0.0000000");
	i = prec;
	// prec += (ft_strchr(bin, '1') ? 1 : 0);
	free(bin);
	if (is_ten && prec > 0)
		ret = ft_floatexp(ret, prec);
	if (prec == -2)
		return (ret);
	if (prec > 0)
		ret = ft_round_dec(ret, prec, &temp);
	printf("i = %d\n", i);
	if (i == 0)
		ret[(ret[0] == '-') ? 2 : 1] = 0;
	return (ret);
}

/*
**Conditions according to the sign of exposant
*/

t_double	ft_doublesign(t_double dble, char end)
{
	dble.temp = ft_pow2str(dble.b + dble.ex, end);
	if (dble.b + dble.ex >= 0)
	{
		ft_adjustpospo(&dble.temp, &dble.ent);
		dble.tempent = ft_addstrings(dble.temp, dble.ent);
		free(dble.ent);
		dble.ent = dble.tempent;
	}
	else if (dble.b + dble.ex < 0)
	{
		ft_adjustnegpo(&dble.dec, &dble.temp);
		ft_addstrings_stack(dble.dec, dble.temp, ft_strlen(dble.dec),
			ft_strlen(dble.temp));
	}
	free(dble.temp);
	return (dble);
}

/*
**Function to initialize values
*/

void		init_dble(t_double *dble, long double a)
{
	dble->b = -1;
	dble->ex = ft_expldouble(a);
	dble->dec = (dble->ex < 0) ? ft_pow2str(0 + dble->ex, 0) : ft_strdup("0");
	dble->ent = (dble->ex >= 0) ? ft_pow2str(0 + dble->ex, 0) : ft_strdup("0");
	dble->m = ft_mantissaldouble(a);
}

/*
**Main function to calculate and transform mant&exp to str long double
*/

char		*ft_ldouble(long double a, int prec, unsigned int is_ten)
{
	t_double	dble;
	int			i;

	i = 0;
	if (a == 0)
		return (ft_float_zero(prec, is_ten, a));
	init_dble(&dble, a);
	while (dble.m[i])
	{
		if (dble.m[i++] == '1')
			dble = ft_doublesign(dble, 0);
		if (!dble.m[i])
			free(ft_pow2str(-1, 1));
		dble.b--;
	}
	if (!is_ten)
		dble = ft_rounding_float(dble, prec);
	dble.ent = ((a < 0.0) ? ft_joinfree(ft_strdup("-"), dble.ent) : dble.ent);
	(prec != 0) ? dble.ent = ft_joinfree(dble.ent, ft_strdup(".")) : 0;
	dble.ent = ft_joinfree(dble.ent, dble.dec);
	free(dble.m);
	if (is_ten)
		dble.ent = ft_floatexp(dble.ent, (prec > 0) ? prec : 6);
	return (dble.ent);
}
