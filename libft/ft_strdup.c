/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:12:51 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/03 13:05:28 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*rez;
	int		i;

	i = 0;
	if (!(rez = (char *)malloc(sizeof(char ) * ft_strlen(s1) + 1)))
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		rez[i] = *(s1 + i);
		i++;
	}
	rez[i] = '\0';
	return (rez);
}
