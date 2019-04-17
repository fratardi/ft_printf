/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:51:03 by tpacaud           #+#    #+#             */
/*   Updated: 2019/03/30 19:30:29 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

/* Verify if Format string is only a string */

int onlystring(char **tab)
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

/* Print Only String */

size_t ft_putonlystring(char **tab)
{
	int i;
	int percent;
	size_t ret;

	i = 0;
	ret = 0;
	while (tab[i])
	{
		if (tab[i][0] != '%')
		{
			ft_putstr(tab[i]);
			ret += ft_strlen(tab[i]);
		}
		else if (tab[i][0] == '%' && tab[i][1] != 0)
		{
			ft_putstr(&tab[i][1]);
			ret += ft_strlen(&tab[i][1]);
		}
		else
		{
			percent = 0;
			while (tab[i] && tab[i][0] == '%' && tab[i][1] == 0)
			{
				percent++;
				i++;
			}
			ft_putstr(((percent + 1) % 2 == 0) ? tab[i] : "");
		}
		i++;
	}
	return (ret);
}

/* Modify ndol to know witch element to print */

void ft_modndol(t_printinfo *list)
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

/* Main Function */

size_t ft_printf(const char *format, ...)
{
	char **tab;
	va_list va;
	t_printinfo *list;
	t_elem *elem;

	tab = ft_split_format(format);
	if (onlystring(tab) == 1)
	{
		ft_putonlystring(tab);
		return (ft_strlen(format));
	}
	list = ft_fillstruct(tab);
	ft_modndol(list);
	va_start(va, format);
	elem = ft_varead(list, va, tab);
	va_end(va);
	//ft_debugelem(elem);
	return (ft_display(tab, list, elem));
}