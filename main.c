/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 13:26:04 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
	char *str;
	str = ft_strdup("0075");
	ft_addstrings_stack(str, "075", 3, 1);
	printf(">>%s\n", str);
	return (0);
}
