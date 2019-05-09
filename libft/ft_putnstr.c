/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:35:55 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/09 21:38:11 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putnstr(char const *s, int size)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (!s || size < 0)
		return (0);
	write(1, s, (len >= size) ? size : len);
	return (len >= size ? size : len);
}
