/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:48:00 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/28 16:29:47 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Align String
*/

size_t	ft_alignstr(char *str, t_printinfo *list)
{
	size_t ret;

	ret = 0;
	list->width -= ft_strlen(str);
	while(list->width--)
	{
		ft_putchar(' ');
		ret++;
	}
	ret += ft_print_n_uni_str(str, list->prec);
	return (ret);
}

/*
**Display the list with proper syntax and conversion
*/

void	ft_printnotsynt(int *i, int *percent, size_t *ret, char **tab)
{
	if (tab[*i][0] != '%')
	{
		ft_putstr(tab[*i]);
		*ret += ft_strlen(tab[*i]);
	}
	else if (tab[*i][0] == '%' && tab[*i][1] != 0)
	{
		ft_putstr(&tab[*i][1]);
		*ret += ft_strlen(&tab[*i][1]);
	}
	else
	{
		percent = 0;
		while (tab[*i] && tab[*i][0] == '%' && tab[*i][1] == 0)
		{
			percent++;
			i++;
		}
		if ((*percent + 1) % 2 == 0)
			ft_putstr(tab[*i]);
	}
}

void	ft_printsyntax(size_t *ret, t_elem *elem, t_printinfo *list)
{
	if (list->is_short == 0 && list->is_char == 0)
		*ret += ft_dispnoh(list, elem);
	else if (list->is_short == 1)
		*ret += ft_disphmodshort(list, elem);
	else if (list->is_char == 1)
		*ret += ft_disphmodchar(list, elem);
	if (list->type == 2)
	{
		ret++;
		ft_putchar((int)elem->lli);
	}
	else if (list->type == 4)
		*ret += ft_alignstr(elem->value, list);
	else if (list->type == 7)
		*ret += ft_ldouble((list->is_long_double == 0) ? \
			elem->dble : elem->long_double, list->prec);
}

size_t	ft_display(char **tab, t_printinfo *list, t_elem *elem)
{
	int		i;
	int		percent;
	size_t	ret;

	i = 0;
	percent = 0;
	ret = 0;
	while (tab[i])
	{
		if (ft_issyntax(tab[i]) == 0)
			ft_printnotsynt(&i, &percent, &ret, tab);
		else if (ft_issyntax(tab[i]) == 1)
		{
			while (elem->next && elem->pos < list->ndol)
				elem = elem->next;
			while (elem->previous && elem->pos > list->ndol)
				elem = elem->previous;
			ft_printsyntax(&ret, elem, list);
			ft_putstr(ft_rest(NULL, tab[i]));
			ret += ft_strlen(ft_rest(NULL, tab[i]));
			list = list->next;
		}
		i++;
	}
	return (ret);
}
