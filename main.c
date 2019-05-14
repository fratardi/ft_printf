/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/14 22:37:51 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"
#include <stdio.h>

/* Main de tests - Tout les commentaires sont a implémenter, ils segfaults ou ne fontionnent pas */

/*
void	*ft_memaset(int c,size_t n)
{
	unsigned char *ret;

	if(!(ret = (unsigned char*)ft_memalloc(n + 1)))
		return(NULL);
	ret = ft_memset(ret, c, n);
	return(ret);
}


*/
int main(void)
{
	char *str;

	str = "test";
	 //ft_printf("%#s%c\n %o%#x%#X%lld%f%Lf%#Lf", "test", '*', 41, 40, 39, 38, 12.5, 1.3L, 123.456L);
	   
//	 ft_putendl((char *)ft_memaset('b',0));
	 //printf("%#s\n%c\n%#o\n%#x\n%#X\n%lld\n%f\n%Lf\n%#LF\n", "test", '*', 41, 40, 39, 38, 12.5, 1.3L, 123.456L);
//	printf("\n%#x\n", 123.456);
//	printf("%#012x\n",4242);
//ft_printf("%#012x\n", 4242);
	// ft_debugf();	

	ft_printf("no_syntax %5% %d %f %u %x %X %o %p %s %c", 12, 1.0625, 12, 42, 42, 42, str, str, 42);
	// ft_printf(">> %d\n", (ft_printf("%5%lld ksdjhf kjsdh fkjsd hf\n", -2147483647)));
	// printf("%5%\n");
	//ft_printf("%01s", "123");
	//ft_printf("%05s", "123");
	//ft_printf("%5%");
	//tests();

	return (0);
}
