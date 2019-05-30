/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_addstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 03:46:23 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/30 03:47:31 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_addstrings_stack(char *assign, char *base, int po_assig, int po_base)
{
	po_assig -= (!assign[po_assig]) ? 1 : 0;
	po_base -= (!base[po_base]) ? 1 : 0;
	if (po_assig < 0 || po_base < 0)
		return ;
	if ((((assign[po_assig]) - '0' + (base[po_base] - '0')) <= 9))
	{
		assign[po_assig] = assign[po_assig] + (base[po_base] - '0');
		ft_addstrings_stack(assign, base, --po_assig, --po_base);
	}
	else
	{
		assign[po_assig] = assign[po_assig] + base[po_base] - 10 - '0';
		assign[po_assig - 1]++;
		ft_addstrings_stack(assign, base, --po_assig, --po_base);
	}
	return ;
}
