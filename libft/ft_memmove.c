/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:28:37 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/21 22:38:08 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dstt;
	unsigned char	*srct;

	i = 0;
	dstt = (unsigned char*)dst;
	srct = (unsigned char*)src;
	if (dstt > srct)
		while (len-- > 0)
			dstt[len] = srct[len];
	else
		while (i < len)
		{
			dstt[i] = srct[i];
			i++;
		}
	return (dstt);
}
