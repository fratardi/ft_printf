/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:10:32 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/05 01:47:12 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

char		*ft_fillbuf_float(t_printinfo *l, t_rep *rep)
{
	long double flts;
	char	*buf;
	char	*exception;
	int		i;

	i = (!l->alt) ? 1 : 0;
	flts = (l->is_long_double) ?
	(va_arg(rep->current, long double)) : (va_arg(rep->current, double));
	exception = ft_exception(flts, l);
	if (exception == NULL)
	{
		if (l->t == 'f' && !l->is_long_double)
			buf = ft_ldouble(flts, (l->prec < 0) ? 6 :
				l->prec, l->is_float_ten, i);
		else if (l->t == 'f' && l->is_long_double)
			buf = ft_ldouble(flts,
			(l->prec < 0) ? 6 : l->prec, l->is_float_ten, i);
	}
	else
		buf = exception;
	return (buf);
}

long long int			ft_filldi(t_printinfo *list, t_rep *rep)
{
	long long int ret;

	ret = 0;
	if (list->is_long_double || list->max)
		ret = va_arg(rep->current, long long int);
	else if (list->is_long)
		ret = va_arg(rep->current, long int);
	else
		ret = va_arg(rep->current, int);
	return (ret);
}

unsigned long long int	ft_fillunsigned(t_printinfo *list, t_rep *rep)
{
	unsigned long long int ret;

	ret = 0;
	if (list->is_long_double || list->max)
		ret = va_arg(rep->current, unsigned long long int);
	else if (list->is_long || ft_strchr("OU", list->t))
		ret = va_arg(rep->current, unsigned long int);
	else
		ret = va_arg(rep->current, unsigned int);
	if (ft_strchr("OU", list->t))
	{
		list->is_long = 1;
		list->t = (list->t == 'U') ? 'u' : list->t;
		list->t = (list->t == 'O') ? 'o' : list->t;
		list->is_char = 0;
		list->is_short = 0;
	}
	return (ret);
}

char		*ft_fillbuf_convert(t_printinfo *l, t_rep *rep)
{
	char	*buf;
	unsigned long long int temp;

	buf = NULL;
	if (l->t == 'p')
		return (ft_convert_p(va_arg(rep->current, void *)));
	temp = ft_fillunsigned(l, rep);
	if (l->t == 'o' && l->is_char)
		buf = ft_convert_o((unsigned char)temp);
	else if (l->t == 'o' && l->is_short)
		buf = ft_convert_o((unsigned short)temp);
	else if (l->t == 'o')
		buf = ft_convert_o(temp);
	else if (l->t == 'x' && l->is_char)
		buf = ft_convert_x((unsigned char)temp);
	else if (l->t == 'x' && l->is_short)
		buf = ft_convert_x((unsigned short)temp);
	else if (l->t == 'x')
		buf = ft_convert_x(temp);
	else if (l->t == 'X' && l->is_char)
		buf = ft_convert_up_x((unsigned char)temp);
	else if (l->t == 'X' && l->is_short)
		buf = ft_convert_up_x((unsigned short)temp);
	else if (l->t == 'X')
		buf = ft_convert_up_x(temp);
	return (buf);
}

char			*ft_fillbuf_digits(t_printinfo *l, t_rep *rep)
{
	char *buf;
	long long int temp;
	unsigned long long int ullitemp;

	buf = NULL;
	if (!l->is_unsigned)
		temp = ft_filldi(l, rep);
	else
		ullitemp = ft_fillunsigned(l, rep);
	if (l->is_char && !l->is_unsigned)
		buf = ft_llitoa((signed char)temp);
	else if (l->is_short && !l->is_unsigned)
		buf = ft_llitoa((signed short)temp);
	else if (!l->is_unsigned)
		buf = ft_llitoa(temp);
	else if (l->is_char && l->is_unsigned)
		buf = ft_ullitoa((unsigned char)ullitemp);
	else if (l->is_short && l->is_unsigned)
		buf = ft_ullitoa((unsigned short)ullitemp);
	else if (l->is_unsigned && l->t == 'u')
		buf = ft_ullitoa(ullitemp);
	return (buf);
}

char		*ft_fillbuf_bin(t_printinfo *l, t_rep *rep)
{
	char *buf;
	long long int temp;
	void *value;

	buf = NULL;
	if (l->t == 'b')
	{
		temp = ft_filldi(l, rep);
		if (l->is_long)
			buf = ft_binary(&temp, sizeof(long int));
		else if (l->is_long_double)
			buf = ft_binary(&temp, sizeof(long long int));
		else
			buf = ft_binary(&temp, sizeof(int));
	}
	else if (l->t == 'B')
	{
		value = va_arg(rep->current, void *);
		buf = ft_binary_string(value,
		sizeof(char) * ft_strlen(value));
	}
	return (buf);
}

char		*ft_fillbuf(t_printinfo *l, t_rep *rep)
{
	char *ret;

	if (l->t == 'd' || l->t == 'i' || l->t == 'u')
		ret = ft_fillbuf_digits(l, rep);
	else if (ft_strchr("oxXp", l->t))
		ret = ft_fillbuf_convert(l, rep);
	else if (ft_strchr("bB", l->t))
		ret = ft_fillbuf_bin(l, rep);
	else if (l->t == 'f')
		ret = ft_fillbuf_float(l, rep);
	else if (l->t == 's')
		ret = va_arg(rep->current, char *);
	return (ret);
}