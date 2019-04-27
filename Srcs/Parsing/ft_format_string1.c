/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:12:19 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/27 16:22:08 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Fill ndol
*/

t_printinfo	*ft_fillndol(char *str, t_printinfo *list)
{
	int i;

	i = 1;
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] == 0)
	{
		list->ndol = 0;
		return (list);
	}
	i = 1;
	list->ndol = ft_atoi(&str[i]);
	return (list);
}

/*
**Fill Flag
*/

t_printinfo	*ft_fillflag(char *str, t_printinfo *list)
{
	int i;

	i = 1;
	while (str[i] && ft_strchr("0 #'-+b", str[i]) != NULL)
	{
		if (list->extra != 1)
			list->extra = (str[i] == '0') ? 1 : 0;
		if (list->space != 1)
			list->space = (str[i] == ' ') ? 1 : 0;
		if (list->alt != 1)
			list->alt = (str[i] == '#') ? 1 : 0;
		if (list->left != 1)
			list->left = (str[i] == '-') ? 1 : 0;
		if (list->showsign != 1)
			list->showsign = (str[i] == '+') ? 1 : 0;
		if (list->group != 1)
			list->group = (str[i] == '\'') ? 1 : 0;
		if (list->bin != 1)
			list->bin = (str[i] == 'b') ? 1 : 0;
		i++;
	}
	//if (ft_strchr("0 #'+-", str[i]) == NULL && str[i - 1] == '%')
	//	ft_fillzerolist(list);
	return (list);
}

/*
**Fill precision
*/

t_printinfo	*ft_fillprec(char *str, t_printinfo *list)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	while (str[i] && str[i] == '.')
		i++;
	list->prec = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	return (list);
}

/*
**Fill width
*/

t_printinfo	*ft_fillwidth(char *str, t_printinfo *list)
{
	int i;

	i = 1;
	while (str[i] && ft_strchr("0 #'-+", str[i]))
		i++;
	list->width = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	return (list);
}