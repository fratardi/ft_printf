/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:48:00 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/13 18:11:22 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"
#include <stdio.h>

/* Display no h mod */

size_t ft_dispnoh(t_printinfo *list, t_elem *elem, size_t ret)
{
	if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
		ret += ft_printlli(elem->lli, list);
	else if (list->t == 'o')
		ft_convert_o(elem->ulli, list);
	else if (list->t == 'x')
		ft_convert_x(elem->ulli, list);
	else if (list->t == 'X')
		ft_convert_X(elem->ulli, list);
	else if (list->t == 'u')
		ret += ft_printulli(elem->ulli, list);
	else if (list->t == 'p')
		ft_convert_p(elem->value, list);
	return (ret);
}

/* Display with h mod -- char*/

size_t ft_disphmodchar(t_printinfo *list, t_elem *elem, size_t ret)
{
	if (list->is_char == 1)
	{
		if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
			ret += ft_printlli((signed char)elem->lli, list);
		else if (list->t == 'o')
			ft_convert_o((unsigned char)elem->ulli, list);
		else if (list->t == 'x')
			ft_convert_x((unsigned char)elem->ulli, list);
		else if (list->t == 'X')
			ft_convert_X((unsigned char)elem->ulli, list);
		else if (list->t == 'u')
			ret += ft_printulli((unsigned char)elem->ulli, list);
		else if (list->t == 'p')
			ft_convert_p(elem->value, list);
	}
	return (ret);
}

/* Display with h mod -- Short */

size_t ft_disphmodshort(t_printinfo *list, t_elem *elem, size_t ret)
{
	if (list->is_short == 1)
	{
		if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
			ret += ft_printlli((short)elem->lli, list);
		else if (list->t == 'o')
			ft_convert_o((unsigned short)elem->ulli, list);
		else if (list->t == 'x')
			ft_convert_x((unsigned short)elem->ulli, list);
		else if (list->t == 'X')
			ft_convert_X((unsigned short)elem->ulli, list);
		else if (list->t == 'u')
			ret += ft_printulli((unsigned short)elem->ulli, list);
		else if (list->t == 'p')
			ft_convert_p(elem->value, list);
	}
	return (ret);
}

/* Display the list with proper syntax and conversion */

size_t ft_display(char **tab, t_printinfo *list, t_elem *elem)
{
	int i;
	int percent;
	size_t ret;

	i = 0;
	percent = 0;
	ret = 0;
	while (tab[i])
	{
		if (ft_issyntax(tab[i]) == 0)
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
				if ((percent + 1) % 2 == 0)
					ft_putstr(tab[i]);
			}
		}
		else if (ft_issyntax(tab[i]) == 1)
		{
			while (elem->next && elem->pos < list->ndol)
				elem = elem->next;
			while (elem->previous && elem->pos > list->ndol)
				elem = elem->previous;
			if (list->is_short == 0 && list->is_char == 0)
				ret += ft_dispnoh(list, elem, ret);
			else if (list->is_short == 1)
				ret += ft_disphmodshort(list, elem, ret);
			else if (list->is_char == 1)
				ret += ft_disphmodchar(list, elem, ret);
			if (list->type == 2)
			{
				ret++;
				ft_putchar((int)elem->lli);
			}
			else if (list->type == 4)
				ret += ft_print_uni_str(elem->value);
/* 			else if (list->type == 7)
				ft_hexfloat((float *)&(elem->dble), sizeof(float)); */
			ft_putstr(ft_rest(NULL, tab[i]));
			ret += ft_strlen(ft_rest(NULL, tab[i]));
			list = list->next;
		}
		i++;
	}
	return (ret);
}