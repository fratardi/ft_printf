/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_str_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:05:38 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/28 18:38:03 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t	ft_uni_str_len(char *str)
{
	size_t ret;

	ret = 0;
	if (!str | !*str)
		return (0);
	while (str[ret])
		ret += ft_uni_char_len(&str[ret]);
	return (ret);
}
