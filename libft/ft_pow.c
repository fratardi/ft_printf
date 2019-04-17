/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:09:02 by tpacaud           #+#    #+#             */
/*   Updated: 2018/11/17 14:21:08 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

long int	ft_pow(int n, int pow)
{
	int			i;
	long int	nbr;

	i = 1;
	nbr = n;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (n);
	while (i < pow)
	{
		nbr *= n;
		i++;
	}
	return (nbr);
}
