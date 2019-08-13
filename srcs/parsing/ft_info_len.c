/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 06:19:05 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/13 06:19:16 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_syntaxlen(const char *format)
{
	int i;

	i = 1;
	while (format[i] && ft_strchr("diouxXcfspUObB", format[i]) == NULL)
		i++;
	if (ft_strchr("diouxXcfspUObB", format[i]) != NULL)
		i++;
	return (i);
}

int			ft_sequencelen(const char *format)
{
	int i;

	i = 0;
	if (format[0])
		i++;
	while (format[i] && ft_strchr("%", format[i]) == NULL)
		i++;
	return (i);
}
