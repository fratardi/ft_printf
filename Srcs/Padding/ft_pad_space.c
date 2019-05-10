/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:42:57 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/10 23:34:03 by fratardi         ###   ########.fr       */
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
	if(ft_strchr(list->buf , '-') && (width == -2 || !list->space)  )
		return;
	if(ft_strchr("aAdeEfFgGi",list->t) && ((width > blen) ))
	{
		
		list->buf = ft_strjoinfree(ft_memaset(' ', width - blen) , list->buf);
		list->buflen = width;
	/*	
	 *
	 *	ft_putchar('\n');
		ft_putnbr(list->buflen);
		ft_putchar('\n');
		*/
	}
	if(!list->prec)
		list->buf = ft_strjoinfree(ft_strdup(" "), list->buf);
}
