/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:01:14 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/23 04:32:34 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_free_elem(t_elem *elem, t_printinfo *list)
{
	t_printinfo	*start;
	t_elem		*temp;

	start = NULL;
	temp = NULL;
	if (!list || !elem)
		return ;
	start = list;
	while (list->next)
	{
		while (list->next && list->ndol != elem->pos)
			list = list->next;
		if (elem->pos == list->ndol)
		{
			temp = elem->next;
			free(elem);
			if (temp == NULL)
				break ;
			elem = temp;
			list = start;
		}
	}
	free(elem);
}

void	ft_free_printinfo(t_printinfo *list)
{
	t_printinfo *temp;

	while (list->next)
	{
		temp = list->next;
		free(list->buf);
		free(list);
		list = temp;
	}
	free(list);
}
