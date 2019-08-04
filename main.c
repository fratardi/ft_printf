/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:03:52 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/04 21:24:01 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main(void)
{
    ft_printf("test %s modifs\n", "test");
    ft_printf("test %2$*.*s modifs\n", "test");
    ft_printf("test %d modifs\n", 42);
    ft_printf("test %o modifs\n", 42);
    ft_printf("test %0$u modifs\n", 42);
    ft_printf("test %% modifs\n", 42);
    return (0);
}