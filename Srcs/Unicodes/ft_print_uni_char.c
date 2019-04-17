/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:42:32 by fratardi          #+#    #+#             */
/*   Updated: 2019/03/22 18:44:51 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t	ft_print_uni_char(char *str)
{
	size_t	ret;

	ret = ft_uni_char_len(str);
	if (ret)
		write(1, str, ret);
	return (ret);
}
