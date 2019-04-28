/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:35:55 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/28 13:58:55 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putnstr(char const *s, size_t size)
{
	int i;
	size_t len;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (0);
	write(1, s, (len >= size) ? len : size);
	return(len >= size ? len : size);
}
