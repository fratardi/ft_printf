/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:50:13 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/05 02:17:47 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t		ft_putonlystring(char **tab)
{
	size_t	ret;
	size_t	i;
	int		open;

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

int			ft_print_not_syntax(t_printinfo *l, char **tab, int i, size_t *ret)
{
	int open;

	open = 1;
	if (ft_issyntax(tab[i]) == 0 && tab[i][0] == '%' && tab[i + 1])
	{
		*ret += ft_sequence(tab[i], tab[i + 1], &open);
		l = (ft_issyntax(tab[i + 1]) == 1) ? l->next : l;
		i += (open == 0) ? 1 : 0;
	}
	else if (ft_issyntax(tab[i]) == 0 && tab[i][0] == '%' && !tab[i + 1] &&
		tab[i][1])
		*ret += ft_endseq(tab[i]);
	return (i);
}

size_t		ft_display(char **tab, t_printinfo *l)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	if (onlystring(tab) == 1)
		return (ft_putonlystring(tab));
	while (tab[i])
	{
		if (ft_issyntax(tab[i]) == 0 && tab[i][0] == '%')
			i = ft_print_not_syntax(l, tab, i, &ret);
		else if (ft_issyntax(tab[i]) == 1)
		{
			(l->left && l->special == 0 && (ret += 1)) ? ft_putchar('\0') : 0;
			if (l->special == 1 || (l->special == 0 && l->width > 1))
				ret += ft_print_uni_str(l->buf);
			(!l->left && l->special == 0 && (ret += 1)) ? ft_putchar('\0') : 0;
			ret += ft_print_uni_str(ft_rest(tab[i]));
			l = l->next;
		}
		else if (tab[i][0] != '%' && tab[i])
			ret += ft_print_uni_str(tab[i]);
		i++;
	}
	return (ret);
}
