/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:00:51 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/12 02:01:09 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Fill the structure
*/

t_elem	*ft_filldi(t_printinfo *list, va_list va, t_elem *elem)
{
	if (list->is_long_double)
		elem->lli = va_arg(va, long long int);
	else if (list->is_long)
		elem->lli = va_arg(va, long int);
	else
		elem->lli = va_arg(va, int);
	return (elem);
}

t_elem	*ft_fillunsigned(t_printinfo *list, va_list va, t_elem *elem)
{
	if (list->is_long_double)
		elem->ulli = va_arg(va, unsigned long long int);
	else if (list->is_long)
		elem->ulli = va_arg(va, unsigned long int);
	else
		elem->ulli = va_arg(va, unsigned int);
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
