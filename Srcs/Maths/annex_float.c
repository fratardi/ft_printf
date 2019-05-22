/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:06 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/22 14:37:23 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char	*ft_fillbig(char *s1, char *s2)
{
	while (ft_strlen(s1) < ft_strlen(s2))
		s1 = ft_joinfree(s1, ft_strdup("0"));
	return (s1);
}

void	ft_hexfloat(void *content, size_t n)
{
	static char tab[16] = "0123456789abcdef";
	char *str;

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

