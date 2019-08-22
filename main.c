/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:03:52 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/18 06:23:46 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <time.h>
#include <float.h>
#include <stdio.h>
int main(void)
{
 
 //float f;
	
	//f = 1.0f;

	//while (   f++ )	
	//	{
		//	ft_putendl("<<orig");
		//	ft_displaybin(&f, sizeof(float));
			//ft_putendl("<<copy");
			//ft_printf("%Ef\n",123.456E-35);

//ft_putstr("\ncopy>>\n");

//ft_putnbr(ft_printf("b'%-0#28h%\\n'"));
//ft_printf("\n>>%d<<\n",/*ft_*/ft_printf("b'%-3$-0#28hs%\\n'","un", "deux", "trois"));
//ft_putendl("\norig>>");
		//	printf( "%4E\n",294807462971541824);
	//	}
 /*
t_print_info ft_print_sequence(const char *format, size_t pos)
{
	t_print_info ret;

	init_print_info(&ret);
	if(!str[pos]) 
		return(ret); 
	while(str[pos]!= 0 || str[pos]!= '%')
	{

	}
	*/
//	ft_putnbr(atoi("+-4556"));
ft_printf("%/$+603.4s", "un", "deux", "trois", "quatre", "cinq");



 /*
    	double		nb;

    nb = 12.13;
	ft_printf("%f\n", nb);
	ft_printf("%12f\n", nb);
	ft_printf("%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	printf("%f\n", nb);
	printf("%12f\n", nb);
	printf("%-12f\n", nb);
	printf("%5.9f\n", nb);
*/
/*     nb = -1.0/0.0;
	ft_printf("%f\n", nb);
	printf("%f\n", nb);
	ft_printf("%12f\n", nb);
	printf("%12f\n", nb);
	ft_printf("%-12f\n", nb);
	printf("%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	printf("%5.9f\n", nb); */
/* 
 	nb = 0.0/0.0;
	ft_printf("%f\n", nb);
	printf("%f\n", nb);
	ft_printf("%12f\n", nb);
	printf("%12f\n", nb);
	ft_printf("%-12f\n", nb);
	printf("%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	printf("%5.9f\n", nb); */


		// printf("aa%%bb\n");
	//	ft_printf("%*.*d || % $0$d\n", 15, 2, 4,5,6);
	//	 ft_printf("test %3$*.*d\n", 15, 2, 4,5,6);
	//	 ft_printf("%10s %15d", "test", 1);
		 //    printf("%10s %15d %2$*.*o %X %2$o %5$2.*f %u %p\n", "test", 0x1, 2, 3, 4, 12.54f, 19, "test");
//		     printf("%10s %15d %2$*.*o %X %2$o %5$.*f %u %p", "test", 0x1, 2, 3, 4, 12.54f, 19, "test");
/*
ft_printf("{%*3d%2$d}\n", 5, 0);
printf("{%*3d%2$d}\n", 5, 0);
*/
  //   ft_printf("{%05.*d}\n", -15, 42);
    // printf("{%05.*d}\n", -15, 42);
/*     ft_printf(">------------<%#42.2zo>------------<\n", 0);
    printf(">------------<%#42.2zo>------------<\n", 0);
    ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
    printf("@moulitest: %#.o %#.0o\n", 0, 0);
    ft_printf("%#040.2o\n", 0);
    printf("%#040.2o\n", 0); */
  // ft_printf("%f\n", 0.0f);
   // printf("%f\n", 0.0f);
    //     ft_printf("%2$d %3$*.");
		//printf("%*.*f\n");
    // printf("_%d_", ft_prin \tf("%17.9d et %% et %0$u %20s et %12y %1.4f %O %U", 42, "string",1.2f, 42, 42));
    // printf("_%d_", printf("\n%17.9d et %% et %0$u %20s et %12y %1.4f %O %U", 42, "string", 1.2f, 42, 42));
 //  ft_printf("test %s %s %s modifs\n", "1", "2", "3");
 //printf("test %2$*.*s modifs\n", "test",1,2,3,64);
  //  printf("test %2$*.*s modifs\n", "test");
  //ft_printf("test %2$.15s modifs\n", "test");
    //ft_printf("test %2$.15x modifs\n", 42);
    //ft_printf("test %2$.15d modifs\n", 42);
    //ft_printf("test %d modifs\n", 42);
    //ft_printf("test %o modifs\n", 42);
    // ft_printf("%+Lf\n", -123456.123456L);
    // printf("%+Lf\n", -123456.123456L);
 //   ft_printf("%28.8lf\n", 16.125);
   // printf("%28.8lf\n", 16.125);
    //  printf("%Lf\n", LDBL_MAX - 1);
    // ft_putendl(ft_pow_pos(1200, 0));
  //  ft_printf("test %% mod\n", 42);
   // ft_printf("%10d\n", 15); 
    // while(1);
    return (0);
}
