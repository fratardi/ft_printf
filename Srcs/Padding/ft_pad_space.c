/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:42:57 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/11 20:32:45 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_space(t_printinfo *list)
{
	int 	width;
	int 	blen;

	width = list->width;
	blen = list->buflen;
	if(!list->space)
		return;
	if(ft_strchr(list->buf , '-') && (width == -2 || !list->space))
		return;
	if(ft_strchr("aAdeEfFgGi",list->t) && ((width > blen)))
	{

		list->buf = ft_strjoinfree(ft_memaset(' ', width - blen) , list->buf);
		list->buflen = width;
	}
	if(list->width == -2)
	{
		list->buf = ft_strjoinfree(ft_strdup(" "), list->buf);
		list->buflen += 1;
	}
}
