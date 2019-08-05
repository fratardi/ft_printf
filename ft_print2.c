#include "includes/ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

t_rep	ft_init_rep(t_rep rep)
{
	rep.ret = 0;
	rep.seglen = 0;
	rep.syntaxlen = 0;
	rep.strpos = 0;
	rep.vapos = 0;
	// rep.start = NULL;
	// rep.current = rep.start;
	return (rep);
}


void		ft_print_rest(char *seg, int size)
{
	if (size > 0)
		ft_putnstr(seg, size);
}

//cut segment
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

//tanslate segment given by ft_segment to printinfo data type
t_printinfo  seg_to_print_info(char *seg, t_rep rep)
{
	t_printinfo list;
	char *temp;

	temp = ft_strndup(seg, rep.syntaxlen);
	// printf("syn={%s}\n", temp);
	ft_fillzerolist(&list);
	ft_fillndol(temp, &list);
	//ndol selon precedant ou ndol soit precise
	ft_fillprec(temp, &list);
	ft_fillflag(temp, &list);
	ft_fillwidth(temp, &list);
	ft_fillmod(temp, &list);
	ft_filltype(temp, &list);
	// ft_strdel(temp);
	return (list);
}

//print the data according to it's printinfo
t_rep 	ft_print_seg(const char *format, t_rep rep)
{
	char *seg;
	char *syntax;
	t_printinfo info;

	seg = (char *)&format[rep.strpos];
	rep.seglen = ft_sequencelen(seg);
	rep.syntaxlen = 0;
	if (ft_issyntax(seg, rep.seglen))
	{
		rep.syntaxlen = ft_syntaxlen(&format[rep.strpos]);
		info = seg_to_print_info(seg, rep);
		syntax = ft_fillbuf(&info, &rep);
		syntax = ft_pad_prec(&info, syntax);
		if (ft_strchr("fdi", info.t))
			ft_pad_di(&info, syntax);
		else
			ft_putstr(syntax);
		// free(syntax);
		ft_print_rest(&seg[rep.syntaxlen], rep.seglen - rep.syntaxlen);
		//ft_display(info, rep);
	}
	else if (seg[0] == '%')
	{
		ft_sequence(seg, rep.seglen);
		rep.seglen += ft_sequencelen(&seg[rep.seglen]);
		// ft_printf("{%s}", seg);
		/* ft_putstr("not_good_syntax"); */
	}
	else
		ft_print_rest(&seg[rep.syntaxlen], rep.seglen - rep.syntaxlen);
	// free(seg);
	rep.strpos += rep.seglen;
	return (rep);
}

int     ft_printf(const char *format , ...)
{
	t_rep rep;
	int ret;

	ret = 0;
	rep = ft_init_rep(rep);
	va_start(rep.start, format);
	va_copy(rep.current, rep.start);
	while(format[rep.strpos])
		rep = ft_print_seg(format, rep);
	ret = rep.ret;
	va_end(rep.start);
	//ft_free_rep(rep);
	return(ret);
}