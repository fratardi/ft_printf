/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/20 10:29:37 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

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

	str = "";
	//	char *str;
	//	int c1;
	//   double d = DBL_MAX;
	// double e = DBL_MIN;knlmkjml
	//  long double f = LDBL_MAX;
	//  long double g = LDBL_MIN;
	//  wchar_t c = L':pleurs_joie:';
	 int cpt1, cpt2;
	// long long j = LLONG_MAX;

	cpt2 = printf("R>> %hU", 4242);
	printf("\n");
	cpt1 = ft_printf("Y>> %hU", 4242);
	printf("\n");
	ft_printf("R{%i} Y{%i}\n",cpt1, cpt2);
	cpt2 = printf("R>> %u\n", 4294967296);
	cpt1 = ft_printf("Y>> %u\n", 4294967296);
	ft_printf("__%i %i\n",cpt1, cpt2);
	// printf(NULL);
	// ft_printf("%.p, %.0p", str, str);
	/* 	  ft_printf("{%0-3d}", 12);
	  printf("{%0-3d}", 12); */
	//ft_printf("%#s%c\n %o%#x%#X%lld%f%Lf%#Lf", "test", '*', 41, 40, 39, 38, 12.5, 1.3L, 123.456L);

	//	 ft_putendl((char *)ft_memaset('b',0));
	//printf("%#s\n%c\n%#o\n%#x\n%#X\n%lld\n%f\n%Lf\n%#LF\n", "test", '*', 41, 40, 39, 38, 12.5, 1.3L, 123.456L);
	//	printf("\n%#x\n", 123.456);
	// printf("%#012x\n",4242);
	// ft_printf("%#012x\n", 4242;)
	// ft_debugf();
	//    printf("%%%%%%%%%%");
	// printf("%2.20f\n", 12.3);
	// ft_printf("%2.20f\n", 12.3);
	// ft_printf("%%%%%%%%%%");

	//   ft_printf("%ju\n", 4999999999);
	//    printf("%ju\n", 4999999999);
	// ft_printf(">> %d\n", (ft_printf("%5%lld ksdjhf kjsdh fkjsd hf\n", -2147483647)));
	// printf("%5%\n");
	/* 	 ft_printf("%01s\n", "123");
		 printf("%01s\n", "123");
	c1 = ft_printf(str);
	printf("Return = %i\n", c1);
	printf(">> %Ef\n", 123456.5); */
	//ft_printf("%5%");
	//tests();

	//ft_printf("%#s%c\n %o%#x%#X%lld%f%Lf%#Lf", "test", '*', 41, 40, 39, 38, 12.5, 1.3L, 123.456L);
	/*
	str = "test\n";
  printf("original >> %.10000f\n", 2.22507385850720138309023271733240406421921598046233E-308);
  ft_printf("Nous >>%.50Ef\n", e);
 */
	//  ft_printf("%Lf\n", f);
	//   printf("%Lf\n", f);
	//   ft_printf("%.1500f\n", e);
	//   printf("%.1500f\n", e);
	//  cpt2 = ft_printf("%.4000Lf\n", 124.0000545);
	// cpt2 = printf("%.4000Lf\n", 124.0000545);
	//  ft_printf("%i || %i\n", cpt1, cpt2);

	return (0);
}
