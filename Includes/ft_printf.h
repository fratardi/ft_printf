/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:35:32 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/16 18:55:19 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# include "../libft/libft.h"

/*
**Defines for the static padding buffer
*/

# define BUFF_SIZE  2014

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

enum				e_type {
	PA_INT = 1,
	PA_CHAR = 2,
	PA_WCHAR = 3,
	PA_STRING = 4,
	PA_WSTRING = 5,
	PA_POINTER = 6,
	PA_FLOAT = 7,
	PA_LAST
};

/*
**Syntax Infos
*/

typedef struct		s_printinfo {
	int					prec;
	int					width;
	unsigned int		ndol;
	unsigned int		max;
	unsigned int		is_long_double;
	unsigned int		is_char;
	unsigned int		is_unsigned;
	unsigned int		is_short;
	unsigned int		is_long;
	unsigned int		is_float_ten;
	unsigned int		alt;
	unsigned int		space;
	unsigned int		left;
	unsigned int		showsign;
	unsigned int		group;
	unsigned int		extra;
	unsigned int		bin;
	char				t;
	char				special;
	char				*buf;
	size_t				buflen;
	enum e_type			type;
	struct s_printinfo	*next;
}					t_printinfo;

/*
**Not_sytax
*/

typedef struct		s_no_syntax{
	size_t	ret;
	char	left;
	char	extra;
	int		width;
}					t_no_syntax;

/*
**Content of elypse
*/

typedef struct		s_elem{
	void					*value;
	long long int			lli;
	unsigned long long int	ulli;
	double					dble;
	long double				long_double;
	int						c;
	unsigned int			pos;
	signed char				s_c;
	struct s_elem			*previous;
	struct s_elem			*next;
}					t_elem;

/*
**End Buffer to print
*/

typedef struct		s_return{
	size_t				written;
	char				*to_print;
}					t_return;

/*
**Struct for va_read
*/

typedef struct		s_va{
	size_t		nb_va;
	size_t		nb_pos;
	t_elem		*elem;
	t_elem		*start;
	t_printinfo	*pstart;
}					t_va;

typedef struct		s_double{
	char	*m;
	int		ex;
	char	*ent;
	char	*dec;
	char	*temp;
	char	*tempent;
	int		b;
}					t_double;

typedef struct		s_power5{
	char	*base;
	int		p;
	int		i;
}					t_power5;

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
char				*ft_addstrings(char *s1, char *s2);
void				ft_addstrings_stack(char *assign, char *base, int po_assig,
	int po_base);
char				*ft_new_addstrings(char *s1, char *s2);
char				*ft_pow5(int pow, char end);
void				ft_hexfloat(void *content, size_t n);
char				*ft_fillbig(char *s1, char *s2);
char				*ft_pow2str(int ex, char end);
char				*ft_floatexp(char *str, int prec);
t_double			ft_rounding_float(t_double dble, int prec);
char				*ft_round_dec(char *str, int prec, int *round_ent);
char				*ft_mantissaldouble(long double d);
int					ft_expldouble(long double a);
char				*ft_ldouble(long double a, int prec, unsigned int is_ten,
	int sign);
char				*ft_exception(long double a, t_printinfo *list);

/*
**Unicode
*/

size_t				ft_print_uni_str(char *str);
size_t				ft_print_uni_char(char *str);
size_t				ft_uni_char_len(char *str);
size_t				ft_uni_str_len(char *str);
int					ft_print_n_uni_str(char *str, int size);

/*
**Fonction Principale
*/

int					ft_printf(const char *format, ...);

/*
**Fill Buffer
*/

void				ft_fillbuf_float(t_printinfo *l, t_elem *elem);
void				ft_opts_mod(t_printinfo *list, int *i, int *hmod,
	char *str);
void				ft_fillbuf_digits(t_printinfo *l, t_elem *elem);
void				ft_fillbuf_convert(t_printinfo *l, t_elem *elem);
t_printinfo			*ft_fillbuf_bin(t_printinfo *l, t_elem *elem);

/*
**Converting Functions
*/

size_t				ft_size_octal(unsigned long long int to_convert);
size_t				ft_size_hexa(unsigned long long int to_convert);
char				*ft_convert_o(unsigned long long int to_convert);
char				*ft_convert_x(unsigned long long int to_convert);
char				*ft_convert_up_x(unsigned long long int to_convert);
char				*ft_convert_p(void *to_convert);

/*
**Display Functions
*/

size_t				ft_display(char **tab, t_printinfo *list);
size_t				ft_dispnoh(t_printinfo *list, t_elem *elem);
size_t				ft_disphmodchar(t_printinfo *list, t_elem *elem);
size_t				ft_disphmodshort(t_printinfo *list, t_elem *elem);
int					onlystring(char **tab);
size_t				ft_putonlystring(char **tab);
size_t				ft_sequence(char *s1, char *s2, int *open);
size_t				ft_endseq(char *s1);

/*
**Annex Functions
*/

char				**ft_split_format(const char *format);
char				*ft_rest(char *str);
int					ft_issyntax(char *str);
void				ft_modndol(t_printinfo *list);
void				ft_displaybin(void *content, size_t n);
char				*ft_of(char *name);
char				*ft_binary(void *content, size_t n);
char				*ft_binary_string(void *content, size_t n);

/*
**Fill Stuct Print_Info
*/

void				ft_fillbuf(t_printinfo *list, t_elem *elem);
void				ft_fillzerolist(t_printinfo *list);
t_printinfo			*ft_fillstruct(char **tab);
t_printinfo			*ft_fillflag(char *str, t_printinfo *list);
t_printinfo			*ft_fillmod(char *str, t_printinfo *list);
t_printinfo			*ft_fillprec(char *str, t_printinfo *list);
t_printinfo			*ft_fillndol(char *str, t_printinfo *list);
t_printinfo			*ft_fillwidth(char *str, t_printinfo *list);
t_printinfo			*ft_filltype(char *str, t_printinfo *list);

/*
**Fill Elems from va_arg
*/

void				ft_initelem(t_elem *elem);
t_elem				*ft_varead(t_printinfo *list, va_list va, char **tab);
t_elem				*ft_filldi(t_printinfo *list, va_list va, t_elem *elem);
t_elem				*ft_fillunsigned(t_printinfo *list, va_list va,
	t_elem *elem);
t_elem				*ft_fillfloats(t_printinfo *list, va_list va, t_elem *elem);

/*
**Free
*/

void				ft_free_printf(char **tab, t_elem *elem, t_printinfo *list);
void				ft_free_parsing(char **tab);
void				ft_free_elem(t_elem *elem, t_printinfo *list);
void				ft_free_printinfo(t_printinfo *list);

/*
**Padding
*/

int					ft_pad_char_type(t_printinfo *l);
int					ft_padding_display(t_printinfo *l);
int					ft_pad_xo(t_printinfo *l, int zero);
int					ft_print_preset_buf(unsigned char c, int n);
void				ft_padding(t_printinfo *list);
int					ft_pad_di(t_printinfo *l);
void				ft_padding_convert(t_printinfo *l, int zero);
void				ft_padding_str(t_printinfo *l);
void				ft_pad_prec(t_printinfo *l);
int					ft_pad_float(t_printinfo *l);

#endif
