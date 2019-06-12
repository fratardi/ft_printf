/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:54:25 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/12 08:09:12 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void		ft_mod_pad_prec(int prec, t_printinfo *list)
{
	if (prec < 0 && list->t == 's' && list->prec != -2)
			list->buflen = (size_t)list->prec;
	if (prec > (int)list->buflen)
	{
		if (ft_strchr("oOUuxX", list->t) && prec > list->width)
			list->buflen += prec;
		if (ft_strchr("di", list->t) && prec)
			list->buflen += prec;
	}
}

t_printinfo	*ft_precdigits(int prec, int neg, t_printinfo *l)
{
	char *temp;

	if (ft_strchr("di", l->t))
	{
		if (prec && l->buf[0] == '-' && (neg = -1))
		{
			temp = ft_strdup(&l->buf[1]);
			free(l->buf);
			l->buf = temp;
		}
		l->buf = (prec > 0) ? ft_joinfree(ft_memaset('0', (size_t)prec),
				l->buf) : l->buf;
		l->buf = (neg != 0) ? ft_joinfree(ft_strdup("-"), l->buf) : l->buf;
	}
	return (l);
}

void		ft_prec_uns_ptr(t_printinfo *l, int prec)
{
	char *temp;
	char *pad;

	if (ft_strchr("uoxX", l->t) && prec > 0)
	{
		pad = ft_memaset('0', (size_t)prec -
				((ft_strchr("oO", l->t) && l->alt) ? 1 : 0));
		l->buf = ft_joinfree(pad, l->buf);
		l->buflen += prec;
	}
	if (l->t == 'p' && l->prec > (int)ft_strlen(l->buf))
	{
		temp = ft_strdup(&l->buf[2]);
		free(l->buf);
		l->buf = ft_joinfree(pad, temp);
		pad = ft_memaset('0', l->prec - ft_strlen(temp));
		l->buf = ft_joinfree(ft_strdup("0x"), l->buf);
	}
}

void		ft_pad_prec(t_printinfo *l)
{
	int prec;
	int neg;

	neg = 0;
	if ((l->prec == 0) && (ft_strchr("diuxX", l->t) || (ft_strchr("oO", l->t)
				&& !l->alt)) && l->buflen == 1 && l->buf[0] == '0')
	{
		l->buf[0] = 0;
		l->buflen = 0;
		return ;
	}
	if (l->prec < 0 || l->t == 'f' || l->t == 'c')
		return ;
	prec = l->prec - ft_strlen(l->buf) + ((l->buf[0] == '-' &&
			ft_strchr("di", l->t)) ? 1 : 0);
	ft_prec_uns_ptr(l, prec);
	if (l->t == 'p' && l->prec == 0 && l->buf[2] == '0')
		l->buf[2] = 0;
	if (l->t == 's' && prec < 0 && l->prec >= 0)
		l->buf[l->prec] = 0;
	l = ft_precdigits(prec, neg, l);
	ft_mod_pad_prec(prec, l);
}
