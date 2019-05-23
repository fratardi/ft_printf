/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:42:57 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/23 07:01:49 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_mod_space(t_printinfo *l, int width, int blen)
{
	if (ft_strchr("aAdeEfFgGiucspb", l->t) && ((width > blen)) && !l->extra)
	{
		l->buf = ft_joinfree(ft_memaset(' ', width - blen), l->buf);
		l->buflen = width;
	}
	if (ft_strchr("aAdeEfFgGid", l->t) && l->width == -2 &&
		l->space && !l->showsign && !l->extra)
	{
		l->buf = ft_joinfree(ft_strdup(" "), l->buf);
		l->buflen += 1;
	}
}

void	ft_pad_space(t_printinfo *l)
{
	int width;
	int blen;

	width = l->width;
	blen = ft_strlen(l->buf);
	if (l->left || (ft_strchr(l->buf, '-') && width == -2))
		return ;
	if (ft_strchr("xXo", l->t) && !l->extra && width > blen &&
		(l->buflen = width))
		l->buf = ft_joinfree(ft_memaset(' ', width - blen), l->buf);
	ft_mod_space(l, width, blen);
	if (ft_strchr("di", l->t) && l->extra && l->prec != -2 &&
		!l->showsign)
	{
		l->buf = ft_joinfree(ft_memaset(' ', width - blen), l->buf);
		l->buflen = width;
	}
}
