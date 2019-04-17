/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:19:33 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/15 21:52:07 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dstt;
	unsigned char *srct;

	dstt = (unsigned char*)dst;
	srct = (unsigned char*)src;
	while (n-- > 0)
		*(dstt + n) = *(srct + n);
	return (dst);
}
