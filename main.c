/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:03:52 by tpacaud           #+#    #+#             */
/*   Updated: 2019/07/31 15:30:44 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main(void)
{
    ft_printf("test %s modifs\n", "test");
    ft_printf("test %2$*.*s modifs\n", "test");
    ft_printf("test %d modifs\n", "test");
    ft_printf("test %o modifs\n", "test");
    ft_printf("test %0$u modifs\n", "test");
    ft_printf("test %% modifs\n", "test");
    return (0);
}