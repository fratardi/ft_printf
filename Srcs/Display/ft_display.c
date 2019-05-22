/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:50:13 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/22 15:59:47 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t ft_sequence(char *str, int *open, char *s1)
{
	size_t ret;
	char *temp;
	char *pad;
	int i;
	t_no_syntax content;

	ret = 0;
	i = 1;
	content.extra = 0;
	content.left = 0;
	
	
	
	pad =NULL;
	
	
	
	// printf("\nsequence = %s\n", str);
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
	//ft_putnbr(content.width);
	while (ft_strchr(".1234567890", str[i]) && str[i])
		i++;
	// printf("\ns1 %s str %s\n", s1, &str[i]);
	if ((s1 && s1[0]) || str[i])
		temp = (str[i]) ? ft_strdup(&str[i]) : ft_memaset(s1[0], 1);
	else
		temp = ft_strdup("");
	if (!str[i])
		*open = 0;
	 //printf("temp = %s et left = %d\n", temp, content.left);
	if (content.width)
	{
		pad = ft_memaset((content.extra) ? '0' : ' ', content.width);
	
	//	printf("ici");//
	}	
	else
		 pad =ft_strdup("");
	if (content.left)
	{
		pad = ft_joinfree(ft_strndup(temp, 1), pad);
		pad = ft_joinfree(pad, ft_strdup(&temp[1]));
		free(temp);
		temp = pad;
	}
	else
		temp = ft_joinfree(pad, temp);
	if (temp)
		ret += ft_print_uni_str(temp);
	if (!str[i] && s1 && s1[0])
		ret += ft_print_uni_str(&s1[1]);
	// printf("\n<<%s\n", temp);
	free(temp);
	return (ret);
}
/* 

size_t ft_putonlystring(char **tab   ,   int param)
{
	size_t ret;
	ret = 0;
	while(tab[i])
	{
		if(param == 1)
		{
			ft_sequence(tab[i]);
		}
		else
			ft_print_uni_str(tab[i]);
		i++;
		if(param == 1)
		if(param)

			param = 0;
	}
	return(ret);
}
 */

size_t ft_putonlystring(char **tab)
{
	size_t ret;
	// size_t temp;
	int open;
	int i;

	open = 0;
	i = 0;
	ret = 0;
	if ((tab[i][0] == '%' && !tab[i + 1] && !tab[i][1]))
			return (0);
		while (tab[i])
	{
		if (tab[i][0] == '%' && open == 0)
			open = 1;
/* 		else if (tab[i][0] == '%' && open == 1)
			open = 0; */
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

/* int ft_percent(char **tab, int i, size_t *ret)
{
	int percent;

	percent = 0;
	if(tab[0][0] == '%' && !tab[1] && !tab[0][1])
		return (i++);
	if (tab[i][0] != '%')
	{
		*ret += ft_print_uni_str(tab[i]);
		// ret += ft_strlen(tab[i]);
	}
	if (tab[i][0] == '%' && tab[i][1] != 0)
	{
		*ret += ft_putnotsyntax(tab[i], tab[i + 1], &i, tab[i + 2]);
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
		ft_putstr(((percent + 1) % 2 == 0) ? tab[i] : ft_memaset('%', (percent + 1) / 2));
		*ret += ((percent + 1) % 2 == 0) ? ft_strlen(tab[i]) : (percent + 1) / 2;
	}
	return (i);
} */

/* size_t ft_putonlystring(char **tab)
{
	int i;
	size_t ret;

	i = 0;
	ret = 0;
	while (tab[i] && tab[i][0])
	{
		i = ft_percent(tab, i, &ret);
		if (tab[i])
			i++;
	}
	// printf("ret = %zu\n", ret);
	return (ret);
} */

size_t ft_display(char **tab, t_printinfo *list)
{
	size_t i;
	size_t ret;
	char *temp;

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
