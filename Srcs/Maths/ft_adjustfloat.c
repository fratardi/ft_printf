/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:03:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/27 14:30:54 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void ft_adjustnegpo(char **s1, char **s2)
{
	size_t i1;
	size_t i2;
	char *tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_strjoinfree(*s1, tojoin);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_strjoinfree(*s2, tojoin);
	}
}

void ft_adjustpospo(char **s1, char **s2)
{
	size_t i1;
	size_t i2;
	char *tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_strjoinfree(tojoin, *s1);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_strjoinfree(tojoin, *s2);
	}
}

void ft_floatEdispneg(char *str, int prec)
{
	int i;
	int y;
	int puiss;

	i = 2;
	y = 0;
	puiss = 0;
	if (str[0] != '0')
		return;
	while (str[i] && str[i] == '0')
		i++;
	puiss = i - 1;
	ft_printf("Nous__%c.", str[i]);
	while (y++ < prec)
		ft_putchar(str[i++]);
	ft_printf("E-%d\n", puiss);
}

char *ft_rounding(char *str, size_t prec)
{
	int i;

	i = 0;
	if (prec > ft_strlen(str))
	{
		while(prec > ft_strlen(str))
			str = ft_strjoinfree(str, ft_strdup("0"));
		return(str);
	}
	i += prec;
	if (str[i] == '5')
		while (str[i] && str[i] == '5')
			i++;
	if (str[i] == 0 || str[i] > '5')
	{
		str[prec] = 0;
		str = ft_addstrings(str, ft_strdup("1"));
	}
	str[prec] = 0;
	return (str);
}