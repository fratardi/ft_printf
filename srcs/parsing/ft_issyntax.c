/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issyntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:40:55 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/12 05:52:29 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_printf.h"

/*
**Verify if str contain a good syntax
*/

int		ft_iterate_syntax(char *str, int i)
{
	if (str[i] == 0)
		i = 1;
	else
		while (str[i] && (str[i] == '$' || ft_isdigit(str[i]) == 1)
			&& str[i] != '0')
			i++;
	while (str[i] && ft_strchr("# 0'-+", str[i]) != NULL)
		i++;
	while (str[i] && ((ft_isdigit(str[i]) == 1) || str[i] == '*'))
		i++;
	while (str[i] && str[i] == '.')
		i++;
	while (str[i] && ((ft_isdigit(str[i]) == 1) || str[i] == '*'))
		i++;
	while (str[i] && ft_strchr("zjhlLE", str[i]) != NULL)
		i++;
	return (i);
}

int		ft_issyntax(char *s, size_t len)
{
	int		i;
	char	*str;

	i = 1;
	if (s[0] != '%' || (s[0] == '%' && s[1] == '%'))
		return (0);
	str = ft_strndup(s, len);
	while (str[i] && str[i] != '$')
		i++;
	if (i != 0 && str[i - 1] == '0')
	{
		free(str);
		return (0);
	}
	i = ft_iterate_syntax(str, i);
	if (str[i] && ft_strchr("diouxXcfspOUBb", str[i]) != NULL)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
