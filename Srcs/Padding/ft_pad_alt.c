/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_alt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:41:16 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/12 03:47:58 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_alt(t_printinfo *list)
{
	if (ft_strcmp("0", list->buf) == 0)
		return ;
	if(list->alt && list->buf[0])
	{
		if (list->t == 'o' && !list->extra && (list->buflen += 1))
			list->buf = ft_strjoinfree(ft_strdup("0"), list->buf);
		if(list->t == 'x' && !list->extra && (list->buflen += 2))
			list->buf = ft_strjoinfree(ft_strdup("0x"), list->buf);
		if(list->t == 'X' && !list->extra && (list->buflen += 2))
			list->buf = ft_strjoinfree(ft_strdup("0X"), list->buf);
		list->buf[list->buflen] = 0;
	}
}
