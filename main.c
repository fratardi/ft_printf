/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 17:41:25 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
	// t_list *list;

	// ft_neg_pow_of_two(list, 10);
	// printf("%s\n", list->content);

ft_printf("%032.32hhd\n" , 3821480137);

printf("%032.32hhd\n" , 3821480137);

ft_printf("%032.32hhd\n" , 858883218);
printf("%032.32hhd\n" , 858883218);

ft_printf("^.^/%032.32hd^.^/\n" , 0);
printf("^.^/%032.32hd^.^/\n" , 0);

ft_printf("^.^/%032.32hd^.^/\n" , 1884346834);
printf("^.^/%032.32hd^.^/\n" , 1884346834);

ft_printf("^.^/%032.32hd^.^/\n" , 3140152908);
printf("^.^/%032.32hd^.^/\n" , 3140152908);

ft_printf("%032.32hd\n" , 0);
printf("%032.32hd\n" , 0);

ft_printf("%032.32hd\n" , 3614349460);
printf("%032.32hd\n" , 3614349460);

ft_printf("%032.32hd\n" , 1180447000);
printf("%032.32hd\n" , 1180447000);

ft_printf("^.^/%032.32lld^.^/\n" , 0);
printf("^.^/%032.32lld^.^/\n" , 0);


ft_printf("^.^/%032.32lld^.^/\n" , 2503068829);
printf("^.^/%032.32lld^.^/\n" , 2503068829);

ft_printf("%032.32lld\n" , 0);
printf("%032.32lld\n" , 0);

ft_printf("%032.32lld\n" , 2466705692);
printf("%032.32lld\n" , 2466705692);

	//ft_printf("res >> %.5000Lf\n", 1.0E-4500L);
	// printf("res >> %.5000Lf\n", 1.0E-4500L);
	return (0);
}
