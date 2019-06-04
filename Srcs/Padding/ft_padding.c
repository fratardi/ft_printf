/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:14:29 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/04 21:10:16 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void		ft_padding_str(t_printinfo *l)
{
	int width;

	width = l->width - ft_strlen(l->buf) - ((l->special == 0) ? 1 : 0);
	if (width > 0 && !l->left)
		l->buf = ft_joinfree(ft_memaset(((l->t == 'c' || l->buf[0] == 0 ||
		l->t == 's') && l->extra) ? '0' : ' ', width), l->buf);
	if (width > 0 && l->left)
		l->buf = ft_joinfree(l->buf, ft_memaset(' ', width));
}

void		padding_hash_convert(t_printinfo *l)
{
	char *temp;

	if (l->alt && ft_strchr("xX", l->t) && l->buf[0] && l->buf[ft_strlen(l->buf) - 1] != '0')
	{
		l->buf = ft_joinfree(ft_strdup((l->t == 'x') ? "0x" : "0X"), l->buf);
		if (!ft_strcmp("0x0", l->buf) || !ft_strcmp("0X0", l->buf))
		{
			temp = ft_strdup("0");
			free(l->buf);
			l->buf = temp;
		}
	}
	else if (l->alt && ft_strchr("oO", l->t))
	{
		if ((!l->extra && ((l->prec >= -2 && l->buf[0] != '0') ||
		(l->prec > (int)ft_strlen(l->buf) && l->buf[0] == '0'))) || l->extra)
			l->buf = ft_joinfree(ft_strdup("0"), l->buf);
	}
}

void		ft_padding_convert(t_printinfo *l)
{
	int width;

	width = l->width - ft_strlen(l->buf) - ((ft_strchr("xX", l->t) && l->alt) ?
	2 : 0);
	if (l->extra && l->prec == -2 && l->t != 'p' && width > 0 && !l->left)
	{
		if (ft_strchr("oO", l->t) && l->alt)
			width--;
		l->buf = ft_joinfree(ft_memaset('0', width), l->buf);
	}
	padding_hash_convert(l);
	width = l->width - ft_strlen(l->buf);
	if (width > 0 && !l->left && l->extra && l->buf[ft_strlen(l->buf) - 1] == '0' && l->alt)
		l->buf = ft_joinfree(ft_memaset('0', width), l->buf);
	else if (width > 0 && !l->left && ((!l->extra && l->prec == -2) || (l->extra) ||
	(l->width > l->prec)))
		l->buf = ft_joinfree(ft_memaset(' ', width), l->buf);
	if (width > 0 && l->left && ((!l->extra && l->prec == -2) || (l->extra) ||
	(l->width > l->prec)))
		l->buf = ft_joinfree(l->buf, ft_memaset(' ', width));
}

void		padding_extra_digit(t_printinfo *l, int sign)
{
	int tmp;

	if (l->extra && (l->prec == -2 || l->t == 'f') && !l->left)
	{
		tmp = l->width - ft_strlen(l->buf) - (((sign == -1) ||
		(sign == 1 && l->showsign)) ? 1 : 0);
		if (l->space && l->buf[0] == '0' && l->t != 'f' && sign == 1)
			tmp--;
		if (l->t == 'f' && l->space && sign == 1)
			tmp--;
		if (ft_strchr("di", l->t) && sign == 1 && l->space && l->buf[0] != '0')
			tmp--;
		if (tmp > 0)
			l->buf = ft_joinfree(ft_memaset('0', tmp), l->buf);
	}
}

void		ft_padding_digit(t_printinfo *l)
{
	int		sign;
	int		width;
	char	*temp;

	sign = (l->buf[0] == '-') ? -1 : 1;
	if (l->buf[0] == '-')
	{
		temp = ft_strdup(&l->buf[1]);
		free(l->buf);
		l->buf = temp;
	}
	padding_extra_digit(l, sign);
	if (l->space && !l->showsign && sign == 1 && !l->is_unsigned)
		l->buf = ft_joinfree(ft_strdup(" "), l->buf);
	if (sign == -1 && !l->is_unsigned)
		l->buf = ft_joinfree(ft_strdup("-"), l->buf);
	if (l->showsign && sign == 1 && !l->is_unsigned)
		l->buf = ft_joinfree(ft_strdup("+"), l->buf);
	width = l->width - ft_strlen(l->buf);
	if (width > 0 && !l->left && ((!l->extra && l->prec == -2) || (l->extra) ||
	(l->width > l->prec)))
		l->buf = ft_joinfree(ft_memaset(' ', width), l->buf);
	if (width > 0 && l->left)
		l->buf = ft_joinfree(l->buf, ft_memaset(' ', width));
}
