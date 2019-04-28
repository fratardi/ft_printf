/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:21:48 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/28 17:16:59 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Align Digits
*/

size_t align_digit(size_t align, t_printinfo *list)
{
	size_t ret;
	
	ret = 0;
	while (align)
	{
		ft_putchar((list->extra) ? '0' : ' ');
		align--;
		ret++;
	}
	return (ret);
}

/*
**Print an LLD and return the length
*/

size_t ft_printlli(long long int n, t_printinfo *l)
{
	char *to_print;
	size_t ret;

	if (!(to_print = ft_llitoa(n)))
		return (0);
	ret = 0;
	if (l->space == 1 && l->width == 0)
		ft_putchar(' ');
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && !l->left)
	{
		l->width -= ft_strlen(to_print);
		ret += align_digit(l->width, l);
	}
	if (l->showsign && to_print[0] != '-')
	{
		ret++;
		ft_putchar('+');
	}
	ft_putnstr(to_print, (l->prec == -2) ? ft_strlen(to_print) : l->prec);
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && l->left)
	{
		l->width -= ft_strlen(to_print) + ((ret == 0) ? 0 : 1);
		ret += align_digit(l->width, l);
	}
	ret += ft_strlen(to_print);
	free(to_print);
	return (ret);
}

/*
**Print an ULLD and return the length
*/

size_t ft_printulli(unsigned long long int n, t_printinfo *l)
{
	char *to_print;
	size_t ret;

	if (!(to_print = ft_ullitoa(n)))
		return (0);
	ret = 0;
	if (l->space == 1 && l->width == 0)
		ft_putchar(' ');
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && !l->left)
	{
		l->width -= ft_strlen(to_print);
		ret += align_digit(l->width, l);
	}
	if (l->showsign && to_print[0] != '-')
	{
		ret++;
		ft_putchar('+');
	}
	ft_putnstr(to_print, (l->prec == -2) ? ft_strlen(to_print) : l->prec);
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && l->left)
	{
		l->width -= ft_strlen(to_print) + ((ret == 0) ? 0 : 1);
		ret += align_digit(l->width, l);
	}
	ret += ft_strlen(to_print);
	free(to_print);
	return (ret);
}
