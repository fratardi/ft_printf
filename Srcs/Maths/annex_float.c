/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:06 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/27 15:46:24 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char	*ft_fillbig(char *s1, char *s2)
{
	while (ft_strlen(s1) < ft_strlen(s2))
		s1 = ft_strjoinfree(s1, ft_strdup("0"));
	return (s1);
}

void	ft_hexfloat(void *content, size_t n)
{
	char *tab;
	char *str;

	tab = ft_strdup("0123456789abcdef");
	str = (char *)content;
	ft_putstr("0x");
	while (0 < n--)
	{
		ft_putchar(tab[((unsigned char)str[n] / 16)]);
		ft_putchar(tab[((unsigned char)str[n] % 16)]);
	}
	free(tab);
}

size_t	digitlen(unsigned long long int i)
{
	size_t ret;

	ret = 0;
	while (i)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}
