/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:01:14 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/20 18:17:33 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

void	ft_free_elem(t_elem *elem, t_printinfo *list)
{
	t_printinfo	*start;
	t_elem		*temp;

	start = NULL;
	temp = NULL;
	if (!list || !elem)
		return ;
	start = list;
	while (list->next && elem->next)
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

void	ft_free_parsing(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab[i]);
	free(tab);
}

void	ft_free_printf(char **tab, t_elem *elem, t_printinfo *list)
{
	ft_free_parsing(tab);
	ft_free_elem(elem, list);
	ft_free_printinfo(list);
}
