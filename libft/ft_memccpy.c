/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:24:26 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/29 09:06:33 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*srct;
	unsigned char	*dstt;

	srct = (unsigned char *)src;
	dstt = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(dstt + i) = *(srct + i);
		if (*(srct + i) == (unsigned char)c)
			return ((void*)&*(dstt + i + 1));
		i++;
	}
	return (NULL);
}
