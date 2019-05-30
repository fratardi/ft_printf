/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/30 02:52:38 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
	// ft_printf("%X %12o %5s %x %d qdaze %c", -123, -432, "okqsd", 5643, 123654, 'S');
	// printf("%X %12o %5s %x %d qdaze %c", -123, -432, "okqsd", 5643, 123654, 'S');

/* 	ft_printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	printf("\n<<\n>>\n");
    printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
 */
	// ft_printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	// printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');

	/* ft_printf("%X %o %s %5x %d qdaze %5c \n %c %X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	printf("\n<<\n>>\n");
	printf("%X %o %s %5x %d qdaze %5c \n %c %X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
 */
    ft_printf("%05s\n", "abc");
    printf("%05s\n", "abc");
    
    return (0);
}
