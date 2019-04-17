/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:45:46 by fratardi          #+#    #+#             */
/*   Updated: 2019/03/24 23:50:53 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t	ft_print_uni_str(char *str)
{
	size_t	ret;

	ret = ft_uni_str_len(str);
	if (ret)
		write(1, str, ret);
	return (ret);
}
