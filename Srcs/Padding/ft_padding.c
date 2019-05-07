/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:59:36 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/29 23:46:39 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void ft_padding_float(t_printinfo *list)
{
	int width;
	int len;

	if (list->space && list->buf[0] != '-')
	{
		list->buf = ft_strjoinfree(ft_strdup(" "), list->buf);
		list->width--;
	}
	len = (int)ft_strlen(list->buf);
	width = list->width - len - 1;
	while (width >= 0 && !list->left)
	{
		list->buf = ft_strjoinfree(ft_strdup(list->extra ? "0" : " "), list->buf);
		width--;
	}
	while (width >= 0 && list->left)
	{
		list->buf = ft_strjoinfree(list->buf, ft_strdup(" "));
		width--;
	}
}

void ft_padding_str(t_printinfo *list)
{
	int width;
	int prec;
	int len;

	len = (int)ft_strlen(list->buf);
	prec = list->prec;
	if (list->prec < len)
	{
		list->buf[list->prec] = 0;
		len = (int)ft_strlen(list->buf);
	}
	width = list->width - len - 1;
	while (width >= 0 && !list->left)
	{
		list->buf = ft_strjoinfree(ft_strdup(" "), list->buf);
		width--;
	}
	while (width >= 0 && list->left)
	{
		list->buf = ft_strjoinfree(list->buf, ft_strdup(" "));
		width--;
	}
}

void ft_padding_convert(t_printinfo *list)
{
	int width;
	int prec;
	int len;

	if (list->alt)
		list->buf = ft_strjoinfree(ft_strdup((list->t != 'X') ? "0x" : "0X"), list->buf);
	len = (int)ft_strlen(list->buf);
	prec = list->prec;
	if (prec < len)
	{
		list->buf[list->prec] = 0;
		len = (int)ft_strlen(list->buf);
	}
	width = list->width - len - 1;
	while (width >= 0 && !list->left)
	{
		if (list->alt)
			list->buf[1] = '0';
		list->buf = ft_strjoinfree(ft_strdup(list->extra ? "0" : " "), list->buf);
		width--;
		if (width < 0 && list->alt)
		{
			list->buf[0] = '0';
			list->buf[1] = (list->t != 'X') ? 'x' : 'X';
		}
	}
	while (width >= 0 && list->left)
	{
		list->buf = ft_strjoinfree(list->buf, ft_strdup(" "));
		width--;
	}
}

void ft_padding_digit(t_printinfo *list)
{
	int width;
	int prec;
	int len;

	if (list->showsign && list->buf[0] != '-')
		list->buf = ft_strjoinfree(ft_strdup("+"), list->buf);
	else if (list->space && list->buf[0] != '-')
	{
		list->buf = ft_strjoinfree(ft_strdup(" "), list->buf);
		list->width--;
	}
	len = (int)ft_strlen(list->buf);
	prec = list->prec;
	if (prec < len)
	{
		list->buf[list->prec] = 0;
		len = (int)ft_strlen(list->buf);
	}
	width = list->width - len - 1;
	while (width >= 0 && !list->left)
	{
		list->buf = ft_strjoinfree(ft_strdup(list->extra ? "0" : " "), list->buf);
		width--;
	}
	while (width >= 0 && list->left)
	{
		list->buf = ft_strjoinfree(list->buf, ft_strdup(" "));
		width--;
	}
}

void ft_padding(t_printinfo *list)
{
	while (list->next)
	{
		if (list->t == 's' || list->t == 'c')
			ft_padding_str(list);
		else if (ft_strchr("diu", list->t))
			ft_padding_digit(list);
		else if (ft_strchr("oxXp", list->t))
			ft_padding_convert(list);
		else if (list->t == 'f')
			ft_padding_float(list);
		list = list->next;
	}
}