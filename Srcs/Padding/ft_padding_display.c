/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:12:49 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/16 17:53:14 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

int		ft_padding_display(t_printinfo *l)
{
	int zero;

	zero = (l->buf[0] == '0' && !l->buf[1]) ? 1 : 0;
	if (l->t == 'p' && !ft_strcmp("0x0", l->buf))
		zero = 1;
	ft_pad_prec(l);
	if (l->t == 'f' && (!ft_strcmp(l->buf, "nan") || !ft_strcmp(l->buf, "inf")
		|| !ft_strcmp(l->buf, "-inf")))
		return (ft_pad_float(l));
	if (ft_strchr("diuUf", l->t))
		return (ft_pad_di(l));
	if (ft_strchr("xXoOp", l->t))
		return (ft_pad_xo(l, zero));
	if (l->t == 'c' || l->t == 's' || ft_strchr("Bb", l->t))
		return (ft_pad_char_type(l));
	if (l->t == 'f' && l->prec == 0 && l->showsign && !l->alt && !l->extra)
		l->buf[ft_strlen(l->buf) - 1] = 0;
	return (0);
}
