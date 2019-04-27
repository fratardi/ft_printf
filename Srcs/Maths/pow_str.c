/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:38:54 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/27 15:48:38 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Functions Power 2 and 5 returning a char*
*/

char	*ft_pow5(int po)
{
	char	*base;
	char	*ret;
	size_t	p;
	int		i;

	p = (size_t)po;
	if (po == 0)
		return (ft_strdup("1"));
	if (po < 0)
		po = -po;
	ret = ft_strdup("5");
	while (po > 1)
	{
		i = 4;
		base = ft_strdup(ret);
		while (i--)
			ret = ft_addstrings(ret, base);
		free(base);
		po--;
	}
	return (ret);
}

char	*ft_pow2c(int po)
{
	char	*base;
	char	*ret;
	size_t	p;

	p = (size_t)po;
	if (!po)
		return (ft_strdup("0"));
	if (po < 0)
		po = -po;
	ret = ft_strdup("2");
	while (po-- > 1)
	{
		base = ft_strdup(ret);
		ret = ft_addstrings(ret, base);
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
	return (ft_strjoinfree(fill, ret));
}

char	*ft_pow2str(int ex)
{
	if (ex == 0)
		return (ft_strdup("1"));
	return ((ex > 0) ? ft_pow2c(ex) : ft_pow2neg(-ex));
}
