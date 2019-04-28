/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:45:46 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/28 16:15:10 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t ft_print_uni_str(char *str)
{
	size_t ret;

	if (!str)
		return (0);
	ret = ft_uni_str_len(str);
	if (ret)
		write(1, str, ret);
	return (ret);
}

int ft_print_n_uni_str(char *str, int size)
{
	int ret;

	if (!str)
	{
		ft_print_n_uni_str("(null)", size);
		return (size);
	}
	if (size < 0)
		return (0);
	ret = ft_uni_str_len(str);
	if (size == 0)
		size = (int)ret;
	if (ret)
		write(1, str, (ret >= size) ? size : ret);
	return (ret >= size ? size : ret);
}