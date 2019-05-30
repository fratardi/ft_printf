/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:38:54 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/30 03:38:19 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Functions Power 2 and 5 returning a char*
*/

char	*ft_pow_neg(int po, char end, t_last_pow *lcalc)
{
	static int	last = 0;
	int			p;
	t_power5	pow;

	if (end == 1)
	{
		free(lcalc->last);
		return(ft_strdup("0"));
	}
	end = 0;
	if (po < last && last != 1)
	{
		free(lcalc->last);
		last = 1;
	}
	if (po == 0)
		return (ft_strdup("1"));
	if (last == 0)
	{
		last++;
		lcalc->last = ft_memaset('0', po);
		lcalc->last[po - 1] = '5';
	}
	else
		lcalc->last = ft_joinfree(ft_memaset('0', po - last), lcalc->last);
	p = po;
	while (po > last)
	{
		pow.i = 4;
		pow.base = ft_strdup(lcalc->last);
		while (pow.i--)
			ft_addstrings_stack(lcalc->last, pow.base,
				ft_strlen(lcalc->last), ft_strlen(pow.base));
		free(pow.base);
		po--;
	}
	last = p;
	return (ft_strdup(lcalc->last));
}

char	*ft_pow2c(int po)
{
	char	*base;
	char	*ret;

	if (!po)
		return (ft_strdup("0"));
	if (po < 0)
		po = -po;
	ret = ft_strdup("2");
	while (po-- > 1)
	{
		base = ft_strdup(ret);
		ret = ft_new_addstrings(ret, base);
		free(base);
	}
	return (ret);
}

char	*ft_pow2str(int ex, char end)
{
	static t_last_pow pow;

	if (end == 1)
	{
		free(pow.last);
		return(ft_strdup("end"));
	}
	if (ex == 0)
		return (ft_strdup("1"));
	return ((ex > 0) ? ft_pow2c(ex) : ft_pow_neg(-ex, end, &pow));
}
