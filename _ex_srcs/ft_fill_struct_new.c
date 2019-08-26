/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 00:57:26 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/26 02:37:39 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

/*
**Fill ndol
*/

t_printinfo	*ft_fillndol(char *str, t_printinfo *list)
{
	int i;

	i = 0;
    // ft_print_t_list_content(list);
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] == 0 || i == 0)
		return (list);
	i = 0;
	list->ndol = ft_atoi(&str[i]);
    return (list);
}

/*
**Fill Flag
*/

t_printinfo	*ft_fillflag(char *str, t_printinfo *list)
{
    int i;
    i = 0;

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
	return (list);
}

/*
**Fill precision
*/

t_printinfo	*ft_fillprec(char *str, t_printinfo *list)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.' && !ft_strchr("diouxXcfpsbBOU", str[i]))
		i++;
	while (str[i] && str[i] == '.' && !ft_strchr("diouxXcfpsbBOU", str[i]))
		i++;
	if (!str[i] || (ft_strchr("diouxXcfpsbBOU", str[i]) && str[i - 1] != '.'))
		return (list);
	list->prec = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	return (list);
}

/*
**Fill width
*/

t_printinfo	*ft_fillwidth(char *str, t_printinfo *list, t_rep *rep)
{
	int i;

	i = 0;
/* 	while (str[i] && str[i] != '$')
		i++; */
/* 	i = (!str[i]) ? 0 : i;
	while (str[i] && ft_strchr("$0 #'-+", str[i]))
		i++; */
    if (!ft_isdigit(str[i]) && str[i] != '*')
        return (list);
	if (str[i] != '0' && ft_atoi(&str[i]) == 0 && str[i] != '*')
	{
		list->width = -2;
		return (list);
	}
	list->width = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	if (ft_isdigit(str[i + 1]) && list->width == -1)
	{
		va_arg(rep->current, int);
		rep->vapos++;
		list->width = ft_atoi(&str[i + 1]);
	}
	return (list);
}


/*
**Init the list
*/

void		ft_fillzerolist(t_printinfo *list)
{
    list->is_float_ten = 0;
	list->ndol = 0;
    list->max = 0;
    list->width = -2;
	list->extra = 0;
	list->alt = 0;
	list->showsign = 0;
	list->is_long_double = 0;
	list->is_long = 0;
	list->prec = -2;
	list->is_char = 0;
	list->special = 1;
	list->is_short = 0;
	list->group = 0;
	list->left = 0;
	list->is_unsigned = 0;
	list->space = 0;
	list->bin = 0;
}

/*
**Fill modifier
*/

void		ft_opts_mod(t_printinfo *list, int *i, int *hmod, char *str)
{
	list->is_float_ten = (str[*i] == 'E' || list->is_float_ten) ? 1 : 0;
    list->max = (str[*i] == 'j' || list->max) ? 1 : 0;
    list->is_long = (str[*i] == 'z' || list->is_long) ? 1 : 0;
	list->is_long_double = (str[*i] == 'L' || list->is_long_double) ? 1 : 0;	
	while (str[*i] && ft_strchr("h", str[*i]) != NULL)
	{
		*hmod += 1;
		*i += 1;
	}
    if (!list->is_char)
    	list->is_char = (*hmod % 2 == 0 && *hmod != 0) ? 1 : 0;
    if (!list->is_char)
        list->is_short = (*hmod % 2 != 0 && *hmod != 0) ? 1 : 0;
	// ft_print_t_list_content(list);    
}

t_printinfo	*ft_fillmod(char *str, t_printinfo *list)
{
	int i;
	int hmod;
	int lmod;

	i = 0;
	hmod = 0;
	lmod = 0;
	while (str[i] && ft_strchr("hlLzjE", str[i]) == NULL &&
	!ft_strchr("diouxXcfpsOU", str[i]))
		i++;
    if (ft_strchr("diouxXcfpsOU", str[i]))
        return (list);
	ft_opts_mod(list, &i, &hmod, str);
	while (str[i] && ft_strchr("l", str[i]) != NULL)
	{
		lmod++;
		i++;
	}
    if (!list->is_long_double)
	    list->is_long_double += (lmod % 2 == 0 && lmod != 0) ? 1 : 0;
	if (!list->is_long_double)
        list->is_long += (lmod % 2 != 0 && lmod != 0) ? 1 : 0;
	if (list->is_long || list->is_long_double)
	{
		list->is_char = 0;
		list->is_short = 0;
	}
	return (list);
}

/*
**Fill Type
*/

t_printinfo	*ft_filltype(char *str, t_printinfo *list)
{
	int i;

	i = 0;
	while (str[i] && ft_strchr("diouxXcfFspOUbB", str[i]) == NULL)
		i++;
	list->t = (ft_strchr("diouxXcfFspOUbB", str[i]) != NULL) ? str[i] : 0;
	if (ft_strchr("ouOUxX", list->t))
		list->is_unsigned = 1;
	return (list);
}
