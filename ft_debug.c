/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 03:07:08 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/24 03:07:31 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		ft_print_t_list_content(t_printinfo *info)
{
	ft_putendl(ft_itoa(info->prec));
	ft_putendl(ft_itoa(info->width));
	ft_putendl(ft_ullitoa(info->ndol));
	ft_putendl(ft_ullitoa(info->max));
	ft_putendl(ft_ullitoa(info->is_long_double));
	ft_putendl(ft_ullitoa(info->is_char));
	ft_putendl(ft_ullitoa(info->is_unsigned));
	ft_putendl(ft_ullitoa(info->is_short));
	ft_putendl(ft_ullitoa(info->is_long));
	ft_putendl(ft_ullitoa(info->is_float_ten));
	ft_putendl(ft_ullitoa(info->alt));
	ft_putendl(ft_ullitoa(info->space));
	ft_putendl(ft_ullitoa(info->left));
	ft_putendl(ft_ullitoa(info->showsign));
	ft_putendl(ft_ullitoa(info->group));
	ft_putendl(ft_ullitoa(info->extra));
	ft_putendl(ft_ullitoa(info->bin));
	ft_putendl(&info->t);
	ft_putendl(&info->special);
}