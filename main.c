/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:03:52 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/31 17:47:35 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <time.h>
#include <float.h>
#include <stdio.h>

#define WHILE while(1);


int main(void)
{
    // ft_printf("%o\n", 0);
    // ft_printf("% o\n", 0);
    // ft_printf("%+o\n", 0);
    // ft_printf("%-o\n", 0);
    // ft_printf("%0o\n", 0);
    // ft_printf("%#o\n", 0);
    // ft_printf("%10o\n", 0);
    // ft_printf("%.6o\n", 0);
    // ft_printf("%hho\n", 0);
    // ft_printf("%llo\n", 0);
    // ft_printf("%ho\n", 0);
    // ft_printf("%lo\n", 0);
    // ft_printf("%jo\n", 0);
    // ft_printf("%zo\n", 0);
    // ft_printf("%#10.10o\n", 0);
    // ft_printf("%#1.o\n", 0);
    // ft_printf("%#.o\n", 0xff);
    // ft_printf("%#.0o\n", 0xff);
    // ft_printf("%#.1o\n", 0xff);
    // ft_printf("%#.1o\n", 0);
    ft_printf("%#.3o\n", 11);
    // ft_printf("% 0+-#10.5llo\n", 42);


	// ft_printf( "copy%hh\n%d\n%d\n", 1 , 2 );
	// printf( "original%hh\n%d\n%d\n", 1 , 2 );

/*

	ft_printf("b'% 010u\n", 0);
	printf("b'% 010u\n", 0);

*/
    //    ft_printf("bonjour\n");
		//   printf("\norig\n%1$d\n%2$d\n%1$d\n", 1 , 2 ,3,4,5,6,7,8,9,10,11,12);
		//ft_printf("\ncopy\n%1$d\n%2$d\n%1$d\n" , 1 , 2 , 3,4,5,6,7,8,9,10,11,12);
		
	    //	printf("\norig%2-12$s %2$s %1$s\n"  "1" , "2" , "3");
/*		ft_printf(">>%2$-15s\n", "A", "B");
	    ft_printf("\ncopy%2$-15s %2$s  %1$s",  "A" , "B" , "C");
		   printf("\norig%2$-15s %2$s  %1$s",  "A" , "B" , "C");
*/
/*
	while(i++ <100)
{
    if(printf("o'%o\n'", i) ==ft_printf("c'%o\n'", i))
		printf("\nsucces\n");		
	if(printf("o'%+o\n'", i) == ft_printf("c'%+o\n'", i))
		printf("\nnsucces\n");
	if(printf("o'%-o\n'", i) == ft_printf("c'%-o\n'", i))
		printf("\nsuccess\n");
	if((printf("o'%.0o\n'", i)) == ft_printf("c'%.0o\n'", i))	
		printf("\nsuccess\n");
	if(printf("o'%.1o\n'", i) ==ft_printf("c'%.1o\n'", i))
		printf("\nsuccess\n");
	if(printf("o'%.2\n'", i) == ft_printf("c'%.2\n'", i))
		printf("\nsuccess\n");
	if(printf("o'% 0+-#10.5llo\no\n'", i) == ft_printf("c'% 0+-#10.5llo\no\n'", i))
		printf("\nsuccess\n");
}
	printf("\nendtests\n");
*/
/*
*/
	//ft_printf("%3$d %2$d %1$d" , 1 , 2 , 3, 5);		

	// char *s = "t";
		// ft_exp_ldouble(-111111111111111.2222222222222L);
		// ft_exp_ldouble(111111111111111.2222222222222L);
		// ft_printf("%Lf\n", -111111111111111.2222222222222L);
//		printf("%Lf\n", -111111111111111.2222222222222L);
//		ft_printf("%Lf\n", 111111111111111.2222222222222L);
	//	printf("%Lf\n", 111111111111111.2222222222222L);
	//	ft_printf("%Lf\n", 0.125L);
		// ft_printf("%Lf\n", 1024.0L);
/* 		printf("bin = %d\n", ft_binary_exopnent("011111111111111"));
		printf("same - %d\n", ft_same("test", "test"));
		printf("not same - %d\n", ft_same("test", "none"));
		printf("not same - %d\n", ft_same("test", "testing"));
        				char 	*j = s;
                printf("P 015  = [%015p] yo\n", s);
                ft_printf("P 015  = [%015p] yo\n", s);//!!!!!!!!!!!!!!!!!!!!!!
                printf("\n");
                printf("P 015 = [%015p] yo\n", s);
                ft_printf("P 015 = [%015p] yo\n", s);
                printf("\n");
                printf("P -.015 = [%.-015p] yo\n", s);
                ft_printf("P -.015 = [%.-015p] yo\n", s);
                printf("\n");
 */
 
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
	// printf("%pruc%+3+719-5$-+603.4s\n", "un", "deux", "trois", "quatre", "cinq");
	// ft_printf("%pruc%+3+719-5$-+603.4s\n", "un", "deux", "trois", "quotre", "cinq");



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
  //ft_printf("test %2$.15s modifs\n", "test");
 /*ft_printf("b'%-01s\\n', b''\n", "");
 printf("b'%-01s\\n', b''\n", "");
*/
 
//  ft_printf("test %2$*.*s modifs\n", "test",1,2,"test",64);
//  printf("test %2$*.*s modifs\n", "test",1,2,"test",64);
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
