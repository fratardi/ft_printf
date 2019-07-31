/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:41:34 by tpacaud           #+#    #+#             */
/*   Updated: 2019/07/30 12:59:27 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

void	ft_readfill(t_printinfo *list, va_list va)
{
	int temp;

	temp = 0;
	if (list->t == 'd' || list->t == 'c')
		temp = va_arg(va, int);
	ft_putnbr((int)temp);
}

t_printinfo		*ft_fillsyntax(const char *str, t_printinfo *list)
{
	ft_fillzerolist(list);
	list = ft_fillndol(str, list);
	list = ft_fillprec(str, list);
	list = ft_fillflag(str, list);
	list = ft_fillwidth(str, list);
	list = ft_fillmod(str, list);
	list = ft_filltype(str, list);
	return (list);
}

size_t	ft_readformat(const char *format, va_list va)
{
	char		*buf;
	char		*temp;
	size_t		i;
	t_elem		*elem;
	t_printinfo	*l;

	if (!(l = (t_printinfo *)malloc(sizeof(t_printinfo))))
		return (0);
	l->next = NULL;
	buf = ft_memaset(0, 4097);
	while (*format)
	{
		if (*format == '%')
		{
			l = ft_fillsyntax(format, l);
			element = ft_readfill(l, va);
			temp = ft_fillbuf(element);
			temp = ft_padding(element);
			ft_putstr(buf);
			ft_memset(buf, 0, 4096);
			i = 0;		
			ft_putstr(temp);
			free(temp);
		}
		else
			buf[i] = *format;
		if (i == 4096 || *format == '\n' || !(*format + 1))
		{
			ft_putstr(buf);
			ft_memset(buf, 0, 4096);
			i = 0;
		}
		*format++;
	}
	free(buf);
	return (i);
}