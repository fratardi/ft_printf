/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:03:52 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/06 18:00:28 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main(void)
{
    printf("_%d_", ft_printf("%17.9d et %% et %0$u %20s et %12y %1.4f %O %U", 42, "string",1.2f, 42, 42));
    printf("_%d_", printf("\n%17.9d et %% et %0$u %20s et %12y %1.4f %O %U", 42, "string", 1.2f, 42, 42));
/*     ft_printf("test %s %s %s modifs\n", "1", "2", "3");
    ft_printf("test %2$*.*s modifs\n", "test");
    ft_printf("test %2$.15s modifs\n", "test");
    ft_printf("test %2$.15x modifs\n", 42);
    ft_printf("test %2$.15d modifs\n", 42);
    ft_printf("test %d modifs\n", 42);
    ft_printf("test %o modifs\n", 42);
    ft_printf("test %0$u error\n", 42);
    ft_printf("test %% mod\n", 42);
    ft_printf("%10d\n", 15); */
    return (0);
}