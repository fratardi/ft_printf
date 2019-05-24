/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:00:51 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/25 00:27:55 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Fill the structure
*/

t_elem	*ft_filldi(t_printinfo *list, va_list va, t_elem *elem)
{
	if (list->is_long_double || list->max)
		elem->lli = va_arg(va, long long int);
	else if (list->is_long)
		elem->lli = va_arg(va, long int);
	else
		elem->lli = va_arg(va, int);
	return (elem);
}

t_elem	*ft_fillunsigned(t_printinfo *list, va_list va, t_elem *elem)
{
	if (list->is_long_double || list->max)
		elem->ulli = va_arg(va, unsigned long long int);
	else if (list->is_long || ft_strchr("OU", list->t))
		elem->ulli = va_arg(va, unsigned long int);
	else
		elem->ulli = va_arg(va, unsigned int);
	if (ft_strchr("OU", list->t))
	{
		list->is_long = 1;
		list->t = (list->t == 'U') ? 'u' : list->t;
		list->t = (list->t == 'O') ? 'o' : list->t;
		list->is_char = 0;
		list->is_short = 0;
	}
	return (elem);
}

t_elem	*ft_fillfloats(t_printinfo *list, va_list va, t_elem *elem)
{
	if (list->is_long_double != 0)
		elem->long_double = va_arg(va, long double);
	else
		elem->dble = va_arg(va, double);
	return (elem);
}
