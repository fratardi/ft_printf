/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:10:32 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/23 01:44:43 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_fillbuf_float(t_printinfo *list, t_elem *elem)
{
	char *exception;

	exception = ft_exception((list->is_long_double) ? elem->long_double : elem->dble, list);
	if (exception == NULL)
	{
		if (list->t == 'f' && !list->is_long_double)
			list->buf = ft_ldouble(elem->dble, (list->prec < 0) ? 6 : (size_t)list->prec, list->is_float_ten);
		else if (list->t == 'f' && list->is_long_double)
			list->buf = ft_ldouble(elem->long_double, (list->prec < 0) ? 6 : (size_t)list->prec, list->is_float_ten);
	}
	else
	{
		list->buf = exception;
		// free(exception);
	}
}

void	ft_fillbuf_convert(t_printinfo *list, t_elem *elem)
{
	if (list->t == 'o' && list->is_char)
		list->buf = ft_convert_o((char)elem->ulli);
	else if (list->t == 'o' && list->is_short)
		list->buf = ft_convert_o((short)elem->ulli);
	else if (list->t == 'o')
		list->buf = ft_convert_o(elem->ulli);
	else if (list->t == 'x' && list->is_char)
		list->buf = ft_convert_x((char)elem->ulli);
	else if (list->t == 'x' && list->is_short)
		list->buf = ft_convert_x((short)elem->ulli);
	else if (list->t == 'x')
		list->buf = ft_convert_x(elem->ulli);
	else if (list->t == 'X' && list->is_char)
		list->buf = ft_convert_X((char)elem->ulli);
	else if (list->t == 'X' && list->is_short)
		list->buf = ft_convert_X((short)elem->ulli);
	else if (list->t == 'X')
		list->buf = ft_convert_X(elem->ulli);
	else if (list->t == 'p')
		list->buf = ft_convert_p(elem->value);
}

void	ft_fillbuf_digits(t_printinfo *list, t_elem *elem)
{
	if (list->is_char && !list->is_unsigned)
		list->buf = ft_llitoa((char)elem->lli);
	else if (list->is_short && !list->is_unsigned)
		list->buf = ft_llitoa((short)elem->lli);
	else if (!list->is_unsigned)
		list->buf = ft_llitoa(elem->lli);
	else if (list->is_char && list->is_unsigned)
		list->buf = ft_ullitoa((char)elem->lli);
	else if (list->is_short && list->is_unsigned)
		list->buf = ft_ullitoa((short)elem->lli);
	else if (list->is_unsigned && list->t == 'u')
		list->buf = ft_ullitoa(elem->ulli);
}

void	ft_fillbuf(t_printinfo *list, t_elem *elem)
{
	t_elem *start;
	char c;
	
	c = 0;
	start = elem;
	while(list->next)
	{
		while(elem->next && elem->pos != list->ndol)
			elem = elem->next;
		if (list->t == 's' || list->t =='S')
			list->buf = ft_strdup((elem->value != NULL) ? (char *)elem->value : "(null)");
		else if (list->t == 'c')
		{
			c = (char)elem->lli;
			if (c == 0)
				list->special = 0;
			list->buf = ft_strndup(&c, 1);
		}
		else if (ft_strchr("diu", list->t))
			ft_fillbuf_digits(list, elem);
		else if (ft_strchr("oxXp", list->t))
			ft_fillbuf_convert(list, elem);
		else if (list->t == 'f')
			ft_fillbuf_float(list, elem);
		else if (list->t == 'F')
			list->buf = ft_of(elem->value);
		list->buflen = ft_uni_str_len(list->buf);
		list = list->next;
		elem = start;
	}
}
