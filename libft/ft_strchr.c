/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:43:04 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/21 22:13:38 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = (char*)s;
	i = 0;
	while (*(tmp + i))
	{
		if (*(tmp + i) == c)
			return (tmp + i);
		i++;
	}
	if (*(tmp + i) == c)
		return (tmp + i);
	return (NULL);
}
