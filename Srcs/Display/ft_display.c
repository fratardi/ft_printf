/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:50:13 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/23 06:36:42 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t		ft_sequence(char *str, int *open, char *s1)
{
	size_t		ret;
	char		*temp;
	char		*pad;
	int			i;
	t_no_syntax	content;

	ret = 0;
	i = 1;
	content.extra = 0;
	content.left = 0;
	pad = NULL;
	while (ft_strchr("-+ 0#", str[i]) && str[i])
	{
		if (str[i] == '-')
			content.left = 1;
		if (str[i] == '0')
			content.extra = 1;
		i++;
	}
	content.width = ft_atoi(&str[i]);
	content.width -= (content.width) ? 1 : 0;
	while (ft_strchr(".1234567890", str[i]) && str[i])
		i++;
	if ((s1 && s1[0]) || str[i])
		temp = (str[i]) ? ft_strdup(&str[i]) : ft_memaset(s1[0], 1);
	else
		temp = ft_strdup("");
	if (!str[i])
		*open = 0;
	if (content.width)
		pad = ft_memaset((content.extra) ? '0' : ' ', content.width);
	else
		pad = ft_strdup("");
	if (content.left)
		temp = ft_joinfree(temp, pad);
	else
		temp = ft_joinfree(pad, temp);
	if (temp)
		ret += ft_print_uni_str(temp);
	if (!str[i] && s1 && s1[0])
		ret += ft_print_uni_str(&s1[1]);
	free(temp);
	return (ret);
}

size_t		ft_putonlystring(char **tab)
{
	size_t	ret;
	int		open;
	int		i;

	open = 0;
	i = 0;
	ret = 0;
	if ((tab[i][0] == '%' && !tab[i + 1] && !tab[i][1]))
		return (0);
	while (tab[i])
	{
		if (tab[i][0] == '%' && open == 0)
			open = 1;
		if (open == 1)
		{
			ret += ft_sequence(tab[i], &open, tab[i + 1]);
			if (open == 0)
				i++;
		}
		else if (open == 0)
			ret += ft_print_uni_str(tab[i]);
		i++;
	}
	return (ret);
}

size_t		ft_display(char **tab, t_printinfo *list)
{
	size_t	i;
	size_t	ret;
	char	*temp;

	i = 0;
	ret = 0;
	if (onlystring(tab) == 1)
		return (ft_putonlystring(tab));
	while (tab[i])
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
			ft_print_uni_str(temp);
			list = list->next;
		}
		else
			ret += ft_print_n_uni_str(tab[i], ft_strlen(tab[i]));
		i++;
	}
	return (ret);
}
