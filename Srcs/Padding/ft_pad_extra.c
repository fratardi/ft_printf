/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:51:35 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/22 20:25:47 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_pad_extra(t_printinfo *lst)
{
	int		sig;
	char	*tmp;

	sig = 0;
	if (!lst->extra || (lst->prec > 0 && ft_strchr("diouxX", lst->t)))
		return ;
	if (((int)lst->buflen) >= lst->width)
		return ;
	if ((lst->buf[0] == '+') || (lst->buf[0] == '-'))
	{
		sig = (lst->buf[0] == '+') ? 1 : -1;
		tmp = ft_strdup(&lst->buf[1]);
		free(lst->buf);
		lst->buf = tmp;
	}
	lst->buf = ft_joinfree((char *)ft_memaset('0', lst->width -
	((int)lst->buflen) - ((lst->t == 'c') ? 1 : 0)), lst->buf);
	if (sig != 0)
		lst->buf = ft_joinfree(ft_strdup((sig == 1) ? "+" : "-"), lst->buf);
	if (lst->alt && ft_strchr("xX", lst->t))
		lst->buf[1] = (lst->t == 'X') ? 'X' : 'x';
	if (lst->space)
		lst->buf[0] = ' ';
}
