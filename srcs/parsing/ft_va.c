/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:11:07 by tpacaud           #+#    #+#             */
/*   Updated: 2019/07/31 12:32:27 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

t_rep	ft_star_search(t_rep rep, const char *fmt, t_printinfo *info)
{
	if (info->width == -1)
		info->width = va_arg(rep.current, int);
	return (rep);
}

va_list	ft_arg_search(t_rep rep, const char *format)
{
	if ()
}

