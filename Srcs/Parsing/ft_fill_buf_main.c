/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buf_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 07:26:18 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/25 00:23:43 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Main for filling list->buf
*/

void		ft_iterate_buffer(t_printinfo *l, t_elem *elem)
{
	char c;

	c = 0;
	if (l->t == 'b' || l->t == 'B')
		l = ft_fillbuf_bin(l, elem);
	if (l->t == 's' || l->t == 'S')
		l->buf = ft_strdup((elem->value != NULL)
		? (char *)elem->value : "(null)");
	else if (l->t == 'c')
	{
		c = (char)elem->lli;
		if (c == 0)
			l->special = 0;
		l->buf = ft_strndup(&c, 1);
	}
	else if (ft_strchr("diu", l->t))
		ft_fillbuf_digits(l, elem);
	else if (ft_strchr("oxXp", l->t))
		ft_fillbuf_convert(l, elem);
	else if (l->t == 'f')
		ft_fillbuf_float(l, elem);
	else if (l->t == 'F')
		l->buf = ft_of(elem->value);
}

void		ft_fillbuf(t_printinfo *l, t_elem *elem)
{
	t_elem	*start;

	start = elem;
	while (l->next)
	{
		while (elem->next && elem->pos != l->ndol)
			elem = elem->next;
		ft_iterate_buffer(l, elem);
		l->buflen = ft_uni_str_len(l->buf);
		l = l->next;
		elem = start;
	}
}
