/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/07 18:58:58 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"
#include <stdio.h>

/* Main de tests - Tout les commentaires sont a implémenter, ils segfaults ou ne fontionnent pas */

int main(void)
{
	 ft_printf("%#s%c\n %o%#x%#X%lld%f%Lf", "test", '*', 41, 40, 39, 38, 12.5, 1.3L);
	   
	 ft_putendl("\nprintf original below\n");
	 printf("%#s\n%c\n%o\n%#x\n%#X\n%lld\n%f\n%Lf\n", "test", '*', 41, 40, 39, 38, 12.5, 1.3L);
//	printf("\n%#x\n", 123.456);

	return (0);
}
