/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexdisp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:23:40 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/13 10:50:27 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	align_printf(int i)
{
	int ret;

	ret = i;
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
	return (ret);
}

size_t	str_printf(char *str, int align)
{
	int lenstr;

	lenstr = ft_strlen(str);
	if (align > 0)
	{
		align_printf(align - lenstr);
		ft_putstr(str);
		return (lenstr + (align - lenstr));
	}
	else if (align < 0)
	{
		align = -align;
		ft_putstr(str);
		align_printf(align - lenstr);
		return (lenstr + (align - lenstr));
	}
	else if (align == 0)
	{
		ft_putstr(str);
		return (lenstr);
	}
	return (0);
}

size_t	digit_printf(int i, int align)
{
	int len;
	char *iti;

	iti = ft_itoa(i);
	len = ft_strlen(iti);
	free(iti);
	if (align > 0)
	{
		align_printf(align - len);
		ft_putnbr(i);
		return (len + (align - len));
	}
	else if (align < 0)
	{
		align = -align;
		ft_putnbr(i);
		align_printf(align - len);
		return (len + (align - len));
	}
	else if (align == 0)
	{
		ft_putnbr(i);
		return (len);
	}
	return (0);
}

size_t	char_printf(int c, int align)
{
	if (align > 0)
	{
		align_printf(align - 1);
		ft_putchar(c);
		return (align);
	}
	else if (align < 0)
	{
		align = -align;
		ft_putchar(c);
		align_printf(align - 1);
		return (align);
	}
	ft_putchar(c);
	return (1);
}

int		lli_printf(int i, va_list va, int align)
{
	char *display;

	display = ft_llitoa(va_arg(va, long long int));
	str_printf(display, align);
	free(display);
	i += 3;
	return (i);
}