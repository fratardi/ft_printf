/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:49:38 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/12 06:40:05 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

t_rep		ft_init_rep(void)
{
	t_rep rep;

	rep.ret = 0;
	rep.seglen = 0;
	rep.syntaxlen = 0;
	rep.strpos = 0;
	rep.vapos = 1;
	return (rep);
}

int			ft_print_rest(char *seg, int size)
{
	if (size > 0)
		ft_putnstr(seg, size);
	return (size);
}

/*
**cut segment
*/

int			ft_syntaxlen(const char *format)
{
	int i;

	i = 1;
	while (format[i] && ft_strchr("diouxXcfspUObB", format[i]) == NULL)
		i++;
	if (ft_strchr("diouxXcfspUObB", format[i]) != NULL)
		i++;
	return (i);
}

int			ft_sequencelen(const char *format)
{
	int i;

	i = 0;
	if (format[0])
		i++;
	while (format[i] && ft_strchr("%", format[i]) == NULL)
		i++;
	return (i);
}

/*
**tanslate segment given by ft_segment to printinfo data type
*/

t_printinfo	seg_to_print_info(char *seg, t_rep *rep)
{
	t_printinfo	list;
	char		*temp;

	temp = ft_strndup(seg, rep->syntaxlen);
	ft_fillzerolist(&list);
	ft_fillndol(temp, &list);
	ft_fillprec(temp, &list);
	ft_fillflag(temp, &list);
	ft_fillwidth(temp, &list);
	ft_fillmod(temp, &list);
	ft_filltype(temp, &list);
	ft_arg_search(rep, &list);
	ft_star_search(rep, &list);
	ft_strdel(&temp);
	return (list);
}

/*
** print the data according to it's printinfo
*/

size_t		ft_print_seg(const char *format, t_rep *rep)
{
	char		*seg;
	char		*syntax;
	t_printinfo	info;
	size_t		ret;

	ret = 0;
	seg = (char *)&format[rep->strpos];
	rep->seglen = ft_sequencelen(seg);
	rep->syntaxlen = 0;
	if (ft_issyntax(seg, rep->seglen))
	{
		rep->syntaxlen = ft_syntaxlen(&format[rep->strpos]);
		info = seg_to_print_info(seg, rep);
		syntax = ft_fillbuf(&info, rep);
		syntax = ft_pad_prec(&info, syntax);
		ret += ft_padding_display(&info, &syntax);
		ret += ft_print_rest(&seg[rep->syntaxlen], rep->seglen - rep->syntaxlen);
	}
	else if (seg[0] == '%')
	{
		ret += ft_sequence(seg, rep->seglen);
		if (seg[rep->seglen] == '%' && seg[rep->seglen] /* && !ft_issyntax(&seg[rep->seglen], ft_sequencelen(&seg[rep->seglen])) */)
			rep->seglen += ft_sequencelen(&seg[rep->seglen]);
	}
	else
		ret += ft_print_rest(&seg[rep->syntaxlen], rep->seglen - rep->syntaxlen);
	rep->strpos += rep->seglen;
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	t_rep	rep;
	int		ret;

	ret = 0;
	if (format == NULL)
		return (0);
	rep = ft_init_rep();
	va_start(rep.start, format);
	va_copy(rep.current, rep.start);
	while (format[rep.strpos])
		ret += ft_print_seg(format, &rep);
	va_end(rep.start);
	return (ret);
}
