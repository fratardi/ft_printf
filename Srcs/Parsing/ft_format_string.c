/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:39:09 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/26 19:24:51 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/* Init the list */

void ft_fillzerolist(t_printinfo *list)
{
	list->extra = 0;
	list->alt = 0;
	list->showsign = 0;
	list->is_long_double = 0;
	list->is_long = 0;
	list->is_char = 0;
	list->is_short = 0;
	list->wide = 0;
	list->group = 0;
	list->left = 0;
	list->is_unsigned = 0;
	list->space = 0;
	list->bin = 0;
}

/* Fill ndol */

t_printinfo *ft_fillndol(char *str, t_printinfo *list)
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

/* Fill Flag */

t_printinfo *ft_fillflag(char *str, t_printinfo *list)
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
	if (ft_strchr("0 #'+-", str[i]) == NULL && str[i - 1] == '%')
		ft_fillzerolist(list);
	return (list);
}

/* Fill precision */

t_printinfo *ft_fillprec(char *str, t_printinfo *list)
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

/* Fill width */

t_printinfo *ft_fillwidth(char *str, t_printinfo *list)
{
	int i;

	i = 1;
	while (str[i] && ft_strchr("0 #'-+", str[i]))
		i++;
	list->width = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	return (list);
}

/* Fill modifier */

t_printinfo *ft_fillmod(char *str, t_printinfo *list)
{
	int i;
	int hmod;
	int lmod;

	i = 0;
	hmod = 0;
	lmod = 0;
	while (str[i] && ft_strchr("hlLz", str[i]) == NULL)
		i++;
	if (str[i] == 'z')
		list->is_long = 1;
	if (str[i] == 'L')
		list->is_long_double = 1;
	while (str[i] && ft_strchr("h", str[i]) != NULL)
	{
		hmod++;
		i++;
	}
	list->is_char = (hmod % 2 == 0 && hmod != 0) ? 1 : 0;
	list->is_short = (hmod % 2 != 0 && hmod != 0) ? 1 : 0;
	while (str[i] && ft_strchr("l", str[i]) != NULL)
	{
		lmod++;
		i++;
	}
	list->is_long_double += (lmod % 2 == 0 && lmod != 0) ? 1 : 0;
	list->is_long += (lmod % 2 != 0 && lmod != 0) ? 1 : 0;
	return (list);
}

/* Fill Type */

// A COMPLETER - CERTAINS TYPES SONT MANQUANTS

t_printinfo *ft_filltype(char *str, t_printinfo *list)
{
	int i;

	i = 0;
	while (str[i] && strchr("diouxXcfsp", str[i]) == NULL)
		i++;
	list->t = (ft_strchr("diouxXcfsp", str[i]) != NULL) ? str[i] : 0;
	if ((ft_strchr("diouxX", str[i]) != NULL) && list->is_char == 0)
		list->type = PA_INT;
	if (ft_strchr("ouxX", str[i]) != NULL)
		list->is_unsigned = 1;
	else if (((str[i] == 'd' || str[i] == 'i') && list->is_char == 1) || str[i] == 'c')
		list->type = PA_CHAR;
	else if (str[i] == 'f')
		list->type = PA_FLOAT;
	else if (str[i] == 'p')
		list->type = PA_POINTER;
	else if (str[i] == 's')
		list->type = PA_STRING;
	return (list);
}