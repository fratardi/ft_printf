/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 05:26:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/30 05:26:45 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void		ft_padding(t_printinfo *l)
{
	while (l->next)
	{
		ft_pad_prec(l);
		if (l->t == 's' || l->t == 'c')
			ft_padding_str(l);
		else if (ft_strchr("diuf", l->t))
			ft_padding_digit(l);
		else if (ft_strchr("xXpo", l->t))
			ft_padding_convert(l);
		if (l->t == 'f' && l->prec == 0 && l->showsign && !l->alt && !l->extra)
			l->buf[ft_strlen(l->buf) - 1] = 0;
		l = l->next;
	}
}
