/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:50:13 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/03 03:24:17 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

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
	while(str[i] && (ft_isdigit(str[i]) || str[i] == '.'))
		i++;
	return (i);
}

size_t		ft_endseq(char *s1)
{
	int i;
	size_t ret;
	char *temp;
	t_no_syntax	content;

	ret = 0;
	i = ft_init_sequence(s1, &content);
	if (s1[i] == 0)
		return(0);
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
	size_t		ret;
	char		*temp;
	int			i;
	t_no_syntax	content;

	ret = 0;
	if (s2 == NULL)
		return (0);
	i = ft_init_sequence(s1, &content);
	if (content.left)
	{
		if (s1[i] == 0)
			ft_putchar(s2[0]);
		else
			ft_putchar(s1[i]);
		ret++;
	}
	if (content.width > 0)
	{
		temp = ft_memaset((content.extra == 1) ? '0' : ' ', content.width);
		ret += ft_print_uni_str(temp);
		free(temp);
	}
	if (s1[i])
	{
		ret += ft_print_uni_str(&s1[i + ((content.left) ? 1 : 0)]);
		*open = 1;
	}
	else
	{
		ret += ft_print_uni_str((content.left) ? &s2[1] : s2);
		*open = 0;
	}
	return (ret);
}

size_t		ft_putonlystring(char **tab)
{
	size_t	ret;
	size_t	i;
	int open;

	ret = 0;
	i = 0;
	open = 1;
	while (tab[i])
	{
		if (tab[i][0] == '%' && tab[i + 1])
		{
			ret += ft_sequence(tab[i], tab[i + 1], &open);
			if (open == 0)
				i += 1;
		}
		else if (tab[i][0] == '%' && tab[i][1])
			ret += ft_endseq(tab[i]);
		else if (tab[i][0] != '%')
			ret += ft_print_uni_str(tab[i]);
		i++;
	}
	return (ret);
}

size_t		ft_display(char **tab, t_printinfo *l)
{
	size_t	ret;
	size_t	i;
	int open;

	ret = 0;
	i = 0;
	if (onlystring(tab) == 1)
		return (ft_putonlystring(tab));
	while (tab[i])
	{
		if (ft_issyntax(tab[i]) == 0 && tab[i][0] == '%' && tab[i + 1])
		{
			ret += ft_sequence(tab[i], tab[i + 1], &open);
			if (ft_issyntax(tab[i + 1]) == 1)
				l = l->next;
			if (open == 0)
				i += 1;
		}
		else if (ft_issyntax(tab[i]) == 0 && tab[i][0] == '%' && !tab[i + 1] && tab[i][1])
			ret += ft_endseq(tab[i]);
		else if (ft_issyntax(tab[i]) == 1)
		{
			ret += ft_print_uni_str(l->buf);
			(l->special == 0 && (ret += 1)) ? ft_putchar('\0') : 0;
			ret += ft_print_uni_str(ft_rest(tab[i]));
			l = l->next;
		}
		else if (tab[i][0] != '%')
			ret += ft_print_uni_str(tab[i]);
		i++;
	}
	return (ret);
}
