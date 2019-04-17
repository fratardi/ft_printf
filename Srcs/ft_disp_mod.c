/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:09:48 by tpacaud           #+#    #+#             */
/*   Updated: 2019/03/31 14:25:37 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

/* Display no h mod */

char *ft_dispnoh(t_printinfo *list, t_elem *elem, char *buf)
{
	if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
		buf = ft_printlli(elem->lli, list, buf);
	else if (list->t == 'o')
		buf = ft_convert_o(elem->ulli, list, buf);
	else if (list->t == 'x')
		buf = ft_convert_x(elem->ulli, list, buf);
	else if (list->t == 'X')
		buf = ft_convert_X(elem->ulli, list, buf);
	else if (list->t == 'u')
		buf = ft_printulli(elem->ulli, list, buf);
	else if (list->t == 'p')
		buf = ft_convert_p(elem->value, list, buf);
	return (buf);
}

/* Display with h mod -- char*/

char 	*ft_disphmodchar(t_printinfo *list, t_elem *elem, char *buf)
{
	if (list->is_char == 1)
	{
		if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
			buf = ft_printlli((signed char)elem->lli, list, buf);
		else if (list->t == 'o')
			buf = ft_convert_o((unsigned char)elem->ulli, list, buf);
		else if (list->t == 'x')
			buf = ft_convert_x((unsigned char)elem->ulli, list, buf);
		else if (list->t == 'X')
			buf = ft_convert_X((unsigned char)elem->ulli, list, buf);
		else if (list->t == 'u')
			buf = ft_printulli((unsigned char)elem->ulli, list, buf);
		else if (list->t == 'p')
			buf = ft_convert_p(elem->value, list, buf);
	}
	return (buf);
}

/* Display with h mod -- Short */

char *ft_disphmodshort(t_printinfo *list, t_elem *elem, char *buf)
{
	if (list->is_short == 1)
	{
		if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
			buf = ft_printlli((short)elem->lli, list, buf);
		else if (list->t == 'o')
			buf = ft_convert_o((unsigned short)elem->ulli, list, buf);
		else if (list->t == 'x')
			buf = ft_convert_x((unsigned short)elem->ulli, list, buf);
		else if (list->t == 'X')
			buf = ft_convert_X((unsigned short)elem->ulli, list, buf);
		else if (list->t == 'u')
			buf = ft_printulli((unsigned short)elem->ulli, list, buf);
		else if (list->t == 'p')
			buf = ft_convert_p(elem->value, list, buf);
	}
	return (buf);
}