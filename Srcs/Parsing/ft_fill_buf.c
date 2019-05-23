/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:10:32 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/23 07:30:14 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void		ft_fillbuf_float(t_printinfo *l, t_elem *elem)
{
	char	*exception;

	exception = ft_exception((l->is_long_double)
	? elem->long_double : elem->dble, l);
	if (exception == NULL)
	{
		if (l->t == 'f' && !l->is_long_double)
			l->buf = ft_ldouble(elem->dble,
			(l->prec < 0) ? 6 : (size_t)l->prec, l->is_float_ten);
		else if (l->t == 'f' && l->is_long_double)
			l->buf = ft_ldouble(elem->long_double,
			(l->prec < 0) ? 6 : (size_t)l->prec, l->is_float_ten);
	}
	else
		l->buf = exception;
}

void		ft_fillbuf_convert(t_printinfo *l, t_elem *elem)
{
	if (l->t == 'o' && l->is_char)
		l->buf = ft_convert_o((char)elem->ulli);
	else if (l->t == 'o' && l->is_short)
		l->buf = ft_convert_o((short)elem->ulli);
	else if (l->t == 'o')
		l->buf = ft_convert_o(elem->ulli);
	else if (l->t == 'x' && l->is_char)
		l->buf = ft_convert_x((char)elem->ulli);
	else if (l->t == 'x' && l->is_short)
		l->buf = ft_convert_x((short)elem->ulli);
	else if (l->t == 'x')
		l->buf = ft_convert_x(elem->ulli);
	else if (l->t == 'X' && l->is_char)
		l->buf = ft_convert_up_x((char)elem->ulli);
	else if (l->t == 'X' && l->is_short)
		l->buf = ft_convert_up_x((short)elem->ulli);
	else if (l->t == 'X')
		l->buf = ft_convert_up_x(elem->ulli);
	else if (l->t == 'p')
		l->buf = ft_convert_p(elem->value);
}

void		ft_fillbuf_digits(t_printinfo *l, t_elem *elem)
{
	if (l->is_char && !l->is_unsigned)
		l->buf = ft_llitoa((char)elem->lli);
	else if (l->is_short && !l->is_unsigned)
		l->buf = ft_llitoa((short)elem->lli);
	else if (!l->is_unsigned)
		l->buf = ft_llitoa(elem->lli);
	else if (l->is_char && l->is_unsigned)
		l->buf = ft_ullitoa((char)elem->lli);
	else if (l->is_short && l->is_unsigned)
		l->buf = ft_ullitoa((short)elem->lli);
	else if (l->is_unsigned && l->t == 'u')
		l->buf = ft_ullitoa(elem->ulli);
}

t_printinfo	*ft_fillbuf_bin(t_printinfo *l, t_elem *elem)
{
	if (l->t == 'b')
	{
		if (l->is_long)
			l->buf = ft_binary(&elem->lli, sizeof(long int));
		else if (l->is_long_double)
			l->buf = ft_binary(&elem->lli, sizeof(long long int));
		else
			l->buf = ft_binary(&elem->lli, sizeof(int));
	}
	else if (l->t == 'B')
		l->buf = ft_binary_string(elem->value,
		sizeof(char) * ft_strlen(elem->value));
	return (l);
}
