/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 05:26:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/08 05:08:15 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void		ft_padding(t_printinfo *l)
{
	int zero;

	while (l->next)
	{
		zero = (l->buf[0] == '0' && !l->buf[1]) ? 1 : 0;
		ft_pad_prec(l);
		if (l->t == 'f' && (!ft_strcmp("nan", l->buf)
		|| !ft_strcmp("inf", l->buf) || !ft_strcmp("-inf", l->buf)))
			ft_padding_str(l);
		else if (l->t == 's' || l->t == 'c')
			ft_padding_str(l);
		else if (ft_strchr("diuf", l->t))
			ft_padding_digit(l);
		else if (ft_strchr("xXpo", l->t))
			ft_padding_convert(l, zero);

		l = l->next;
	}
}
