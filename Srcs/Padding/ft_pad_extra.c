/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:51:35 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/09 20:37:41 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_extra(t_printinfo *list)
{

	// option 0
//	ft_debug(list);
//	printf("extra  =->   %d prec = -> %d width =  ->  %d \n", list->extra, list->prec , list->width);
	if(!list->extra || (list->prec && ft_strchr("diouxX", list->t)))
		return;
	if((list->extra && ft_strchr("diouxXf", list->t) ) || ((int)list->buflen) >= list->width)
		return;
	list->buf = ft_strjoinfree((char *)ft_memaset('0', list->width - ((int)list->buflen)), list->buf);
	//ft_putendl(list->buf);
}
