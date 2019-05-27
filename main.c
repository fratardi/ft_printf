/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/27 18:50:15 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void	bonus(void)
{
	ft_printf("n$ - inverse = %2$s %1$s\n", "1st_String", "2nd_String");
	ft_printf("Scientific = %Ef\n", 1.234567E-100);
	ft_printf("Binary (int) = %b\n", 1);
	ft_printf("Binary (str){hello} = %B\n", "hello");
	ft_printf("Octal Upper = %O\n", 42);
	ft_printf("Unsigned Upper = %U\n", 42);
	ft_printf("size_t = %zu\n", (size_t)42);
	ft_printf("Unicodes = 𝟜𝟚 et %s\n", "😀");
}


int main(void)
{
	bonus();
	ft_printf("<> %f\n", 2.4);
	// printf(">> %.5000Lf\n", 2.0E-4930L);
	return (0);
}