/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjustfloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:03:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 16:42:22 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Functions to adjust str_numbers for addstrings
*/

void	ft_adjustnegpo(char **s1, char **s2)
{
	size_t	i1;
	size_t	i2;
	char	*tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return ;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return ;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_joinfree(*s1, tojoin);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return ;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_joinfree(*s2, tojoin);
	}
}

void	ft_adjustpospo(char **s1, char **s2)
{
	size_t	i1;
	size_t	i2;
	char	*tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return ;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return ;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_joinfree(tojoin, *s1);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return ;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_joinfree(tojoin, *s2);
	}
}

/*
**Function to display str_long_double with E^
*/

char	*ft_floatexp(char *str, int prec)
{
	int		i;
	int		y;
	int		puiss;
	char	*ret;

	i = 2;
	y = 0;
	puiss = 0;
	if (str[0] != '0')
		return (str);
	while (str[i] && str[i] == '0')
		i++;
	puiss = i - 1;
	ret = ft_memaset(str[i], 1);
	ret = ft_joinfree(ret, ft_strdup("."));
	ret = ft_joinfree(ret, ft_strndup(&str[i + 1], (prec) ? prec : 6));
	ret = ft_joinfree(ret, ft_strdup("E-"));
	ret = ft_joinfree(ret, ft_itoa(puiss));
	free(str);
	prec = 0;
	return (ret);
}

/*
**Function to round decimal part
*/

char	*ft_rounding(char *str, size_t prec)
{
	int		i;
	char	*tmp;

	i = 0;
	if (prec > ft_strlen(str))
	{
		while (prec > ft_strlen(str))
			str = ft_joinfree(str, ft_strdup("0"));
		return (str);
	}
	i += prec;
/* 	if (str[i] == '5')
		while (str[i] && str[i] == '5')
			i++; */
	if (str[i] == 0 || str[i] >= '5')
	{
		str[prec] = 0;
		tmp = ft_strdup("1");
		str = ft_addstrings(str, tmp);
		free(tmp);
	}
	str[prec] = 0;
	return (str);
}
