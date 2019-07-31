/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 02:56:44 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/25 15:34:05 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

int			ft_pad_char_type(t_printinfo *l)
{
	int	width;
	int	ret;

	ret = 0;
	width = l->width - ft_strlen(l->buf) - ((l->special == 0) ? 1 : 0);
	if (width > 0 && !l->left)
	{
		ret += ft_print_preset_buf(((l->t == 'c' || l->buf[0] == 0 ||
		l->t == 's') && l->extra) ? '0' : ' ', width);
		ret += ft_print_uni_str(l->buf);
	}
	else if (width > 0 && l->left)
	{
		ret += ft_print_uni_str(l->buf);
		ret += ft_print_preset_buf(((l->t == 'c' || l->buf[0] == 0 ||
			l->t == 's') && l->extra) ? '0' : ' ', width);
	}
	else
		ret += ft_print_uni_str(l->buf);
	return (ret);
}

int			ft_pad_float(t_printinfo *l)
{
	int	width;
	int	ret;

	ret = 0;
	width = l->width - ft_strlen(l->buf) - ((l->special == 0) ? 1 : 0);

	if (width > 0 && !l->left)
	{
		ret += ft_print_preset_buf(' ', width);
		ret += ft_print_uni_str(l->buf);
	}
	else if (width > 0 && l->left)
	{
		ret += ft_print_uni_str(l->buf);
		ret += ft_print_preset_buf(' ', width);
	}
	else
		ret += ft_print_uni_str(l->buf);
	return (ret);
}

void		padding_hash_convert(t_printinfo *l, int zero)
{
	char	*temp;
	int		octal;

	octal = (l->prec > (int)ft_strlen(l->buf)) ? 1 : 0;
	if (l->alt && ft_strchr("xX", l->t) && l->buf[0] && !zero)
	{
		l->buf = ft_joinfree(ft_strdup((l->t == 'x') ? "0x" : "0X"), l->buf);
		if (!ft_strcmp("0x0", l->buf) || !ft_strcmp("0X0", l->buf))
		{
			temp = ft_strdup("0");
			ft_strdel(&(l->buf));
			l->buf = temp;
		}
	}
	else if (l->alt && ft_strchr("oO", l->t))
	{
		if ((!l->extra && ((l->prec >= -2 && !zero) ||
			(octal && zero))) || (l->extra && (!zero || octal)))
		{
			l->buf = ft_joinfree(ft_strdup("0"), l->buf);
		}
	}
}

int			ft_display_pad_xo(t_printinfo *l, int zero, int width, int ret)
{
	if (width > 0 && !l->left && l->extra && zero && l->prec == -2 && (l->alt
				|| l->t == 'p'))
	{
		ret += (l->t == 'p' && zero) ? ft_print_uni_str("0x") : 0;
		ret += ft_print_preset_buf('0', width);
		ret += ft_print_uni_str((l->t == 'p' && zero) ? &l->buf[2] : l->buf);
	}
	else if (width > 0 && !l->left &&
			((!l->extra && l->prec == -2) || (l->extra)
			|| (l->width > l->prec)))
	{
		ret += ft_print_preset_buf(' ', width);
		ret += ft_print_uni_str(l->buf);
	}
	else if (width > 0 && l->left && ((!l->extra && l->prec == -2)
			|| (l->extra) || (l->width > l->prec)))
	{
		ret += ft_print_uni_str(l->buf);
		ret += ft_print_preset_buf(' ', width);
	}
	else
		ret += ft_print_uni_str(l->buf);
	return (ret);
}

int			ft_pad_xo(t_printinfo *l, int zero)
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
	padding_hash_convert(l, zero);
	width = l->width - ft_strlen(l->buf);
	return (ft_display_pad_xo(l, zero, width, 0));
}
