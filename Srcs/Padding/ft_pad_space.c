/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:42:57 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/20 05:52:16 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_space(t_printinfo *list)
{
	int	width;
	int	blen;

	width = list->width;
	blen = ft_strlen(list->buf);
	// printf("{%s}{%d}\n", list->buf, list->width);
	if (list->left || (ft_strchr(list->buf, '-') && width == -2))
		return ;
 	if (ft_strchr("xXo", list->t) && !list->extra && width > blen && (list->buflen = width))
		list->buf = ft_joinfree(ft_memaset(' ', width - blen), list->buf);
	if (ft_strchr("aAdeEfFgGiucsp", list->t) && ((width > blen)) && !list->extra)
	{
		// printf("\n> %s\n", list->buf);
		list->buf = ft_joinfree(ft_memaset(' ', width - blen), list->buf);
		// printf("\n> %s\n", list->buf);
		// printf("\n>> %zu\n", ft_strlen(list->buf));
		list->buflen = width;
	}
	if (ft_strchr("aAdeEfFgGid", list->t) && list->width == -2 && list->space && !list->showsign && !list->extra)
	{
		list->buf = ft_joinfree(ft_strdup(" "), list->buf);
		list->buflen += 1;
	}
	if (ft_strchr("di", list->t) && list->extra && list->prec != -2 && !list->showsign)
	{
		list->buf = ft_joinfree(ft_memaset(' ', width - blen), list->buf);
		list->buflen = width;
	}
}
