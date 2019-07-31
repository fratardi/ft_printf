#include "includes/ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_rep
{
	int ret;
	int seglen;
	int syntaxlen;
	int pos;
	va_list start;
	va_list current;
}				t_rep;

void	ft_init_rep(t_rep rep)
{
	rep.ret = 0;
	rep.seglen = 0;
	rep.syntaxlen = 0;
	rep.pos = 0;
	rep.start = NULL;
	rep.current = rep.start;
}


//cut segment
char	*ft_segment(const char *format, int segmen_pos)
{
	// SEGLEN
}


//tanslate segment given by ft_segment to printinfo data type
t_printinfo  *seg_to_print_info(char *seg, t_rep rep)
{
	
}

//print the data according to it's printinfo
t_rep 	ft_print_seg(const char *format, t_rep rep)
{
		char *seg;
		t_printinfo info;

		seg = &format[rep.pos];
		rep.seglen = ft_segment(format, rep.pos);
		if (ft_issyntax(&format[rep.pos]))
		{
			info = seg_to_print_info(seg, rep);
			ft_display(info, rep);
		}
		printrest(seg, rep.seglen - rep.syntaxlen)
		free(seg);

}

char	*ft_rest

int     ft_printf(const char *format , ...)
{
	t_rep rep;
	int ret;

	ret = 0;
	rep = NULL;
	ft_init_rep(rep);
	while(format[rep.pos])
	{
		if (issyntax(&format[ret.pos]))
			rep = ft_printseg(format, rep);
		else
		{
				// Buff rest
		}
		
	}
	ret = rep.ret;
	ft_free_rep(rep);
	return(ret);
}