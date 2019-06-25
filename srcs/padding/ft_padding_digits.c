/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:29:55 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/25 15:34:34 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

size_t			ft_declen(char *str)
{
	size_t pos;

	pos = 0;
	while(str[pos] && str[pos] != '.')
		pos++;
	pos++;
	return(ft_strlen(&str[pos]));
}

void	padding_extra_digit(t_printinfo *l, int sign)
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

int		ft_print_pad_dig(t_printinfo *l, int width)
{
	int ret;

	ret = 0;
	l->prec = (l->t == 'f' && l->prec == -2) ? 6 : l->prec;
	if (width > 0 && !l->left && ((!l->extra && l->prec == -2) ||
		(l->extra) || (l->width > l->prec)))
	{
		ret += ft_print_preset_buf(' ', width);
		ret += ft_print_uni_str(l->buf);
		if (l->t == 'f' && l->prec > 0 && (size_t)l->prec > ft_declen(l->buf))
			ret += ft_print_preset_buf('0', l->prec - ft_declen(l->buf));
	}
	else if (width > 0 && l->left)
	{
		ret += ft_print_uni_str(l->buf);
		ret += ft_print_preset_buf(' ', width);
		if (l->t == 'f' && l->prec > 0 && (size_t)l->prec > ft_declen(l->buf))
			ret += ft_print_preset_buf('0', l->prec - ft_declen(l->buf));
	}
	else
	{
		ret += ft_print_uni_str(l->buf);
		if (l->t == 'f' && l->prec > 0 && (size_t)l->prec > ft_declen(l->buf))
			ret += ft_print_preset_buf('0', l->prec - ft_declen(l->buf));
	}
	return (ret);
}

int		ft_pad_di(t_printinfo *l)
{
	int		sign;
	int		width;
	char	*temp;

	sign = (l->buf[0] == '-') ? -1 : 1;
	if (l->buf[0] == '-')
	{
		temp = ft_strdup(&l->buf[1]);
		ft_strdel(&(l->buf));
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
	return (ft_print_pad_dig(l, width));
}
