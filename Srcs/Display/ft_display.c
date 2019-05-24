/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:50:13 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/24 14:45:55 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

int		ft_init_sequence(char *str, t_no_syntax *content)
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
	return (i);
}

size_t		ft_sequence(char *str, int *open, char *s1)
{
	size_t		ret;
	char		*temp;
	char		*pad;
	int			i;
	t_no_syntax	content;

	ret = 0;
	i = ft_init_sequence(str, &content);
	while (ft_strchr(".1234567890", str[i]) && str[i])
		i++;
	if ((s1 && s1[0]) || str[i])
		temp = (str[i]) ? ft_strdup(&str[i]) : ft_memaset(s1[0], 1);
	else
		temp = ft_strdup("");
	!str[i] ? (*open = 0) : 0;
	if (content.width)
		pad = ft_memaset((content.extra) ? '0' : ' ', content.width);
	else
		pad = ft_strdup("");
	temp = (content.left) ? ft_joinfree(temp, pad) : ft_joinfree(pad, temp);
	temp ? (ret += ft_print_uni_str(temp)) : 0;
	(!str[i] && s1 && s1[0]) ? (ret += ft_print_uni_str(&s1[1])) : 0;
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
		tab[i][0] == '%' && open == 0 ? (open = 1) : 0;
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

size_t		ft_display(char **tab, t_printinfo *l)
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
			l->special == 0 && l->buflen != 0 ? (l->buf[l->buflen - 1] = 0) : 0;
			ret += ft_print_n_uni_str(l->buf, ft_strlen(l->buf));
			(l->special == 0 && (ret += 1)) ? ft_putchar('\0') : 0;
			temp = ft_rest(tab[i]);
			ret += ft_strlen(temp);
			ft_print_uni_str(temp);
			l = l->next;
		}
		else
			ret += ft_print_n_uni_str(tab[i], ft_strlen(tab[i]));
		i++;
	}
	return (ret);
}
