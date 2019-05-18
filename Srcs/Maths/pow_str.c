/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:38:54 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/18 04:13:25 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Functions Power 2 and 5 returning a char*
*/

char	*ft_pow5(int po)
{
	t_power5 pow;

	pow.p = (size_t)po;
	if (po == 0)
		return (ft_strdup("1"));
	if (po < 0)
		po = -po;
	pow.ret = ft_strdup("5");
	while (po > 1)
	{
		pow.i = 4;
		pow.base = ft_strdup(pow.ret);
		while (pow.i--)
		{
			pow.tmp = ft_addstrings(pow.ret, pow.base);
			free(pow.ret);
			pow.ret = ft_strdup(pow.tmp);
			free(pow.tmp);
		}
		free(pow.base);
		po--;
	}
	return (pow.ret);
}

char	*ft_pow2c(int po)
{
	char	*base;
	char	*ret;
	char	*tmp;

	if (!po)
		return (ft_strdup("0"));
	if (po < 0)
		po = -po;
	ret = ft_strdup("2");
	while (po-- > 1)
	{
		base = ft_strdup(ret);
		tmp = ft_addstrings(ret, base);
		free(ret);
		ret = ft_strdup(tmp);
		free(tmp);
		free(base);
	}
	return (ret);
}

char	*ft_pow2neg(int n)
{
	char	*ret;
	char	*fill;
	size_t	i;

	ret = ft_pow5(n);
	i = n - ft_strlen(ret);
	if (!(fill = (char *)ft_memalloc((sizeof(char)) * (i + 1))))
		return (NULL);
	ft_memset(fill, '0', i);
	return (ft_joinfree(fill, ret));
}

char	*ft_pow2str(int ex)
{
	if (ex == 0)
		return (ft_strdup("1"));
	return ((ex > 0) ? ft_pow2c(ex) : ft_pow2neg(-ex));
}
