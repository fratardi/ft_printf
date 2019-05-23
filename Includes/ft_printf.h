/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:35:32 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/23 05:50:31 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# include "ft_float.h"
# include "../libft/libft.h"

/*
**Defines for unicodes hexas masks matching  hardware specifcations
*/

# define UNI1  0x80
# define UNI2  0xC0
# define UNI3  0xE0
# define UNI4  0xF0

/* 
**Type ENUM 
*/

enum 					e_type
{                      /* C type: */
  PA_INT = 1,          /* int */
  PA_CHAR = 2,         /* int, cast to char */
  PA_WCHAR = 3,        /* wide char */
  PA_STRING = 4,       /* const char *, a '\0'-terminated string */
  PA_WSTRING = 5,      /* const wchar_t *, wide character string */
  PA_POINTER = 6,      /* void* */
  PA_FLOAT = 7,        /* float */
  PA_LAST
};

/*
**Syntax Infos
*/

typedef struct			s_printinfo {
	int 				prec;			/* Precision */
	int 				width;			/* Width */
	unsigned int		ndol;			/* Elem n° */
	unsigned int		max;
	unsigned int		is_long_double;	/* Is a Double Long */
	unsigned int		is_char;		/* Is char */
	unsigned int		is_unsigned;	/* Is an unsigned */
	unsigned int		is_short;		/* Is Short */
	unsigned int		is_long;		/* Is Long */
	unsigned int		is_float_ten;	/* Is 'E' for floats E^x */
	unsigned int		alt;			/* Is # */
	unsigned int		space;			/* Is ' ' */
	unsigned int		left;			/* Is - */
	unsigned int		showsign;		/* Is + */
	unsigned int		group;			/* is \' */
	unsigned int		extra;			/* Is '0' */
	unsigned int		bin;
	char				t;				/* Type */
	char				special;
	char				*buf;			/* Buffer */
	size_t				buflen;			/*length of buffer*/
	enum				e_type type;	/* Type */
	struct s_printinfo	*next;
}           			t_printinfo;

/*
**Not_sytax
*/

typedef struct			s_no_syntax{
	char left;
	char extra;
	int  width;
}						t_no_syntax;

/*
**Content of elypse
*/

typedef struct			s_elem{
	void					*value;			/* Value of ptr */
	long long int			lli;
	unsigned long long int	ulli;
	double					dble;
	long double				long_double;
	int						c;
	unsigned int			pos;			/* Position of the list-elem */
	struct s_elem			*previous;
	struct s_elem			*next;
}						t_elem;

/*
**End Buffer to print
*/

typedef struct			s_return{
	size_t				written;
	char				*to_print;
}						t_return;


/*
**Struct for va_read
*/

typedef struct			s_va{
	size_t nb_va;
	size_t nb_pos;
	t_elem *elem;
	t_elem *start;
	t_printinfo *pstart;
}						t_va;

typedef struct			s_double{
	char	*m;
	int		ex;
	char	*ent;
	char	*exep;
	char	*dec;
	char	*temp;
	char	*tempent;
	char	*tempdec;
	int		b;
}						t_double;

typedef struct			s_power5{
	char	*base;
	char	*tmp;
	char	*ret;
	size_t	p;
	int		i;
}						t_power5;

/*
**Funtions to print Digits
*/

size_t				ft_printlli(long long int n, t_printinfo *l);
size_t				ft_printulli(unsigned long long int n, t_printinfo *l);

/*
**Float
*/

void				ft_adjustpospo(char **s1, char **s2);
void				ft_adjustnegpo(char **s1, char **s2);
char				ft_addchar(char *s1, char *s2, char *ret, char carry);
char 				*ft_addstrings(char *s1, char *s2);
char				*ft_pow5(int pow);
void 				ft_hexfloat(void *content, size_t n);
char				*ft_fillbig(char *s1, char *s2);
char 				*ft_pow2str(int ex);
char				*ft_floatEdispneg(char *str, int prec);
char				*ft_rounding(char *str, size_t prec);
char				*ft_mantissaldouble(long double d);
int					ft_expldouble(long double a);
char				*ft_ldouble(long double a, int prec, unsigned int is_ten);
char	*ft_exception(long double a, t_printinfo *list);
// char				*ft_mantissadouble(double d);
// unsigned int		ft_get_sig(float d);
// char 				*ft_decimal(float a);
// char				*ft_floatt(float a);
//char   				*ft_add_5(char *str);
// char 				*ft_mantissabin(float d);
// int					ft_expfloat(float a);
// int					ft_expdouble(double a);
// unsigned int		ft_get_sig_double(double d);
// char 				*ft_double(double a);

