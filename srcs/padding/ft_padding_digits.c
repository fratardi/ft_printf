/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:29:55 by fratardi          #+#    #+#             */
/*   Updated: 2019/08/06 17:24:12 by tpacaud          ###   ########.fr       */
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

char	*padding_extra_digit(t_printinfo *l, int sign, char *buf)
{
	int tmp;

	// printf(">>%s\n", buf);
	if (l->extra && (l->prec == -2 || l->t == 'f') && !l->left)
	{
		tmp = l->width - ft_strlen(buf) - (((sign == -1) ||
			(sign == 1 && l->showsign)) ? 1 : 0);
		if (l->space && buf[0] == '0' && l->t != 'f' && sign == 1)
			tmp--;
		if (l->t == 'f' && l->space && sign == 1)
			tmp--;
		if (ft_strchr("di", l->t) && sign == 1 && l->space && buf[0] != '0')
			tmp--;
		if (tmp > 0)
			return(ft_memaset('0', tmp));
	}
	return (NULL);
}

int		ft_print_pad_dig(t_printinfo *l, int width, char *buf)
{
	int ret;

	ret = 0;
	if (buf == NULL)
		return (0);
	l->prec = (l->t == 'f' && l->prec == -2) ? 6 : l->prec;
	if (width > 0 && !l->left && ((!l->extra && l->prec == -2) ||
		(l->extra) || (l->width > l->prec)))
	{
		ret += ft_print_preset_buf(' ', width);
		ret += ft_display_char_content(buf, ft_strlen(buf));
		if (l->t == 'f' && l->prec > 0 && (size_t)l->prec > ft_declen(buf))
			ret += ft_print_preset_buf('0', l->prec - ft_declen(buf));
	}
	else if (width > 0 && l->left)
	{
		ret += ft_display_char_content(buf, ft_strlen(buf));
		ret += ft_print_preset_buf(' ', width);
		if (l->t == 'f' && l->prec > 0 && (size_t)l->prec > ft_declen(buf))
			ret += ft_print_preset_buf('0', l->prec - ft_declen(buf));
	}
	else
	{
		ret += ft_display_char_content(buf, ft_strlen(buf));
		if (l->t == 'f' && l->prec > 0 && (size_t)l->prec > ft_declen(buf))
			ret += ft_print_preset_buf('0', l->prec - ft_declen(buf));
	}
	return (ret);
}

int		ft_pad_di(t_printinfo *l, char *buf)
{
	int		sign;
	int		width;
	char	*temp;
	
	sign = (buf[0] == '-') ? -1 : 1;
	if (buf[0] == '-')
		temp = ft_strdup(&buf[1]);
	else
		temp = ft_strdup(buf);
	temp = ft_joinfree(padding_extra_digit(l, sign, temp), temp);
	if (l->space && !l->showsign && sign == 1 && !l->is_unsigned)
		temp = ft_joinfree(ft_strdup(" "), temp);
	if (sign == -1 && !l->is_unsigned)
		temp = ft_joinfree(ft_strdup("-"), temp);
	if (l->showsign && sign == 1 && !l->is_unsigned)
		temp = ft_joinfree(ft_strdup("+"), temp);
	width = l->width - ft_strlen(temp);
	return (ft_print_pad_dig(l, width, temp));
}
