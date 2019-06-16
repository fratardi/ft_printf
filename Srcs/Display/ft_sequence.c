/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 02:07:09 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/16 19:04:19 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"
#include <stdlib.h>

int			ft_init_sequence(char *str, t_no_syntax *content)
{
	int i;

	content->extra = 0;
	content->left = 0;
	i = 1;
	while (ft_strchr("-+ 0#", str[i]) && str[i])
	{
		(str[i] == '-') ? (content->left = 1) : 0;
		(str[i] == '0') ? (content->extra = 1) : 0;
		i++;
	}
	content->width = ft_atoi((str + i));
	content->width -= (content->width) ? 1 : 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.'))
		i++;
	return (i);
}

size_t		ft_endseq(char *s1)
{
	int			i;
	size_t		ret;
	char		*temp;
	t_no_syntax	content;

	ret = 0;
	i = ft_init_sequence(s1, &content);
	if (s1[i] == 0)
		return (0);
	if (content.left)
	{
		ft_putchar(s1[i]);
		ret++;
	}
	if (content.width > 0)
	{
		temp = ft_memaset((content.extra == 1) ? '0' : ' ', content.width);
		ret += ft_print_uni_str(temp);
		free(temp);
	}
	ret += ft_print_uni_str(&s1[i + ((content.left) ? 1 : 0)]);
	return (ret);
}

size_t		ft_sequence(char *s1, char *s2, int *open)
{
	char		*temp;
	int			i;
	t_no_syntax	content;

	content.ret = 0;
	if (s2 == NULL)
		return (0);
	i = ft_init_sequence(s1, &content);
	if (content.left)
	{
		ft_putchar((s1[i] == 0) ? s2[0] : s1[i]);
		content.ret++;
	}
	if (content.width > 0)
	{
		temp = ft_memaset((content.extra == 1) ? '0' : ' ', content.width);
		content.ret += ft_print_uni_str(temp);
		free(temp);
	}
	if (s1[i])
		content.ret += ft_print_uni_str(&s1[i + ((content.left) ? 1 : 0)]);
	else
		content.ret += ft_print_uni_str((content.left) ? &s2[1] : s2);
	*open = (s1[i]) ? 1 : 0;
	return (content.ret);
}
