/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:12:49 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/08 04:27:28 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

int         ft_padding_display(t_printinfo *l)
{
	int zero;

	zero = (l->buf[0] == '0' && !l->buf[1]) ? 1 : 0;
	if(ft_strchr("diouUf", l->t))
		return(ft_pad_di(l));
	if(ft_strchr("xXoO", l->t))
		return(ft_pad_xo(l, zero));
	if(l->t == 'c' || l->t == 's')
		return(ft_pad_char_type(l));
	// if(l->t == 'f' )
		// return(ft_pad_float(l));
	return(0);        
}