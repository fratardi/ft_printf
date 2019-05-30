/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:39:09 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/30 02:18:45 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Init the list
*/

void		ft_fillzerolist(t_printinfo *list)
{
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
	list->buflen = 0;
}

/*
**Fill modifier
*/

void		ft_opts_mod(t_printinfo *list, int *i, int *hmod, char *str)
{
	list->is_float_ten = (str[*i] == 'E') ? 1 : 0;
	list->max = (str[*i] == 'j') ? 1 : 0;
	list->is_long = (str[*i] == 'z') ? 1 : 0;
	list->is_long_double = (str[*i] == 'L') ? 1 : 0;
	while (str[*i] && ft_strchr("h", str[*i]) != NULL)
	{
		*hmod += 1;
		*i += 1;
	}
	list->is_char = (*hmod % 2 == 0 && *hmod != 0) ? 1 : 0;
	list->is_short = (*hmod % 2 != 0 && *hmod != 0) ? 1 : 0;
}

t_printinfo	*ft_fillmod(char *str, t_printinfo *list)
{
	int i;
	int hmod;
	int lmod;

	i = 0;
	hmod = 0;
	lmod = 0;
	while (str[i] && ft_strchr("hlLzjE", str[i]) == NULL && !ft_strchr("diouxXcfpsOU", str[i]))
		i++;
/* 	if (!str[i] || ft_strchr("diouxXcfpsOU", str[i]))
		return (list); */
	ft_opts_mod(list, &i, &hmod, str);
	while (str[i] && ft_strchr("l", str[i]) != NULL)
	{
		lmod++;
		i++;
	}
	list->is_long_double += (lmod % 2 == 0 && lmod != 0) ? 1 : 0;
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
	if ((ft_strchr("diouxXOU", str[i]) != NULL))
		list->type = PA_INT;
	if (ft_strchr("ouxXOU", str[i]) != NULL)
		list->is_unsigned = 1;
	else if (((str[i] == 'd' || str[i] == 'i') && list->is_char == 1)
	|| str[i] == 'c')
		list->type = PA_CHAR;
	else if (str[i] == 'f')
		list->type = PA_FLOAT;
	else if (str[i] == 'p')
		list->type = PA_POINTER;
	else if (str[i] == 's' || str[i] == 'F')
		list->type = PA_STRING;
	return (list);
}
