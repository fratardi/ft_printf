/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tileprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:56:34 by tpacaud           #+#    #+#             */
/*   Updated: 2018/11/14 13:19:23 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tileprint(t_list *ptr)
{
	ft_putstr("Content of tile = ");
	ft_putstr((char*)ptr->content);
	ft_putchar('\n');
}
