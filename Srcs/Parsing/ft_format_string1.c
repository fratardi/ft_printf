/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:12:19 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/22 15:59:50 by fratardi         ###   ########.fr       */
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
	//printf("debug = %d__\n", list->showsign);
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
	while (str[i] && str[i] != '.' && !ft_strchr("cs", str[i]))
		i++;
	while (str[i] && str[i] == '.'&& !ft_strchr("cs", str[i]))
		i++;
	if (!str[i] || (ft_strchr("cCsS", str[i]) && str[i - 1] != '.'))
		return (list);
/* 	if (str[i] == '0')
	{
		list->prec = -1;
		return (list);
	}
	if (str[i] != '0' && ft_atoi(&str[i]) == 0)
	{
		list->prec = -1;
		return (list);
	} */
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
	if (str[i] != '0' && ft_atoi(&str[i]) == 0)
	{
		list->width = -2;
		return(list);
	}
	list->width = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	return (list);
}
