/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:22:21 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/22 15:59:52 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char	*ft_exception(long double a, t_printinfo *list)
{
	int ex;
	char *m;
	char *inf;

	ex = ft_expldouble(a);
	//printf("exeption = %i\n", ex);
	if (ex >= -16383)
		return (NULL);
/* 	// else if (ex >= -1023 && !list->is_long_double)
		// return (NULL); */
	m = ft_mantissaldouble(a);
	inf = ft_memaset('0', (list->is_long_double) ? 64 : 31);
	if (ft_strcmp(inf, m) == 0)
	{
		free(m);
		free(inf);
		return (ft_strdup((a < 0) ? "-Inf" : "+Inf"));
	}
	else if (ft_strcmp(inf, m) != 0)
	{
		free(inf);
		free(m);
		return (ft_strdup("nan"));
	}
	free(inf);
	free(m);
	return (ft_strdup("nan"));
}