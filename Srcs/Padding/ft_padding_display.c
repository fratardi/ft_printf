/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:12:49 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/10 19:56:57 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

int		ft_padding_display(t_printinfo *l)
{
	int zero;

	zero = (l->buf[0] == '0' && !l->buf[1]) ? 1 : 0;
	ft_pad_prec(l);
	if (ft_strchr("diuUf", l->t))
		return (ft_pad_di(l));
	if (ft_strchr("xXoOp", l->t))
		return (ft_pad_xo(l, zero));
	if (l->t == 'c' || l->t == 's')
		return (ft_pad_char_type(l));
	if (l->t == 'f' && l->prec == 0 && l->showsign && !l->alt && !l->extra)
		l->buf[ft_strlen(l->buf) - 1] = 0;
	return (0);
}
