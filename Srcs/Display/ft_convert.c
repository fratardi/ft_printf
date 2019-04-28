/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:25:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/28 15:54:47 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Print Alignment
*/

size_t	ft_printalign(t_printinfo *list, size_t lenless, char *print)
{
	size_t ret;

	list->width -= lenless;
	if (list->left == 1)
		ft_putstr(print);
	ret = (list->left == 1) ? ft_strlen(print) : 0;
	while (list->width > 0)
	{
		ft_putchar((list->extra) ? '0' : ' ');
		list->width--;
		ret++;
	}
	if (list->left == 0)
		ft_putstr(print);
	ret += (list->left == 0) ? ft_strlen(print) : 0;
	return (ret);
}

/*
**Convert to Octal
*/

size_t	ft_convert_o(unsigned long long int to_convert, t_printinfo *list)
{
	char	*tab;
	char	ret[ft_size_octal(to_convert) + ((list->alt == 1) ? 2 : 0)];
	size_t	size;

	tab = ft_strdup("012345678");
	if (to_convert == 0)
		return (0);
	if (list->alt == 1)
		ft_putchar('0');
	size = ft_size_octal(to_convert) + ((list->alt == 1) ? 2 : 0);
	ret[0] = (list->alt == 1) ? '0' : 0;
	ret[1] = (list->alt == 1) ? 'X' : 0;
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[to_convert % 8]);
		to_convert = to_convert / 8;
		if (list->alt == 1 && size == 2)
			break ;
	}
	free(tab);
	return (ft_printalign(list, ft_strlen(ret), ret));
}

/*
**Convert to Hexa Lowercase
*/

size_t	ft_convert_x(unsigned long long int to_convert, t_printinfo *list)
{
	char	*tab;
	char	ret[ft_size_hexa(to_convert) + ((list->alt == 1) ? 2 : 0)];
	size_t	size;

	tab = ft_strdup("0123456789abcdef");
	if (to_convert == 0)
		return (0);
	size = ft_size_hexa(to_convert) + ((list->alt == 1) ? 2 : 0);
	ret[0] = (list->alt == 1) ? '0' : 0;
	ret[1] = (list->alt == 1) ? 'x' : 0;
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[to_convert % 16]);
		to_convert = to_convert / 16;
		if (list->alt == 1 && size == 2)
			break ;
	}
	free(tab);
	return (ft_printalign(list, ft_strlen(ret), ret));
}

/*
**Convert to Hexa Uppercase
*/

size_t	ft_convert_X(unsigned long long int to_convert, t_printinfo *list)
{
	char	*tab;
	char	ret[ft_size_hexa(to_convert) + ((list->alt == 1) ? 2 : 0)];
	size_t	size;

	tab = ft_strdup("0123456789ABCDEF");
	if (to_convert == 0)
		return (0);
	size = ft_size_hexa(to_convert) + ((list->alt == 1) ? 2 : 0);
	ret[0] = (list->alt == 1) ? '0' : 0;
	ret[1] = (list->alt == 1) ? 'X' : 0;
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[to_convert % 16]);
		to_convert = to_convert / 16;
		if (list->alt == 1 && size == 2)
			break ;
	}
	free(tab);
	return (ft_printalign(list, ft_strlen(ret), ret));
}

/*
**Print pointer address
*/

size_t	ft_convert_p(void *to_convert, t_printinfo *list)
{
	char *tab;
	char ret[ft_size_hexa((unsigned long long int)to_convert) + 2];
	unsigned long long int converted;
	size_t size;

	converted = (unsigned long long int)to_convert;
	if (to_convert == 0)
		return (0);
	tab = ft_strdup("0123456789abcdef");
	size = ft_size_hexa((unsigned long long int)to_convert) + 2;
	ret[0] = '0';
	ret[1] = 'x';
	ret[size] = 0;
	while (size--)
	{
		ret[size] = (tab[converted % 16]);
		converted = converted / 16;
		if (size == 2)
			break ;
	}
	free(tab);
	return (ft_printalign(list, ft_strlen(ret), ret));
}
