/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:06:32 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/03 13:04:10 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*rez;
	size_t		i;

	i = 0;
	if (!(rez = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	ft_bzero(rez, size + 1);
	return (rez);
}
