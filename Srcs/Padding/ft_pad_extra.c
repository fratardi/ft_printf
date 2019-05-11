/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:51:35 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/12 01:58:25 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_extra(t_printinfo *list)
{
	int sig;
	char *tmp;
	// option 0
//	ft_debug(list);
//	printf("extra  =->   %d prec = -> %d width =  ->  %d \n", list->extra, list->prec , list->width);
	sig = 0;
	if(!list->extra || (list->prec > 0 && ft_strchr("diouxX", list->t)))
		return;
	if(((int)list->buflen) >= list->width)
		return;
	if ((list->buf[0] == '+' && (sig = 1)) || (list->buf[0] == '-' && (sig = -1)))
	{
		tmp = ft_strdup(&list->buf[1]);
		free(list->buf);
		list->buf = tmp;
	}
	list->buf = ft_strjoinfree((char *)ft_memaset('0', list->width - ((int)list->buflen)), list->buf);
	if (sig != 0)
		list->buf = ft_strjoinfree(ft_strdup((sig == 1) ? "+" : "-"), list->buf);
	//ft_putendl(list->buf);
}
