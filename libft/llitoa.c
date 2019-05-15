/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:17:43 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/12 14:30:14 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_powten(int count)
{
	long int nb;

	nb = 10;
	if (count == 1)
		return (1);
	while (count > 2)
	{
		nb = nb * 10;
		count--;
	}
	return (nb);
}

static int		howmany(unsigned long long int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char		*ft_fill(long long int n, int i, int count, char *str)
{
	if (n == 0 || n == -0)
		return (str = "0");
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (count > 0)
	{
		str[i] = (n / ft_powten(count)) + 48;
		n = (n % ft_powten(count));
		count--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_llitoa(long long n)
{
	char	*str;
	int		count;
	int		i;

	count = howmany((unsigned long long int)n);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (count + 2))))
			return (NULL);
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
			return (NULL);
	}
	return (ft_fill(n, i, count, str));
}
