/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:25:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/03/30 17:37:39 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

/* Print Alignment */

void ft_printalign(t_printinfo *list, size_t lenless, char *print)
{
	list->width -= lenless;
	if (list->left == 1)
		ft_putstr(print);
	while (list->width > 0)
	{
		ft_putchar(' ');
		list->width--;
	}
	if (list->left == 0)
		ft_putstr(print);
}

/* Size */

size_t ft_size_octal(unsigned long long int to_convert)
{
	size_t ret;

	ret = 0;
	while (to_convert)
	{
		to_convert = to_convert / 8;
		ret++;
	}
	return (ret);
}

size_t ft_size_hexa(unsigned long long int to_convert)
{
	size_t ret;

	ret = 0;
	while (to_convert)
	{
		to_convert = to_convert / 16;
		ret++;
	}
	return ((ret != 0) ? ret-- : 0);
}

/* Convert to Octal */

void ft_convert_o(unsigned long long int to_convert, t_printinfo *list)
{
	char tab[17] = "012345678";
	char ret[ft_size_octal(to_convert)];
	size_t size;

	if (to_convert == 0)
		return;
	if (list->alt == 1)
		ft_putchar('0');
	size = ft_size_octal(to_convert);
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[to_convert % 8]);
		to_convert = to_convert / 8;
	}
	ft_printalign(list, ft_strlen(ret), ret);
}

/* Convert to Hexa Lowercase */

void ft_convert_x(unsigned long long int to_convert, t_printinfo *list)
{
	char tab[17] = "0123456789abcdef";
	char ret[ft_size_hexa(to_convert)];
	size_t size;

	if (to_convert == 0)
		return;
	if (list->alt == 1)
		ft_putstr("0x");
	size = ft_size_hexa(to_convert);
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[to_convert % 16]);
		to_convert = to_convert / 16;
	}
	ft_printalign(list, ft_strlen(ret), ret);
}

/* Convert to Hexa Uppercase */

void ft_convert_X(unsigned long long int to_convert, t_printinfo *list)
{
	char tab[17] = "0123456789ABCDEF";
	char ret[ft_size_hexa(to_convert)];
	size_t size;

	if (to_convert == 0)
		return;
	if (list->alt == 1)
		ft_putstr("0X");
	size = ft_size_hexa(to_convert);
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[to_convert % 16]);
		to_convert = to_convert / 16;
	}
	ft_printalign(list, ft_strlen(ret), ret);
}

/* Print pointer address */

void ft_convert_p(void *to_convert, t_printinfo *list)
{
	char tab[17] = "0123456789abcdef";
	char ret[ft_size_hexa((unsigned long long int)to_convert)];
	unsigned long long int converted = (unsigned long long int)to_convert;
	size_t size;

	if (to_convert == 0)
		return;
	ft_putstr("0x");
	size = ft_size_hexa((unsigned long long int)to_convert);
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[converted % 16]);
		converted = converted / 16;
	}
	ft_printalign(list, ft_strlen(ret), ret);
}