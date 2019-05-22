/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:37:18 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/20 09:12:59 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad(t_printinfo *info)
{
	t_printinfo 	*tmp_info;

	tmp_info = info;
	while(tmp_info->next)
	{
		ft_pad_prec(tmp_info);
		ft_pad_alt(tmp_info);//option ''	
		ft_pad_showsig(tmp_info); // option '+'
		// printf("\n{%s}\n", tmp_info->buf);
		ft_pad_space(tmp_info); // option 'espace'
		ft_pad_left(tmp_info);	//option '-'
		//ft_pad_group(tmp_info); // 'apostrophe'
		ft_pad_extra(tmp_info); //option 0
		tmp_info = tmp_info->next;			
	}
}
