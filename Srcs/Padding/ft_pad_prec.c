/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:54:25 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/12 01:11:59 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_mod_pad_prec(int prec, t_printinfo *list)
{
	if (prec < 0 && list->t == 's')
		list->buflen = (size_t)list->prec;
	if (ft_strchr("ouxX", list->t) && prec)
		list->buflen += prec;
	if (ft_strchr("di", list->t) && prec)
		list->buflen += prec;
}

void	ft_pad_prec(t_printinfo *l)
{
	int prec;
	int neg;
	char *temp;

	neg = 0;
	if (l->prec < 0 || l->t == 'f' || l->t == 'c' || l->t == 'p')
		return ;
	prec = l->prec - l->buflen + ((l->buf[0] == '-' &&
	ft_strchr("di", l->t)) ? 1 : 0);
	if (ft_strchr("uoxX", l->t) && prec > 0)
		l->buf = ft_strjoinfree(ft_memaset('0', (size_t) prec), l->buf);
	l->buf[l->prec] = (l->t == 's' && prec < 0) ? 0 : l->buf[l->prec];
	if (ft_strchr("di", l->t))
	{
		if (prec && l->buf[0] == '-' && (neg = -1))
		{
			temp = ft_strdup(&l->buf[1]);
			free(l->buf);
			l->buf = temp;
		}
		l->buf = (prec) ?
		ft_strjoinfree(ft_memaset('0', (size_t)prec), l->buf) : l->buf; 
		l->buf = (neg != 0) ? ft_strjoinfree(ft_strdup("-"), l->buf) : l->buf;
	}
/* 	if (prec > (int)l->buflen) */
		ft_mod_pad_prec(prec, l);
}