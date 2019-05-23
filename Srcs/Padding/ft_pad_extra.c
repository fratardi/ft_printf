/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:51:35 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/23 04:55:27 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_extra(t_printinfo *list)
{
	int		sig;
	char	*tmp;

	sig = 0;
	if (!list->extra || (list->prec > 0 && ft_strchr("diouxX", list->t)))
		return ;
	if (((int)list->buflen) >= list->width)
		return ;
	if ((list->buf[0] == '+' && (sig = 1)) || (list->buf[0] == '-' && (sig = -1)))
	{
		tmp = ft_strdup(&list->buf[1]);
		free(list->buf);
		list->buf = tmp;
	}
	list->buf = ft_joinfree((char *)ft_memaset('0', list->width - ((int)list->buflen) - ((list->t == 'c') ? 1 : 0)), list->buf);
	if (sig != 0)
		list->buf = ft_joinfree(ft_strdup((sig == 1) ? "+" : "-"), list->buf);
	if (list->alt && ft_strchr("xX", list->t))
		list->buf[1] = (list->t == 'X') ? 'X' : 'x';
	if (list->space)
		list->buf[0] = ' ';
}
