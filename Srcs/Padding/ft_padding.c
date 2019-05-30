/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:14:29 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/30 02:53:24 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void ft_padding_str(t_printinfo *list)
{
	int width;

	width = list->width - ft_strlen(list->buf) - ((list->special == 0) ? 1 : 0);    
	if (width > 0 && !list->left)
		list->buf = ft_joinfree(ft_memaset(((list->t == 'c' || list->buf[0] == 0 || list->t == 's') && list->extra) ? '0' : ' ', width), list->buf);
	if (width > 0 && list->left)
		list->buf = ft_joinfree(list->buf, ft_memaset(' ', width));      
}

void ft_padding_convert(t_printinfo *list)
{
	int width;
	char *temp;
	
	width = list->width - ft_strlen(list->buf) - ((ft_strchr("xX", list->t) && list->alt) ? 2 : 0);	
	if (list->extra && list->prec == -2 && list->t != 'p' && width > 0 && !list->left)
	{
		if (ft_strchr("oO", list->t) && list->alt)
			width--;
		list->buf = ft_joinfree(ft_memaset('0', width), list->buf);
		width = list->width - ft_strlen(list->buf);			
	}
	/* else if (list->alt && list->extra && width > 2 && ft_strchr("xX", list->t))
		list->buf[1] = list->t; */
	if (list->alt && ft_strchr("xX", list->t) && list->buf[0] != 0)
	{
		list->buf = ft_joinfree(ft_strdup((list->t == 'x') ? "0x" : "0X"), list->buf);
		if (!ft_strcmp("0x0", list->buf) || !ft_strcmp("0X0", list->buf))
		{
			temp = ft_strdup("0");
			free(list->buf);
			list->buf = temp;
		}
	}
	else if (list->alt && ft_strchr("oO", list->t)/*  && !list->extra */)
	{
		if ((!list->extra && ((list->prec >= -2 && list->buf[0] != '0') || (list->prec > (int)ft_strlen(list->buf) && list->buf[0] == '0'))) || list->extra)
			list->buf = ft_joinfree(ft_strdup("0"), list->buf);
	}
	width = list->width - ft_strlen(list->buf);		
	if (width > 0 && !list->left && ((!list->extra && list->prec == -2) || (list->extra) || (list->width > list->prec)))
		list->buf = ft_joinfree(ft_memaset(' ', width), list->buf);
	if (width > 0 && list->left && ((!list->extra && list->prec == -2) || (list->extra) || (list->width > list->prec)))
		list->buf = ft_joinfree(list->buf, ft_memaset(' ', width));

}

void ft_padding_digit(t_printinfo *list)
{
	int sign;
	int width;
	int tmp;
	char *temp;

	sign = (list->buf[0] == '-') ? -1 : 1;
	if (list->buf[0] == '-')
	{
		temp = ft_strdup(&list->buf[1]);
		free(list->buf);
		list->buf = temp;
	}
	if (list->extra && (list->prec == -2 || list->t == 'f') && !list->left)
	{
		tmp = list->width - ft_strlen(list->buf) - (((sign == -1) || (sign == 1 && list->showsign)) ? 1 : 0);
		if (list->space && list->buf[0] == '0' && list->t != 'f' && sign == 1)
			tmp--;
		if (list->t == 'f' && list->space && sign == 1)
			tmp--;
		if (tmp > 0)
			list->buf = ft_joinfree(ft_memaset('0', tmp), list->buf);        
	}
	if (list->space && !list->showsign && sign == 1 && !list->is_unsigned)
		list->buf = ft_joinfree(ft_strdup(" "), list->buf);
	if (sign == -1 && !list->is_unsigned)
		list->buf = ft_joinfree(ft_strdup("-"), list->buf);
	if (list->showsign && sign == 1 && ! list->is_unsigned)
		list->buf = ft_joinfree(ft_strdup("+"), list->buf);
	width = list->width - ft_strlen(list->buf);
	if (width > 0 && !list->left && ((!list->extra && list->prec == -2) || (list->extra) || (list->width > list->prec)))
		list->buf = ft_joinfree(ft_memaset(' ', width), list->buf);
	if (width > 0 && list->left)
		list->buf = ft_joinfree(list->buf, ft_memaset(' ', width));
}

void ft_padding(t_printinfo *list)
{
	while (list->next)
	{
		ft_pad_prec(list);
		if (list->t == 's' || list->t == 'c')
			ft_padding_str(list);
		else if (ft_strchr("diuf", list->t))
			ft_padding_digit(list);
		else if (ft_strchr("xXpo", list->t))
			ft_padding_convert(list);
		if (list->t == 'f' && list->prec == 0 && list->showsign && !list->alt && !list->extra)
			list->buf[ft_strlen(list->buf) - 1] = 0;
		list = list->next;
	}
}