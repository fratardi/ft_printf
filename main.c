/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/24 14:56:20 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
//	printf("orig>> %100f\n", 0.00000045669F);
	// ft_printf("nous>> %U\n", 5136, 12);
	unsigned int i = 0;
	
	ft_printf("%#0.0f\n", i);
	printf("%#0.0f\n",i);
	return (0);
}
