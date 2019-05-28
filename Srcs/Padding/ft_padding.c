/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:14:29 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 21:38:05 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void ft_padding_str(t_printinfo *list)
{
	int width;

	width = list->width - ft_strlen(list->buf);    
	if (width > 0 && !list->left)
		list->buf = ft_joinfree(ft_memaset(' ', width), list->buf);
	if (width > 0 && list->left)
		list->buf = ft_joinfree(list->buf, ft_memaset(' ', width));      
}

void ft_padding_convert(t_printinfo *list)
{
	int width;
	
	width = list->width - ft_strlen(list->buf);
	if (list->extra && list->prec == -2 && list->t != 'p')
		list->buf = ft_joinfree(ft_memaset('0', list->width - ft_strlen(list->buf)), list->buf);
	else if (list->alt && list->extra && ft_strchr("xX", list->t))
		list->buf[1] = list->t;
	else if (list->alt && ft_strchr("oO", list->t) && !list->extra)
		list->buf = ft_joinfree(ft_strdup("0"), list->buf);
	if (width > 0 && !list->left && !list->extra)
		list->buf = ft_joinfree(ft_memaset(' ', width), list->buf);
	if (width > 0 && list->left && !list->extra)
		list->buf = ft_joinfree(list->buf, ft_memaset(' ', width));

}

void ft_padding_digit(t_printinfo *list)
{
	int sign;
	int width;
	char *temp;

	sign = (list->buf[0] == '-') ? -1 : 1;
	if (list->buf[0] == '-')
	{
		temp = ft_strdup(&list->buf[1]);
		free(list->buf);
		list->buf = temp;
	}
	// printf(">>show %d sign %d\n", list->showsign, sign);
	if (list->extra && list->prec == -2)
		if ((!list->showsign && sign == 1) || (list->showsign && sign == -1))
			list->buf = ft_joinfree(ft_memaset('0', list->width - ft_strlen(list->buf) - ((sign == -1 || (sign == 1 && list->showsign)) ? 1 : 0)), list->buf);        
	if (list->space && !list->showsign && !list->extra && sign == 1)
		list->buf = ft_joinfree(ft_strdup(" "), list->buf);
	if (sign == -1)
		list->buf = ft_joinfree(ft_strdup("-"), list->buf);
	if (list->showsign && sign == 1)
		list->buf = ft_joinfree(ft_strdup("+"), list->buf);
	width = list->width - ft_strlen(list->buf);
	// printf(">> %d\n", width);
	if (width > 0 && !list->left && ((!list->extra && list->prec == -2) || (list->extra)))
		list->buf = ft_joinfree(ft_memaset(' ', width), list->buf);
	if (width > 0 && list->left /* && ((!list->extra && list->prec == -2) || (list->extra)) */)
		list->buf = ft_joinfree(list->buf, ft_memaset(' ', width));
}

void ft_padding(t_printinfo *list)
{
	while (list->next)
	{
		ft_pad_prec(list);
		if (list->t == 's' || list->t == 'c')
			ft_padding_str(list);
		else if (ft_strchr("diu", list->t))
			ft_padding_digit(list);
		else if (ft_strchr("xXpo", list->t))
			ft_padding_convert(list);
		list = list->next;
	}
}