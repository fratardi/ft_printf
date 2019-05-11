/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:50:13 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/11 21:32:06 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/* int onlystring(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		if (ft_issyntax(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
} */

size_t	ft_putonlystring(char **tab)
{
	int		i;
	int		percent;
	size_t	ret;

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
			ft_putstr(((percent + 1) % 2 == 0) ? tab[i] : "%");
		}
		i++;
	}
	return (ret);
}

size_t	ft_display(char **tab, t_printinfo *list)
{
	size_t i;
	size_t ret;
	char *temp;

	i = 0;
	ret = 0;
	if (onlystring(tab) == 1)
		return (ft_putonlystring(tab));
	while(tab[i])
	{
		if (ft_issyntax(tab[i]) == 1)
		{
			ret += ft_print_n_uni_str(list->buf, list->buflen);
			temp = ft_rest(tab[i]);
			ret += ft_print_n_uni_str(temp, ft_strlen(temp));
			list = list->next;
		}
		else
			ret += ft_print_n_uni_str(tab[i], ft_strlen(tab[i]));
		i++;
	}
	return (ret);
}