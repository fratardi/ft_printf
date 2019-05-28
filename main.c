/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 16:29:09 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
	// t_list *list;

	// ft_neg_pow_of_two(list, 10);
	// printf("%s\n", list->content);
	ft_printf("res >> %.5000Lf\n", 1.0E-4500L);
	// printf("res >> %.5000Lf\n", 1.0E-4500L);
	return (0);
}
