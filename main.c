/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:03:52 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/09 16:00:15 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <time.h>

int main(void)
{
		// printf("aa%%bb\n");
		// ft_printf("%*.*d || % $0$d\n", 15, 2, 4,5,6);
		// ft_printf("test %3$*.*d\n", 15, 2, 4,5,6);
		ft_printf("%2$*.*d || %1$d %2$d\n", 15, 7, 4,5,444, 444,555);
        printf("%2$*.*d || %1$d %2$d\n", 15, 7, 4,5,444, 444,555);
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
    return (0);
}