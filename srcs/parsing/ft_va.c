/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:11:07 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/06 19:48:03 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

void	ft_star_search(t_rep *rep, t_printinfo *info)
{
	if (info->width == -1)
	{
		info->width = va_arg(rep->current, int);
		rep->vapos++;
	}
	if (info->prec == -1)
	{
		info->prec = va_arg(rep->current, int);
		rep->vapos++;
	}
}

/* va_list	ft_arg_search(t_rep rep, const char *format)
{
	if ()
} */

