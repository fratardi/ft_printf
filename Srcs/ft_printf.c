/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:51:03 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/23 05:10:01 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

/*
**Verify if Format string is only a string
*/

int		onlystring(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_issyntax(tab[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

/*
**Modify ndol to know witch element to print
*/

void	ft_modndol(t_printinfo *list)
{
	int i;

	if (list->ndol == 0 && list->width != -1)
		i = 1;
	else if (list->ndol == 0 && list->width == -1)
		i = 2;
	else if (list->ndol != 0)
		i = list->ndol;
	while (list->next)
	{
		if (list->ndol == 0 && list->width != -1)
			list->ndol = i++;
		else if (list->ndol == 0 && list->width == -1)
			list->ndol = i + 2;
		else if (list->ndol != 0)
			i = list->ndol;
		list = list->next;
	}
}

/*
**Main Function
*/

size_t	ft_printf(const char *format, ...)
{
	char		**tab;
	size_t		ret;
	va_list		va;
	t_printinfo	*list;
	t_elem		*elem;

	ret = 0;
	elem = NULL;
	list = NULL;
	tab = NULL;
	if (!format || !(tab = ft_split_format(format)))
		return (0);
	if (onlystring(tab) == 1)
	{
		ret = ft_putonlystring(tab);
		ft_free_parsing(tab);
		return (ret);
	}
	list = ft_fillstruct(tab);
	ft_modndol(list);
	va_start(va, format);
	elem = ft_varead(list, va, tab);
	va_end(va);
	ft_fillbuf(list, elem);
	ft_pad(list);
	ret = ft_display(tab, list);
	ft_free_parsing(tab);
	ft_free_elem(elem, list);
	ft_free_printinfo(list);
	return (ret);
}
