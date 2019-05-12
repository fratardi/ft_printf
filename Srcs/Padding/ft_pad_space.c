/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:42:57 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/12 02:15:54 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_space(t_printinfo *list)
{
	int	width;
	int	blen;

	width = list->width;
	blen = list->buflen;
	// printf("blen = %d\n", blen);
	if (list->left || (ft_strchr(list->buf, '-') && width == -2))
		return ;
 	if (ft_strchr("xXo", list->t) && !list->extra && (list->buflen = width) && width > blen)
		list->buf = ft_strjoinfree(ft_memaset(' ', width - blen), list->buf);
	if (ft_strchr("aAdeEfFgGi", list->t) && ((width > blen)) && !list->extra)
	{
		list->buf = ft_strjoinfree(ft_memaset(' ', width - blen), list->buf);
		list->buflen = width;
	}
	if (ft_strchr("aAdeEfFgGi", list->t) && list->width == -2 && list->space && !list->showsign && !list->extra)
	{
		list->buf = ft_strjoinfree(ft_strdup(" "), list->buf);
		list->buflen += 1;
	}
}
