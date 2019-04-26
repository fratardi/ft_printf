/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaybin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:48:41 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/26 18:49:08 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void ft_displaybin(void *content, size_t n)
{

	unsigned char *tmp;
	unsigned int mask;

	tmp = (unsigned char *)content + n - 1;
	while(n--)
	{
		mask = 0x100;
		while((mask = mask >> 1))
			(*tmp & mask) ? ft_putchar('1') :ft_putchar('0');
		tmp--;
	}
}
