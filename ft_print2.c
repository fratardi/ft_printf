#include "includes/ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

void	ft_init_rep(t_rep rep)
{
	rep.ret = 0;
	rep.seglen = 0;
	rep.syntaxlen = 0;
	rep.pos = 0;
	rep.start = NULL;
	rep.current = rep.start;
}


void		ft_print_rest(char *seg, int size)
{
	ft_putstr(&seg[size]);
}

//cut segment
int			ft_syntaxlen(const char *format)
{
	int i;

	i = 0;
	while (format[i] && ft_strchr("diouxXcfspUObB", format[i]) == NULL)
		i++;
	return (i);
}

int			ft_sequencelen(const char *format)
{
	int i;

	i = 0;
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



		seg = &format[rep.pos];
		rep.seglen = ft_sequence(seg);
		if (ft_issyntax(seg))
		{
			rep.syntaxlen = ft_segment(&format[rep.pos]);
			info = seg_to_print_info(seg, rep);
			ft_display(info, rep);
		}
		printrest(&seg[rep.syntaxlen], rep.seglen - rep.syntaxlen);
		free(seg);
		rep.strpos += rep.seglen;
}

char	*ft_rest

int     ft_printf(const char *format , ...)
{
	t_rep rep;
	int ret;

	ret = 0;
	rep = NULL;
	ft_init_rep(rep);
	while(format[rep.strpos])
			rep = ft_printseg(format, rep);	
	ret = rep.ret;
	ft_free_rep(rep);
	return(ret);
}