/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/30 19:54:51 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
    double		nb;

    nb = 1.0/0.0;
	// ft_printf("%f\n", nb);
	// printf("%f\n", nb);
	// ft_printf("%12f\n", nb);
	// printf("%12f\n", nb);
	// ft_printf("%-12f\n", nb);
	// printf("%-12f\n", nb);
	// ft_printf("%5.9f\n", nb);
	// printf("%5.9f\n", nb);

    nb = -1.0/0.0;
	// ft_printf("%f\n", nb);
	// printf("%f\n", nb);
	// ft_printf("%12f\n", nb);
	// printf("%12f\n", nb);
	// ft_printf("%-12f\n", nb);
	// printf("%-12f\n", nb);
	// ft_printf("%5.9f\n", nb);
	// printf("%5.9f\n", nb);

	nb = 0.0/0.0;
	// ft_printf("%f\n", nb);
	// printf("%f\n", nb);
	// ft_printf("%12f\n", nb);
	// printf("%12f\n", nb);
	// ft_printf("%-12f\n", nb);
	// printf("%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	printf("%5.9f\n", nb);
    return (0);
}
