/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:42:47 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/11 21:27:30 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

/*
**Funtion to properly join two string
*/

char			*ft_join(char *s1, char *s2)
{
	char *temp;

	if (s1)
	{
		temp = ft_strdup(s1);
		free(s1);
		s1 = ft_strjoin(temp, s2);
		free(temp);
	}
	else
		s1 = ft_strdup(s2);
	return (s1);
}

/*
**Return the rest of the string
*/

char			*ft_rest(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_strchr("diouxXcfsp", str[i]) == NULL)
		i++;
	i++;
	return (&str[i]);
}

/*
**If tab is a syntax, function fill print_info
*/

t_printinfo		*ft_ifissyntax(char **tab, int i, t_printinfo *list)
{
	// list = ft_initlist(list);
	ft_fillzerolist(list);
	list = ft_fillndol(tab[i], list);
	list = ft_fillprec(tab[i], list);
	list = ft_fillflag(tab[i], list);
	list = ft_fillwidth(tab[i], list);
	list = ft_fillmod(tab[i], list);
	list = ft_filltype(tab[i], list);
	if (!(list->next = (t_printinfo*)malloc(sizeof(t_printinfo))))
		exit(0);
	list->next->next = NULL;
	list = list->next;
	return (list);
}

/*
**Distribute to ifsyntax or fill to_print
*/

t_printinfo		*ft_annex(char **tab, int i, t_printinfo *list)
{
	if (ft_issyntax(tab[i]) == 1)
		list = ft_ifissyntax(tab, i, list);
	else
	{
		if (tab[i + 1] && ft_issyntax(tab[i]) == 1)
		{
			if (!(list->next = (t_printinfo*)malloc(sizeof(t_printinfo))))
				exit(0);
			list->next->next = NULL;
			list = list->next;
		}
	}
	return (list);
}

/*
**Create and fill struct printinfo
*/

t_printinfo		*ft_fillstruct(char **tab)
{
	int			i;
	t_printinfo *list;
	t_printinfo *start;

	i = 0;
	if (!(list = (t_printinfo*)malloc(sizeof(t_printinfo))))
		exit(0);
	list->next = NULL;
	start = list;
	while (ft_issyntax(tab[i]) == 0)
	{
		i++;
	}
	if (ft_issyntax(tab[i]) == 1)
	{
		list = ft_ifissyntax(tab, i, list);
		i++;
	}
	while (tab[i])
	{
		list = ft_annex(tab, i, list);
		i++;
	}
	return (start);
}
