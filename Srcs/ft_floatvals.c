/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatvals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:07:25 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/04 15:39:08 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h" 

unsigned int	ft_get_sig(float d)
{
	return(d ? (((unsigned int)d &(1 << 31)) >> 31) : 0);
}

unsigned int	ft_get_exp(float d)
{
	return(d ? (((unsigned int )d  & 0x7F000000) >> 24  ) : 0);
}

