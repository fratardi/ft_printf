/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:11:07 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/13 01:42:47 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

void	ft_star_search(t_rep *rep, t_printinfo *info)
{
	if (info->width == -1)
	{
		info->width = va_arg(rep->current, int);
		if (info->width < 0)
		{
			info->left = 1;
			info->width = -info->width;
		}
		rep->vapos++;
	}
	if (info->prec == -1)
	{
		info->prec = va_arg(rep->current, int);
		rep->vapos++;
		if (info->prec < 0)
			info->prec = -2;
	}
}

void	ft_arg_search(t_rep *rep, t_printinfo *info)
{
	if (!info->ndol || rep->vapos == 0)
		return ;
	if (info->ndol != 0 && info->ndol != rep->vapos)
	{
		if (info->ndol < rep->vapos)
		{
			va_end(rep->current);
			va_copy(rep->current, rep->start);
			rep->vapos = 1;
		}
		while (rep->vapos < info->ndol)
		{
			va_arg(rep->current, int);
			rep->vapos++;
		}
	}
}
