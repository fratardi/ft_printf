/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:03:52 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/12 03:50:23 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <time.h>

int main(void)
{
		// printf("aa%%bb\n");
		// ft_printf("%*.*d || % $0$d\n", 15, 2, 4,5,6);
		// ft_printf("test %3$*.*d\n", 15, 2, 4,5,6);
		// ft_printf("%10s %15d", "test", 1);
		    // ft_printf("%10s %15d %2$*.*o %X %2$o %5$2.*f %u %p\n", "test", 0x1, 2, 3, 4, 12.54f, 19, "test");
		    // printf("%10s %15d %2$*.*o %X %2$o %5$.*f %u %p", "test", 0x1, 2, 3, 4, 12.54f, 19, "test");
		ft_printf("{%#.o}\n", 42, 2);
		printf("{%#o}\n", 42, 2);
        // ft_printf("%2$d %3$*.")
		//printf("%*.*f\n");
    // printf("_%d_", ft_prin \tf("%17.9d et %% et %0$u %20s et %12y %1.4f %O %U", 42, "string",1.2f, 42, 42));
    // printf("_%d_", printf("\n%17.9d et %% et %0$u %20s et %12y %1.4f %O %U", 42, "string", 1.2f, 42, 42));
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
    // while(1);
    return (0);
}