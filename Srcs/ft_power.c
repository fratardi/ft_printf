/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:03:40 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/15 21:04:06 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* char *ft_add_forpow2neg(char *s1, char *s2)
{
	int s1p;
	int s2p;
	int i;
	char diff;
	char *temp;

	s1p = ft_strlen(s1);
	s2p = ft_strlen(s2);
	if (s1p <= s2p)
	{
		temp = s1;
		s1 = s2;
		s2 = temp;
		s1p = ft_strlen(s1);
		s2p = ft_strlen(s2);
	}
	diff = 0;
	while (s1p-- && s2p--)
	{
		s1[s1p] = ft_addchar(&s1[s1p], &s2[s2p]);
		diff = ft_diffaddchar(s1[s1p], s2[s2p]);
		if (diff && s1p)
		{
			i = 1;
			while (diff)
			{
				s1[s1p] = ft_addchar(&s1[s1p], &s2[s2p]);
				diff = ft_addchar(&s1[s1p - i++], "1");
			}
		}
		s1 = (s1p == 0) ? ft_strjoinfree(ft_strdup("1"), s1) : s1;
		diff = (s1p == 0) ? 0 : diff;
	}
	return (s1);
} */

char *ft_pow2neg(int po)
{
	char *temp;
	char *base;
	char *ret;
	size_t p;
	int i;

	p = (size_t)po;
	if (po == 0)
		return (ft_strdup("1"));
	if (po < 0)
		po = -po;
	po++;
	ret = ft_strdup("5");
	while (po > 1)
	{
		i = 4;
		base = ft_strdup(ret);
		while (i)
		{
			temp = ft_strdup(base);
			//printf("%s + %s = ", ret, temp);
			ret = ft_add_forpow2neg(ret, temp);
			//printf("%s\n", ret);
			i--;
		}
		free(base);
		po--;
	}
	//ree(&ret[0]);
	return (&ret[1]);
}