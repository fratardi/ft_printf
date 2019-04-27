/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issyntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:40:55 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/27 15:53:38 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Verify if str contain a good syntax
*/

int		ft_issyntax(char *str)
{
	int i;

	i = 1;
	if (str[0] != '%' || (str[0] == '%' && str[1] == '%'))
		return (0);
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] == 0)
		i = 1;
	else
		while (str[i] && (str[i] == '$' || ft_isdigit(str[i]) == 1))
			i++;
	while (str[i] && ft_strchr("# 0'-+", str[i]) != NULL)
		i++;
	while (str[i] && (ft_isdigit(str[i]) == 1 || str[i] == '*'))
		i++;
	while (str[i] && str[i] == '.')
		i++;
	while (str[i] && (ft_isdigit(str[i]) == 1 || str[i] == '*'))
		i++;
	while (str[i] && ft_strchr("hlL", str[i]) != NULL)
		i++;
	if (str[i] && ft_strchr("diouxXcfsp", str[i]) != NULL)
		return (1);
	return (0);
}
