/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 14:09:48 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/26 20:08:15 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/* Display no h mod */

size_t	ft_dispnoh(t_printinfo *list, t_elem *elem)
{
	size_t ret;
	
	if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
		ret = ft_printlli(elem->lli, list);
	else if (list->t == 'o')
		ret = ft_convert_o(elem->ulli, list);
	else if (list->t == 'x')
		ret = ft_convert_x(elem->ulli, list);
	else if (list->t == 'X')
		ret = ft_convert_X(elem->ulli, list);
	else if (list->t == 'u')
		ret = ft_printulli(elem->ulli, list);
	else if (list->t == 'p')
		ret = ft_convert_p(elem->value, list);
	return (ret);
}

/* Display with h mod -- char*/

size_t ft_disphmodchar(t_printinfo *list, t_elem *elem)
{
	size_t ret;

	ret = 0;
	if (list->is_char == 1)
	{
		if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
			ret = ft_printlli((signed char)elem->lli, list);
		else if (list->t == 'o')
			ret = ft_convert_o((unsigned char)elem->ulli, list);
		else if (list->t == 'x')
			ret = ft_convert_x((unsigned char)elem->ulli, list);
		else if (list->t == 'X')
			ret = ft_convert_X((unsigned char)elem->ulli, list);
		else if (list->t == 'u')
			ret = ft_printulli((unsigned char)elem->ulli, list);
		else if (list->t == 'p')
			ret = ft_convert_p(elem->value, list);
	}
	return (ret);
}

/* Display with h mod -- Short */

size_t ft_disphmodshort(t_printinfo *list, t_elem *elem)
{
	size_t ret;
	
	ret = 0;
	if (list->is_short == 1)
	{
		if (ft_strchr("di", list->t) && list->is_unsigned == 0 && list->is_char == 0)
			ret = ft_printlli((short)elem->lli, list);
		else if (list->t == 'o')
			ret = ft_convert_o((unsigned short)elem->ulli, list);
		else if (list->t == 'x')
			ret = ft_convert_x((unsigned short)elem->ulli, list);
		else if (list->t == 'X')
			ret = ft_convert_X((unsigned short)elem->ulli, list);
		else if (list->t == 'u')
			ret = ft_printulli((unsigned short)elem->ulli, list);
		else if (list->t == 'p')
			ret = ft_convert_p(elem->value, list);
	}
	return (ret);
}

/* Display Binary Content */

size_t	ft_binmod(t_printinfo *list, t_elem *elem, char *buf)
{
	if (list->t == 's')
		ft_displaybin(elem->value, ft_strlen(elem->value));
		
}