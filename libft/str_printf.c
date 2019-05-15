/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:43:23 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/12 14:28:37 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_align(const char *format, va_list va, int *i, int align)
{
	if (format[*i + 1] == '-' && format[*i + 2] == '*')
	{
		align = va_arg(va, int);
		align = -align;
		*i += 2;
	}
	if (format[*i + 1] == '*')
	{
		align = va_arg(va, int);
		*i += 1;
	}
	return(align);
}

void	ft_display(const char *format, ...)
{
	int		i;
	int		align;
	va_list	va;

	i = 0;
	va_start(va, format);
	while (format[i])
	{
		align = 0;
		if (format[i] == '%')
		{
			align = ft_align(format, va, &i, align);
			if (format[i + 1] == 'l' && format[i + 2] == 'l' && format[i + 3] == 'd')
				i = lli_printf(i, va, align);
			if (format[i + 1] == 's')
				str_printf(va_arg(va, char *), align);
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				digit_printf(va_arg(va, int), align);
			if (format[i + 1] == 'c')
				char_printf(va_arg(va, int), align);
			i += 2;
		}
		else
			ft_putchar(format[i++]);
	}
}