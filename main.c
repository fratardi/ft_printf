/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 17:19:08 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
	// t_list *list;

	// ft_neg_pow_of_two(list, 10);
	// printf("%s\n", list->content);

ft_printf("%032.32hhd" , 3821480137);
/*
ft_printf("%032.32hhd" , 858883218);
ft_printf("^.^/%032.32hd^.^/" , 0);
ft_printf("^.^/%032.32hd^.^/" , 1884346834);
ft_printf("^.^/%032.32hd^.^/" , 3140152908);
ft_printf("%032.32hd" , 0);
ft_printf("%032.32hd" , 3614349460);
ft_printf("%032.32hd" , 1180447000);
ft_printf("^.^/%032.32lld^.^/" , 0);
ft_printf("^.^/%032.32lld^.^/" , 1100240104);
ft_printf("^.^/%032.32lld^.^/" , 2503068829);
ft_printf("%032.32lld" , 0);
ft_printf("%032.32lld" , 2466705692);
*/
	ft_printf("res >> %.5000Lf\n", 1.0E-4500L);
	// printf("res >> %.5000Lf\n", 1.0E-4500L);
	return (0);
}
