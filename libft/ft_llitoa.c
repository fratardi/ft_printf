/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:32:38 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/29 17:03:14 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nblen(long long int nb)
{
	long int	nbl;
	int			i;

	i = 0;
	nbl = nb;
	if (nbl < 0)
	{
		i = i + 1;
		nbl = -nbl;
	}
	while ((nbl / 10) > 0)
	{
		i++;
		nbl = nbl / 10;
	}
	return (i + 1);
}

char			*ft_llitoa(long long int n)
{
	char			*rez;
	long long int	nbl;
	long long int	i;

	nbl = n;
	i = 0;
	if (nbl == 0)
		return (ft_strdup("0"));
	if (!(rez = (char*)ft_memalloc((sizeof(char) * ft_nblen(nbl) + 1))))
		return (NULL);
	i = ft_nblen(nbl) - 1;
	if (nbl < 0)
		nbl = -nbl;
	rez[i] = '\0';
	while (i >= 0)
	{
		rez[i] = nbl % 10 + '0';
		i--;
		nbl = nbl / 10;
	}
	if (n < 0)
		rez[0] = '-';
	return (rez);
}
