/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:21:48 by tpacaud           #+#    #+#             */
/*   Updated: 2019/03/30 19:03:44 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	align_digit(size_t align)
{
	while (align)
	{
		ft_putchar(' ');
		align--;
	}
}

/* Print an LLD and return the length */

size_t ft_printlli(long long int n, t_printinfo *l)
{
	char *to_print;
	size_t ret;

	if (!(to_print = ft_llitoa(n)))
		return (0);
	ret = 0;
	ft_putchar((l->space == 1 && l->width == 0) ? ' ' : 0);
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && !l->left)
	{
		l->width -= ft_strlen(to_print);
		align_digit(l->width);
	}
	if (l->showsign && to_print[0] != '-')
	{
		ret++;
		ft_putchar('+');
	}
	ft_putstr(to_print);
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && l->left)
	{
		l->width -= ft_strlen(to_print) + ((ret == 0) ? 0 : 1);
		align_digit(l->width);
	}
	ret += ft_strlen(to_print);
	free(to_print);
	return (ret);
}

/* Print an ULLD and return the length */

size_t ft_printulli(unsigned long long int n, t_printinfo *l)
{
	char *to_print;
	size_t ret;

	if (!(to_print = ft_ullitoa(n)))
		return (0);
	ret = 0;
	ft_putchar((l->space == 1 && l->width == 0) ? ' ' : 0);
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && !l->left)
	{
		l->width -= ft_strlen(to_print);
		align_digit(l->width);
	}
	if (l->showsign && to_print[0] != '-')
	{
		ret++;
		ft_putchar('+');
	}
	ft_putstr(to_print);
	if (l->width != 0 && (size_t)l->width > ft_strlen(to_print) && l->left)
	{
		l->width -= ft_strlen(to_print) + ((ret == 0) ? 0 : 1);
		align_digit(l->width);
	}
	ret += ft_strlen(to_print);
	free(to_print);
	return (ret);
}