/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_alt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:41:16 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/09 19:45:22 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_alt(t_printinfo *list)
{
	if(list->alt)
	{
		if(list->t == 'x' && !list->extra)
			list->buf = ft_strjoinfree(ft_strdup("0x"), list->buf);
		if(list->t == 'X' && !list->extra)
			list->buf = ft_strjoinfree(ft_strdup("0X"), list->buf);
	}
}
