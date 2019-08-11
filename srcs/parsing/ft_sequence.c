/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 02:07:09 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/11 22:42:50 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

int			ft_init_sequence(char *str, t_no_syntax *content, size_t len)
{
	int i;

	content->extra = 0;
	content->left = 0;
	i = 1;
	while (ft_strchr("-+ 0#", str[i]) && str[i] && i < len)
	{
		(str[i] == '-') ? (content->left = 1) : 0;
		(str[i] == '0') ? (content->extra = 1) : 0;
		i++;
	}
	content->width = ft_atoi((str + i));
	content->width -= (content->width) ? 1 : 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.') && i < len)
		i++;
	return (i);
}

size_t		ft_sequence(char *s, int len)
{
	char		*temp;
	int			i;
	int			rest_size;
	t_no_syntax	content;

	content.ret = 0;
	rest_size = ft_sequencelen(&s[len]);
	i = ft_init_sequence(s, &content, len);
	if (content.left)
	{
		ft_putchar((s[i] == 0) ? s[len] : s[i]);
		content.ret++;
	}
	if (content.width > 0)
	{
		temp = ft_memaset((content.extra == 1) ? '0' : ' ', content.width);
		content.ret += ft_print_uni_str(temp);
		ft_strdel(&temp);
	}
	if (i <= len)
	{
		if (s[i + ((content.left) ? 1 : 0)] == '%')
			content.ret += ft_print_n_uni_str(&s[i + ((content.left) ? 1 : 0)], rest_size);
		else
			content.ret += ft_print_n_uni_str(&s[i + ((content.left) ? 1 : 0)], len - i);
	}
	else if (s[len] != 0)
		content.ret += ft_print_uni_str((content.left) ? &s[len + 1] : &s[len]);
	return (content.ret);
}
