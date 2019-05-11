/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:44:00 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/12 00:23:31 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_left(t_printinfo *list )
{
	if(list->left && (list->width > (int)list->buflen) && list->t != 'n')
	{
		list->buf = ft_strjoinfree((list->buf), (char *)ft_memaset(' ',  list->width - list->buflen));
			list->buflen = (size_t)list->width;
	}
	if(list->left && (list->width > (int)list->buflen) && list->t == 'n')
	{
		list->buf = ft_strjoinfree((char *)ft_memaset('0', list->width - list->buflen), list->buf);	
		list->buflen = (size_t)list->width;
	}
}
