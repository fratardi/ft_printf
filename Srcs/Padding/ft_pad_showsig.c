/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_showsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:44:09 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/15 19:33:04 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_showsig(t_printinfo *list)
{
	if (!ft_strchr("dif", list->t) || !list->showsign || list->buf[0] == '-')
		return ;
	list->buf = ft_joinfree(ft_strdup("+"), list->buf);
	list->buflen++;
}