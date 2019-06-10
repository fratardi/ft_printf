/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:04:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/10 21:17:12 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"
#include <stdio.h>

/*
**Count how many Arguments to be read
*/

int		ft_howmanyva(char **tab)
{
	int i;
	int y;
	int count;
	int temp;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_issyntax(tab[i]) == 1)
		{
			temp = 0;
			y = 0;
			while (tab[i][y] && tab[i][y] != '$')
				y++;
			if (tab[i][y] != 0)
				temp = ft_atoi(&tab[i][1]);
			if (temp > count)
				count = temp;
			else if (temp == 0)
				count++;
		}
		i++;
	}
	return (count);
}

/*
**Read printinfo to fill elem
*/

t_elem	*ft_readfill(t_printinfo *list, va_list va, t_elem *elem)
{
	if (list->width == -1)
		list->width = va_arg(va, int);
	if ((list->type == 1 || list->type == 2) && !list->is_unsigned)
		elem = ft_filldi(list, va, elem);
	else if ((list->type == 1 || list->type == 2) && list->is_unsigned)
		elem = ft_fillunsigned(list, va, elem);
	else if (list->type == 7)
		elem = ft_fillfloats(list, va, elem);
	else if (list->type == 6 || list->t == 'B')
		elem->value = va_arg(va, void *);
	else if (list->type == 4 && !list->is_long)
		elem->value = va_arg(va, char *);
	else if (list->t == 'b')
		elem->lli = va_arg(va, long long int);
	if (!(elem->next = (t_elem *)malloc(sizeof(t_elem))))
		exit(0);
	elem->next->pos = elem->pos + 1;
	elem->next->previous = elem;
	elem = elem->next;
	elem->next = NULL;
	list = list->next;
	return (elem);
}

/*
**Read Elypse and fill elem list
*/

t_va	ft_initvaread(t_printinfo *list, char **tab)
{
	t_va varead;

	varead.pstart = list;
	varead.nb_pos = 1;
	if (!(varead.elem = (t_elem *)malloc(sizeof(t_elem))))
		exit(0);
	varead.elem->previous = NULL;
	varead.elem->pos = 1;
	varead.elem->next = NULL;
	varead.start = varead.elem;
	varead.nb_va = (size_t)ft_howmanyva(tab);
	return (varead);
}

t_elem	*ft_varead(t_printinfo *list, va_list va, char **tab)
{
	t_va varead;

	varead = ft_initvaread(list, tab);
	while (varead.nb_pos <= varead.nb_va && (list = varead.pstart))
	{
		while (list->next && varead.nb_pos <= varead.nb_va)
		{
			list = varead.pstart;
			while (list->next && list->ndol != varead.nb_pos)
				list = list->next;
			if (list->next == NULL)
			{
				va_arg(va, void *);
				varead.nb_pos += 1;
				varead.elem->pos += 1;
				list = varead.pstart;
			}
			else
				break ;
		}
		varead.elem = (varead.nb_pos == list->ndol) ?
		ft_readfill(list, va, varead.elem) : varead.elem;
		varead.nb_pos += 1;
	}
	return (varead.start);
}
