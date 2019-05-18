/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:44:00 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/18 03:13:11 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void ft_pad_left(t_printinfo *l)
{
	if (l->left && l->alt && ft_strchr("xX", l->t) && (l->buflen += 2))
		l->buf = ft_joinfree(ft_strdup((l->t == 'x') ? "0x" : "0X"), l->buf);
	if (l->left && (l->width > (int)l->buflen) && l->t != 'n')
	{
		l->buf = ft_joinfree((l->buf), (char *)ft_memaset(' ', l->width -
		l->buflen));
		l->buflen = (size_t)l->width;
	}
	if (l->left && (l->width > (int)l->buflen) && l->t == 'n')
	{
		l->buf = ft_joinfree((char *)ft_memaset('0', l->width - l->buflen),
		l->buf);
		l->buflen = (size_t)l->width;
	}
}
