/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:22:21 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/30 19:45:51 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char	*ft_exception(long double a, t_printinfo *list)
{
	int		ex;
	char	*m;
	char	*inf;

	ex = ft_expldouble(a);
	if (ex >= -16383 && ex <= 16383)
		return (NULL);
	m = ft_mantissaldouble(a);
	list->is_char = 0;
	inf = ft_memaset('0', 63);
	if (ft_strcmp(inf, m) == 0)
	{
		free(m);
		free(inf);
		return (ft_strdup((a < 0) ? "-inf" : "inf"));
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
