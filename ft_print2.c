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
	while (format[i] && ft_strchr("\n%", format[i]) == NULL)
		i++;
	return (i);
}

//tanslate segment given by ft_segment to printinfo data type
t_printinfo  seg_to_print_info(char *seg, t_rep rep)
{
	t_printinfo list;

	ft_fillzerolist(&list);
	ft_fillndol(seg, &list);
	//ndol selon precedant ou ndol soit precise
	ft_fillprec(seg, &list);
	ft_fillflag(seg, &list);
	ft_fillwidth(seg, &list);
	ft_fillmod(seg, &list);
	ft_filltype(seg, &list);
	return (list);
}

//print the data according to it's printinfo
t_rep 	ft_print_seg(const char *format, t_rep rep)
{
	char *seg;
	t_printinfo info;

	seg = (char *)&format[rep.strpos];
	rep.seglen = ft_sequencelen(seg);
	rep.syntaxlen = 0;
	if (ft_issyntax(seg))
	{
		printf("syntax_a_traiter");
		rep.syntaxlen = ft_syntaxlen(&format[rep.strpos]);
		info = seg_to_print_info(seg, rep);
		//ft_display(info, rep);
	}
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