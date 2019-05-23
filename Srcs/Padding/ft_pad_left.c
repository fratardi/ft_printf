/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:44:00 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/23 04:58:42 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_left(t_printinfo *l)
{
	int blen;

	blen = ft_strlen(l->buf);
	if (l->left && l->alt && ft_strchr("xX", l->t) && (blen += 2))
		l->buf = ft_joinfree(ft_strdup((l->t == 'x') ? "0x" : "0X"), l->buf);
	if (l->left && (l->width > (int)blen) && l->t != 'n')
	{
		l->buf = ft_joinfree((l->buf), (char *)ft_memaset(' ', l->width -
		blen));
		blen = (size_t)l->width;
	}
	if (l->left && (l->width > (int)blen) && l->t == 'n')
	{
		l->buf = ft_joinfree((char *)ft_memaset('0', l->width - blen),
		l->buf);
		blen = (size_t)l->width;
	}
	l->buflen = blen;
}
