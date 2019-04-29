/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:37:18 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/29 21:18:14 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_pad(t_printfinfo *info, t_elem *list)
{
	t_printinfo *tmpi;
	t_elem		*tmplist;

	tmpi = info;
	tmplist = list;
	while(*tmpi && *tmplist)
	{
		ft_pad_alt(*tmpi ,*tmplist);	
/*		ft_pad_extra(*tmpi ,*tmplist);
		ft_pad_left(*tmpi ,*tmplist);
		ft_pad_space(*tmpi ,*tmplist);
		ft_pad_showsig(*tmpi ,*tmplist);	
		ft_pad_group(*tmpi ,*tmplist);*/
		tmpelem = tmpelem->next;
		tmpi = tmpi->next;			
	}
}
