/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_ldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/27 06:23:09 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**If float == 0
*/

char		*ft_float_zero(int prec, unsigned int is_ten, long double a)
{
	char *ret;
	char *bin;

	bin = ft_binary(&a, sizeof(long double));
	ret = ft_strdup((ft_strchr(bin, '1')) ? "-0.0000000" : "0.0000000");
	prec += (ft_strchr(bin, '1') ? 1 : 0);
	free(bin);
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
		///
		///
		///
		/*
		ft_adjustnegpo(&dble.temp, &dble.dec);
		dble.tempdec = ft_addstrings(dble.temp, dble.dec);
		free(dble.dec);
		dble.dec = dble.tempdec;
	
		*/

		ft_pow2str_stack((size_t)(dble.ex) , &dble.basenegpo);
		//ft_putendl(dble.basenegpo.content);

		//
	
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
//attention ici a voir
	dble->basenegpo.content = ft_strdup("\0");
	dble->basenegpo.content_size = 1;
// fin attention    
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
			free(ft_pow5(1, 1));
		dble.b--;
	}
	dble.ent = ((a < 0.0) ? ft_joinfree(ft_strdup("-"), dble.ent) : dble.ent);
	if (!is_ten)
		dble.dec = ft_rounding(dble.dec, (prec > 0) ? prec : 6);
	(prec == 0) ? 0 : (dble.ent = ft_joinfree(dble.ent, ft_strdup(".")));
	(prec == 0) ? free(dble.dec) : (dble.ent = ft_joinfree(dble.ent, dble.dec));
	free(dble.m);
	if (is_ten)
		dble.ent = ft_floatexp(dble.ent, (prec > 0) ? prec : 6);
	return (dble.ent);
}
