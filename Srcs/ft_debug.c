/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:50:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/03/30 15:54:22 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fichier de Debug. Affiche le contenu de la 
	liste des syntax et les elements lus par va_arg	*/

#include "../Includes/ft_printf.h"
#include <stdio.h>

/* Fonction d'affichage du contenu de printinfo */

void ft_printdebuglist(t_printinfo *list, char **tab)
{
	int i;

	i = 0;
	while (list->next)
	{
		while (ft_issyntax(tab[i]) != 1)
			i++;
		printf("syntax = %s\n", tab[i]);
		i++;
		printf("n$ = %d\n", list->ndol);
		printf("alt = %d\n", list->alt);
		printf("space = %d\n", list->space);
		printf("zero = %d\n", list->extra);
		printf("group = %d\n", list->group);
		printf("showsign = %d\n", list->showsign);
		printf("width = %d\n", list->width);
		printf("prec = %d\n", list->prec);
		printf("left = %d\n", list->left);
		printf("ischar = %d\n", list->is_char);
		printf("isshort = %d\n", list->is_short);
		printf("is_long_double = %d\n", list->is_long_double);
		printf("is_long = %d\n", list->is_long);
		printf("type = %d\n", list->type);
		printf("to_print = %s\n", list->to_print);
		ft_putendl("");
		list = list->next;
	}
	printf("to_print = %s\n", list->to_print);
}

void	ft_debugelem(t_elem *elem)
{
	while(elem->next)
	{
		printf("%lld\n", elem->lli);
		elem = elem->next;
	}
}

/* Fonction principale
	PAR DEFAUT : affiche les elements lus par va_arg */

/* size_t ft_debug(const char *format, ...)
{
	char **tab;
	va_list va;
	t_printinfo *list;
	t_elem *elem;

	tab = ft_split_format(format);
	list = ft_fillstruct(tab);
	ft_modndol(list);
	va_start(va, format);
	elem = ft_varead(list, va, tab);
	va_end(va);
	// ft_printdebuglist(list, tab);
	printf("\n--------- ELEMENTS ELIPSE ---------\n\n");
	while (list->next)
	{
		while (elem->next && elem->pos < list->ndol)
			elem = elem->next;
		while (elem->previous && elem->pos > list->ndol)
			elem = elem->previous;
		if (list->type == 1 || list->type == 2)
			printf("elem = %d\n", elem->val);
		else if (list->type == 4)
			printf("elem = %s\n", elem->value);
		list = list->next;
	}
	return (0);
} */