/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:50:13 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/14 22:52:04 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t ft_putnotsyntax(char *str, char *s1, int *y)
{
	size_t ret;
	size_t i;
	int width;
	char *pad;
	
	if (!str)
		return (0);
	ret = 0;
	
	// printf("y1 = %d", *y);
	width = ft_atoi(&str[(str[1] == '-') ? 2 : 1]);
	width -= (width > 0) ? 1 : 0;
	pad = (width) ? ft_memaset(' ', (size_t)width) : NULL;
	i = (str[1] == '-') ? 2 : 1;
	while (str[i] && ft_strchr("0123456789.- +0#", str[i]))
		i++;
	if (str[1] == '-')
	{
		if (str[i] != 0)
			ft_putchar(str[i]);
		if (str[i] == 0 && s1 && (*y += 1))
			ft_putstr(s1);
		 ft_putstr(pad);
		if (str[i])
			ft_putstr(&str[i + 1]);
	}
	else
	{
		ft_putstr(pad);
		if (str[i])
			ft_putstr(&str[i]);
		else if (s1 && !str[i] && (*y += 1))
			ft_putstr(s1);
	}
	ret = ft_strlen((str[i]) ? &(str[i]) : s1) + ((pad) ? ft_strlen(pad) : 0);
	free(pad);
	// printf("y = %d", *y);
	return (ret);
}

size_t	ft_putonlystring(char **tab)
{
	int		i;
	int		percent;
	size_t	ret;

	i = 0;
	ret = 0;
	percent = 0;
	while (tab[i] && tab[i][0])
	{
		percent = 0;
		if (tab[i][0] != '%')
		{
			ft_putstr(tab[i]);
			ret += ft_strlen(tab[i]);
		}
		if (tab[i][0] == '%' && tab[i][1] != 0)
		{
			ret += ft_putnotsyntax(tab[i], tab[i + 1], &i);
			if (tab[i][1] == '-' && tab[i + 1])
				i += 1;
			percent++;
		}
		else if (tab[i][0] == '%' && !tab[i][1])
		{
			while (tab[i] && tab[i][0] == '%' && tab[i][1] == 0)
			{
				percent++;
				i++;
			}
			i--;
			// printf("%i", (percent + 1) % 2);
			ft_putstr(((percent + 1) % 2 == 0) ? tab[i] : "%");
			ret += ((percent + 1) %2 == 0) ? ft_strlen(tab[i]) : 1;
		}
		if (tab[i])
			i++;
	}
	// printf("ret = %zu\n", ret);
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
			if (list->special == 0 && list->buflen != 0)
				list->buf[list->buflen - 1] = 0;
			ret += ft_print_n_uni_str(list->buf, ft_strlen(list->buf));
			if (list->special == 0 && (ret += 1))
				ft_putchar('\0');
			temp = ft_rest(tab[i]);
			ret += ft_strlen(temp);
			ft_putstr(temp);
			// free(list->buf);
			list = list->next;
		}
		else
			ret += ft_print_n_uni_str(tab[i], ft_strlen(tab[i]));
		i++;
	}
	return (ret);
}