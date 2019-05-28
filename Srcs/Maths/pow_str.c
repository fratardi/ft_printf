/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:38:54 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 14:41:55 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Functions Power 2 and 5 returning a char*
*/

char	*ft_pow5(int po, char end)
{
	static char *str[1];
	static int	last = 1;
	char		*temp;
	int			p;
	t_power5 pow;

	if (po == 0)
		return (ft_strdup("1"));
	if (last == 1)
		str[0] = ft_strdup("5");
	p = po;
	while (po > last)
	{
		pow.i = 4;
		pow.base = ft_strdup(str[0]);
		while (pow.i--)
		{
			ft_addstrings_stack(str[0], pow.base, ft_strlen(str[0]), ft_strlen(pow.base));
			printf("<< %s\n", str[0]);
		}
		free(pow.base);
		po--;
	}
	last = p;
	temp = ft_strdup(str[0]);
	if (end == 1)
		free(str[0]);
	return(temp);
}

char	*ft_pow_neg(int po, char end)
{
	static char *str[1];
	static int	last = 1;
	char		*temp;
	int			p;
	t_power5 pow;

	if (po < last && last != 1)
	{
		free(str[0]);
		last = 1;
	}
	if (po == 0)
		return (ft_strdup("1"));
	if (last == 1)
		str[0] = ft_joinfree(ft_memaset('0', po - 1), ft_strdup("5"));
	else if (po > last)
		str[0] = ft_joinfree(ft_memaset('0', po - last), str[0]);
	p = po;
	while (po > last)
	{
		pow.i = 4;
		pow.base = ft_strdup(str[0]);
		while (pow.i--)
		{
			ft_addstrings_stack(str[0], pow.base, ft_strlen(str[0]), ft_strlen(pow.base));
		}
		free(pow.base);
		po--;
	}
	last = p;
	temp = ft_strdup(str[0]);
	end = 0;
	if (end == 1)
		free(str[0]);
	return(temp);
}

/* char	*ft_pow5(int po)
{
	t_power5 pow;

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
} */

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

char	*ft_pow2neg(int n, char end)
{
	char	*ret;
	char	*fill;
	size_t	i;

	printf("pow = %d\n", n);
	ret = ft_pow5(n, end);
	printf("res = %s\n", ret);
	i = n - ft_strlen(ret);
	if (!(fill = (char *)ft_memalloc((sizeof(char)) * (i + 1))))
		return (NULL);
	ft_memset(fill, '0', i);
	return (ft_joinfree(fill, ret));
}

char	*ft_pow2str(int ex, char end)
{
	if (ex == 0)
		return (ft_strdup("1"));
	return ((ex > 0) ? ft_pow2c(ex) : ft_pow2neg(-ex, end));
}
