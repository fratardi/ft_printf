/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 02:56:44 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/08 03:25:26 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

int      ft_pad_char_type(t_printinfo *l)
{
	int width;
	int ret;
	
	ret = 0;
	width = l->width - ft_strlen(l->buf) - ((l->special == 0) ? 1 : 0);
	if (width > 0 && !l->left)
	{
		ret += ft_print_preset_buf(((l->t == 'c' || l->buf[0] == 0 ||
		l->t == 's') && l->extra) ? '0' : ' ', width);
		ret += ft_print_uni_str(l->buf);
	}
	if (width > 0 && l->left)
	{
		ret += ft_print_uni_str(l->buf);
		ret += ft_print_preset_buf(((l->t == 'c' || l->buf[0] == 0 ||
		l->t == 's') && l->extra) ? '0' : ' ', width);
	}
	else
		ret += ft_print_uni_str(l->buf);
	return (ret);
}