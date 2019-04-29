/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:25:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/29 18:38:11 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Convert to Octal
*/

char	*ft_convert_o(unsigned long long int to_convert)
{
	static char	tab[17] = "012345678";
	char	*ret;
	size_t	size;

	if (to_convert == 0)
		return (ft_strdup("0"));
	size = ft_size_octal(to_convert);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
	{
		ret[size] = (tab[to_convert % 8]);
		to_convert = to_convert / 8;
	}
	return (ret);
}

/*
**Convert to Hexa Lowercase
*/

char	*ft_convert_x(unsigned long long int to_convert)
{
	static char	tab[17] = "0123456789abcdef";
	char	*ret;
	size_t	size;

	if (to_convert == 0)
		return (ft_strdup("0"));
	size = ft_size_hexa(to_convert);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
	{
		ret[size] = (tab[to_convert % 16]);
		to_convert = to_convert / 16;
	}
	return (ret);
}

/*
**Convert to Hexa Uppercase
*/

char *ft_convert_X(unsigned long long int to_convert)
{
	static char	tab[17] = "0123456789ABCDEF";
	char	*ret;
	size_t	size;

	if (to_convert == 0)
		return (ft_strdup("0"));
	size = ft_size_hexa(to_convert);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
	{
		ret[size] = (tab[to_convert % 16]);
		to_convert = to_convert / 16;
	}
	return (ret);
}


/*
**Print pointer address
*/

char *ft_convert_p(void *to_convert)
{
	static char tab[17] = "0123456789abcdef";
	char *ret;
	unsigned long long int converted;
	size_t size;

	converted = (unsigned long long int)to_convert;
	if (to_convert == 0)
		return (ft_strdup("0"));
	size = ft_size_hexa((unsigned long long int)to_convert);
	if(!(ret = (char *)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
	{
		ret[size] = (tab[converted % 16]);
		converted = converted / 16;
	}
	return (ret);
}
