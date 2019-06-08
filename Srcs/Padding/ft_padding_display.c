/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:12:49 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/08 03:27:51 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

int         ft_padding_display(t_printinfo *l)
{
	if(ft_strchr("diouUf", l->t))
		return(ft_pad_di(l));
	// if(t_strchr("xXoO", l->t))
		// return(ft_pad_xo(l));
	if(l->t == 'c' || l->t == 's')
		return(ft_pad_char_type(l));
	// if(l->t == 'f' )
		// return(ft_pad_float(l));
	return(0);        
}