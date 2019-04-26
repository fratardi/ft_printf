/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:36:47 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/26 19:18:53 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parse 1 of format string and split % */

#include "../../Includes/ft_printf.h"

int		ft_countargs(const char *format)
{
	int i;
	int n;

	i = 0;
	n = 1;
	if (!format)
		return (0);
	while (format[i])
	{
		if (i != 0 && format[i] == '%')
			n++;
		i++;
	}
	return (n);
}

int		ft_arglen(const char *format)
{
	int pos;

	pos = 0;
	while (format[pos] && format[pos] != '%')
		pos++;
	return (pos == 0 ? 1 : pos + 1);
}

char	*ft_copynarg(int n, const char *format)
{
	int i;

	i = 0;
	while (n && format[i])
	{
		if (format[i] == '%')
			n--;
		if (n - 1 == 0)
			return (ft_strndup(&format[i], ft_arglen(&format[i + 1])));
		i++;
	}
	return (NULL);
}

char	**ft_split_format(const char *format)
{
	char	**ret;
	int		pos;
	int		n;

	n = ft_countargs(format);
	pos = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_countargs(format) + 1)))
		return (NULL);
	ret[n] = NULL;
	while (n != 0)
	{
		if (format[0] != '%')
			ret[n - 1] = ft_copynarg(n, format);
		else
			ret[n - 1] = ft_copynarg(n + 1, format);
		n--;
	}
	return (ret);
}
