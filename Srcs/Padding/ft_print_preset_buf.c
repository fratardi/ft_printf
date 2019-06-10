/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_preset_buf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:07:36 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/10 20:09:11 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

int	ft_print_preset_buf(unsigned char c, int n)
{
	static char		lign[BUFF_SIZE];
	int				i;

	i = 0;
	if (n == 0)
		return (0);
	ft_memset(lign, c, BUFF_SIZE);
	while (i < n)
	{
		if ((n - i) > BUFF_SIZE)
			i += (int)write(1, lign, BUFF_SIZE);
		if ((n - i) <= BUFF_SIZE)
			i += (int)write(1, lign, n - i);
	}
	return (i);
}