/*
**Unicode
*/

size_t				ft_print_uni_str(char *str);
size_t				ft_print_uni_char(char *str);
size_t				ft_uni_char_len(char *str);
size_t				ft_uni_str_len(char *str);
int	ft_print_n_uni_str(char *str, int size);

/*
**Fonction Principale
*/

/*
**	A enlever
*/
size_t 				ft_debug(const char *format, ...);
void				ft_debugf(void);
void				ft_printdebuglist(t_printinfo *list, char **tab);
void				ft_debugelem(t_elem *elem);
void 				tests(void);





size_t  			ft_printf(const char *format, ...);

/*
**Converting Functions
*/

size_t				ft_size_octal(unsigned long long int to_convert);
size_t				ft_size_hexa(unsigned long long int to_convert);
char    			*ft_convert_o(unsigned long long int to_convert);
char				*ft_convert_x(unsigned long long int to_convert);
char				*ft_convert_up_x(unsigned long long int to_convert);
char				*ft_convert_p(void *to_convert);

/*
**Display Functions
*/

size_t	ft_display(char **tab, t_printinfo *list);
size_t				ft_dispnoh(t_printinfo *list, t_elem *elem);
size_t				ft_disphmodchar(t_printinfo *list, t_elem *elem);
size_t				ft_disphmodshort(t_printinfo *list, t_elem *elem);
int		onlystring(char **tab);
size_t	ft_putonlystring(char **tab);

/*
**Annex Functions
*/

char				**ft_split_format(const char *format);
char		        *ft_rest(char *str);
int 				ft_issyntax(char *str);
void				ft_modndol(t_printinfo *list);
char				*ft_joinfree(char *s1, char *s2);
void				ft_displaybin(void *content, size_t n);
char *ft_of(char *name);
char *ft_binary(void *content, size_t n);
char *ft_binary_string(void *content, size_t n);

/*
**Fill Stuct Print_Info
*/

void				ft_fillbuf(t_printinfo *list, t_elem *elem);
void				ft_fillzerolist(t_printinfo *list);
t_printinfo 		*ft_fillstruct(char **tab);
t_printinfo 		*ft_fillflag(char *str, t_printinfo *list);
t_printinfo 		*ft_fillmod(char *str, t_printinfo *list);
t_printinfo			*ft_fillprec(char *str, t_printinfo *list);
t_printinfo			*ft_fillndol(char *str, t_printinfo *list);
t_printinfo			*ft_fillwidth(char *str, t_printinfo *list);
t_printinfo			*ft_filltype(char *str, t_printinfo *list);

/*
**Fill Elems from va_arg
*/

t_elem				*ft_varead(t_printinfo *list, va_list va, char **tab);
t_elem				*ft_filldi(t_printinfo *list, va_list va, t_elem *elem);
t_elem				*ft_fillunsigned(t_printinfo *list, va_list va, t_elem *elem);
t_elem				*ft_fillfloats(t_printinfo *list, va_list va, t_elem *elem);

/*
**Free
*/

void				ft_free_parsing(char **tab);
void				ft_free_elem(t_elem *elem, t_printinfo *list);
void				ft_free_printinfo(t_printinfo *list);

/*
** Padding
*/
void				ft_pad_prec(t_printinfo *list);
void				ft_pad(t_printinfo *info);
void				ft_pad_alt(t_printinfo *list);
void				ft_pad_space(t_printinfo *list);
void				ft_pad_left(t_printinfo *list);
void				ft_pad_showsig(t_printinfo *list);
//void				ft_pad_group(t_printinfo *list);
void				ft_pad_extra(t_printinfo *list);
#endif
