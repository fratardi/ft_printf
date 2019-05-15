/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/15 19:38:50 by tpacaud          ###   ########.fr       */
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

 ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
	// ft_printf(">> %d\n", (ft_printf("%5%lld ksdjhf kjsdh fkjsd hf\n", -2147483647)));
	// printf("%5%\n");
	//ft_printf("%01s", "123");
	//ft_printf("%05s", "123");
	//ft_printf("%5%");
	//tests();

	return (0);
}
