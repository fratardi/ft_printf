/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:38:54 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/24 05:26:24 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

/*
**Functions Power 2 and 5 returning a char*
*/

char		*init_pow(int po, int *last, char *str)
{
	if (po < *last && *last != 0)
	{
		ft_strdel(&str);
		*last = 0;
	}
	if (*last == 0)
	{
		str = ft_memaset('0', po);
		str[po - 1] = '5';
		*last = 1;
	}
	else
		str = ft_joinfree(ft_memaset('0', po - *last), str);
	return (str);
}

char		*ft_pow_neg(int po, int end)
{
	static char	*str;
	static int	last = 0;
	t_power5	pow;

	if (end == 1 && last != 0)
	{
		ft_strdel(&str);
		last = 0;
		return (ft_strdup("0"));
	}
	str = init_pow(po, &last, str);
	pow.p = po;
	while (po > last)
	{
		pow.i = 4;
		pow.base = ft_strdup(str);
		while (pow.i--)
			ft_addstrings_stack(str, pow.base,
				ft_strlen(str), ft_strlen(pow.base));
		ft_strdel(&pow.base);
		po--;
	}
	last = pow.p;
	return (ft_strdup(str));
}

char		*ft_pow2c(int po)
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
		ft_strdel(&base);
	}
	return (ret);
}

char		*ft_pow2str(int ex, char end)
{
	if (ex == 0)
		return (ft_strdup("1"));
	return ((ex > 0) ? ft_pow2c(ex) : ft_pow_neg(-ex, end));
}
