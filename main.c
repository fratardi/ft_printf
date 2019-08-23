#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>
#include <float.h>

int             main(int ac, char **av)
{
/*	printf(av[1]);
	ft_printf(av[1]);
	return (0);
*/

	 ft_printf("[% -5d]\n", 1560133635);
	 printf("[% -5d]\n", 1560133635);


	int d = 53431;
	unsigned int u = 151354;
	ft_printf("%D ettt %D et %U et %10U\n", d, d, u, u);
	printf("%D ettt %D et %U et %10U\n", d, d, u, u);

	printf("%o %O %U\n", d, -54122, -4572);
	ft_printf("%o %O %U\n", d, -54122, -4572);




	printf("LL = %d\n ULL= %d\n L= %d\n", sizeof(long long), sizeof(unsigned long long), sizeof(long));
	printf("%llu\n", ULLONG_MAX);
	printf("%lld\n", LLONG_MAX);
	printf("%lld\n", LLONG_MIN);
	printf("%ld\n", LONG_MIN);
	printf("%ld\n", LONG_MAX);
	ft_printf("%llu\n", ULLONG_MAX);  /// affiche uint_max
	ft_printf("%lld\n", LLONG_MAX);
	ft_printf("%lld\n", LLONG_MIN);
	ft_printf("%ld\n", LONG_MIN);
	ft_printf("%ld\n", LONG_MAX);
	printf("f1 = %lf\n", (float)1/3);
	ft_printf("f1 = %lf\n", (float)1/3);
	printf("f2 = %f\n", (float)-1/3);
	ft_printf("f2 = %f\n", (float)-1/3);

	printf("\n");
	long double f = -18446744073709551615.00;

	printf("P = cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	ft_printf("M = cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);

	printf("P = cc%#.4X et %-#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	ft_printf("M = cc%#.4X et %-#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	
	ft_printf("%b\n", 2);
	printf("%b\n", 2);
	ft_printf("%.63Lf\n", f);
	printf("%.63Lf\n", f);



     printf("the maximum value of long long = %llu\n", ULLONG_MAX);
	printf("ici etienne  %*d\n", 5, 42);
	ft_printf("ici etienne  %*d\n", 42, 5);

	printf("ici 222 %.*d\n", 5, 42);
	ft_printf("ici 222 %.*d\n", 42, 5);

	printf("la %*.5s\n", 15, "bonjour");
	ft_printf("la %*.5s\n", 15, "bonjour");
	printf("la %.*s\n", 5, "bonjour");
	ft_printf("la %.*s\n", 5, "bonjour");

	printf("here %*c\n", 5, 'c');
	ft_printf("here %*c\n", 5, 'c');

	int v[5] = {2, 2, 2, 2, 2};
	ft_printf("[%20B]\n", &v);

	int b = 0;
	int ret = 0;
	int x = 0; 
	ret = ft_printf("bonjour les gens %n ca va %d  %n\n", &b, b, &x);
	printf("moi = %d\n", ret);
	ret = printf("bonjour les gens %n ca va %d  %n\n", &b, b, &x);
	printf("lui = %d\n", ret);

	ft_printf("%6c et coco %c titi %c tyty\n", 3250, 0xd800, 'u');
	printf("%6c et coco %c titi %c tyty\n", 3250, 0xd800, 'u');
	printf("%%\n");
	ft_printf("%%\n");
printf("%10%\n");
	ft_printf("%10%\n");
printf("P = %-7% %007d%-10.2s!!\n", 777, "L");
ft_printf("M = %-7% %007d%-10.2s!!\n", 777, "L");
	
//	printf("%#o%#0120%1c\n", 8, 5, 95);	
//	ft_printf("%#o%#012o%1c\n", 8, 5, 95);	
	
	int i = 35432;
	ret = 0;
//
//	ft_printf("M = %-.7C !!\n", 0xd777);
//	printf("P = %-.7C !!\n", 0xd777);
	ft_printf("M = test %-10.2s!!\n","jj");
	printf("P = test %-10.2s!!\n", "jj");
printf("\n\n");
	

	//printf("P = %-7Q %007d%-10.2s!!\n", 0xd777, 0x45, "L");
	//ft_printf("M = %-7Q %007d%-10.2s!!\n", 0xd777, 0x45, "L");
//	ft_printf("[]\n");
	printf("1 \n\n");
	ft_printf("M = [%0#10.0x] [%0#x]\n", 12345, 0);
	printf("P = [%0#10.0x] [%0#x]\n", 12345, 0);

	ft_printf("M = %#.22X et %020.14x\n", 0xff1144ff1144, 0xffaaabbccee );
	printf("P = %#.22X et %020.14x\n", 0xff1144ff1144, 0xffaaabbccee );

	
	printf("P = toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e);
	ft_printf("M = toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e);


	printf("P = cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	ft_printf("M = cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);

	printf("P = cc%#.4X et %-#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	ft_printf("M = cc%#.4X et %-#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	ft_printf("%d\n", 42);
        unsigned long t, pt;

        pt = time(0);
        i = -1;
        //while (i++ < 1000000)
        //{
                ft_printf("bonjour %i\t %det%c ou %.15s pour voir       %c  g   %c          \n"
,42, 24, 'c', "l'hiver est la", 'c', 'c');
                ft_printf ("[%.100f]\n", (float)1.3);
                ft_printf("[ici %-10d % d %+d %010d %d et la]\n", 3, 3, 3, 1, 0);
                ft_printf("\[-%.4jd-%.4jd-%.jd-%.0jd-]\n", 7, 12345, 1, 9);
                ft_printf("[-%d-%.0jd-%.8d-%8.0zd-%8.8d-]\n", 0, 0, 0, 0, 0);
                ft_printf("[%zd %zd %+zd %+zd % zd % d %+ d %+ d % +d % +d]\n", 7, -7, 7, -7, 7
, -7, 7, -7, 7, -7);
        //}
        t  = time(0);
        printf("printf(\"bonjour %%i\t %%det%%c ou %%.15s pour voir       %%c  g   %%c          \n\",42, 24, 'c', \"l'hiver est la\", 'c', 'c');\n");
        dprintf(2, "Mine: %lu s for 1.000.000\n", t - pt);
        pt = time(0);
        i = -1;
        //while (i++ < 1000000)
        //{
                printf("bonjour %i\t %det%c ou %.15s pour voir       %c  g   %c          \n",42, 24, 'c', "l'hiver est la", 'c', 'c');
                printf ("[%.100f]\n", (float)1.3);
                printf("[ici %-10d % d %+d %010d %d et la]\n", 3, 3, 3, 1, 0);
                printf("\[-%.4jd-%.4jd-%.jd-%.0jd-]\n", 7, 12345, 1, 9);
                printf("[-%d-%.0jd-%.8d-%8.0zd-%8.8d-]\n", 0, 0, 0, 0, 0);
                printf("[%zd %zd %+zd %+zd % zd % d %+ d %+ d % +d % +d]\n", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7);
        //}
        t  = time(0);
        dprintf(2, "Real: %lu s for 1.000.000\n\n", t - pt);
           float bhf = 135.1534;

           ft_printf("%f\n", bhf);
           printf("%f\n", bhf);
	
           int  me = 0;
           int  pr = 0;
           printf("  %c %c \n", 'a', 'A');
           ft_printf("  %s %c\n", "a", 'A');
           printf("bonjour %i\t %det%c ou\n",42, 24, 'c');
           ft_printf("bonjour %i\t %det%c ou\n",42, 24, 'c');
           pr = printf("bonjour %i\t %det%c ou %.15s pour voir       %c  g   %c          \n",42, 24, 'c', "l'hiver est la", 'c', 'c');
           me = ft_printf("bonjour %i\t %det%c ou %.15s pour voir       %c  g   %c          \n",42, 24, 'c', "l'hiver est la", 'c', 'c');
           printf("me = [%d] \t pr = [%d] \n\n", me, pr);

           ft_printf("hexa [%x] hexa [%x], puis [%#25x] et [%.5x] puis [%x]\n", 23, 452, -587, 26, 0);
           printf("hexa [%x] hexa [%x], puis [%#25x] et [%.5x] puis [%x]\n", 23, 452, -587, 26, 0);

           char *s = "LALALILALA";

           printf("P 015 = [%15p] yo\n", s);
           ft_printf("P 015 = [%15p] yo\n", s);
           printf("\n");
           printf("\n");
           printf("P=0 %%p = [%p] yo\n", NULL);
           ft_printf("P=0 %%p = [%p] yo\n", NULL);
           printf("\n");
           ft_printf ("[%Lf]\n", (long double)1.3);
           printf ("[%Lf]\n", (long double)1.3);
           ft_printf ("[%.100f]\n", (float)1.3);
           printf ("[%.100f]\n", (float)1.3);
           ft_printf("%10p\n", NULL);
           printf("%10p\n", NULL);
           ft_printf("\n\nTEST : %p", NULL - 1);
           printf("\n\nTEST : %p\n", NULL - 1); 
           char c = 'c';
           int          m = 0;
           int          p = 0;
		  i = 31573;
           ft_printf("%d\n", p);
           printf("%d\n", p);
           m = printf("bonjour %c %%\n", c);
           p = ft_printf("bonjour %c %%\n", c);
           printf("m = [%d]   p = [%d]\n\n", m, p);
           printf("bonjour %c %10%\n", c);
           ft_printf("bonjour %c %10%\n", c);
           printf("m = [%d]   p = [%d]\n\n", m, p);
           printf("bonjour %c %-10%\n", c);
           ft_printf("bonjour %c %-10%\n", c);
           printf("m = [%d]   p = [%d]\n\n", m, p);
           printf("bonjour %c %010%\n", c);
           ft_printf("bonjour %c %010%\n", c);
           printf("m = [%d]   p = [%d]\n\n", m ,p);

           printf("\n **** %%o *** \n");
           ft_printf("[%-#o]\n", i);
           printf("[%-#o]\n", i);
           printf("[%-#10o]\n", i);
           ft_printf("[%-#10o]\n", i);
           printf("[%-#10o]\n", i);
           ft_printf("[%-#10o]\n", i);
           printf("[%-.3o]\n", i);
           ft_printf("[%-.3o]\n", i);
           printf("[%-#.3o]\n", i);
        ft_printf("[%-#.3o]\n", i);
        printf("[%-#10.3o]\n", i);
        ft_printf("[%-#10.3o]\n", i);
        printf("[%#010.3o]\n", i);
        ft_printf("[%#010.3o]\n", i);
        printf("[%#010o]\n", i);
        ft_printf("[%#010o]\n", i);
        printf("[%-.o]\n", 0);
        ft_printf("[%-.o]\n", 0);///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	ft_printf(" %50%ici\n");

        printf("P = [%-10.50s]\n", s);
        ft_printf("M = [%-10.50s]\n", s);
        printf("\n");
        printf("P = [%-10.2s]\n", s);
        ft_printf("M = [%-10.2s]\n", s);
        printf("\n");
        printf("P = [%-10s]\n", s);
        ft_printf("M = [%-10s]\n", s);
        printf("\n");
        printf("P = [%-.10s]\n", s);
        ft_printf("M = [%-.10s]\n", s);
        printf("\n");
        printf("P = [%-.5s]\n", s);
        ft_printf("M = [%-.5s]\n", s);
		me = 0;
		pr = 0;
        me = ft_printf("[ici %-10d % d %+d %010d %d et la]\n", 3, 3, 3, 1, 0);
        pr = printf("[ici %-10d % d %+d %010d %d et la]\n", 3, 3, 3, 1, 0);
        printf("me = [%d] \t pr = [%d] \n\n", me, pr);
        ft_printf("\n[%llda]\n", 18446744065119617025ULL);
        printf("\[%llda]\n", 18446744065119617025ULL);
        ft_printf("[%10.8lld]\n", 100LL);
        printf("\[%10.8lld]\n", 100LL);
        ft_printf("[%25.22llda]\n", -1LL);
        printf("\[%25.22llda]\n", -1LL);
        ft_printf("[%-+8.5llda]\n", 100LL);
        printf("[%-+8.5llda]\n", 100LL);
        ft_printf("[% .40d]\n", 1);
        printf("[% .40d]\n", 1);
        ft_printf("[% 10.40d]\n", 10);
        printf("[% 10.40d]\n", 10);
        ft_printf("[% 10.40d]\n", -10);
        printf("[% 10.40d]\n", -10);
                //////////////////////////////% P % //////////////////////////
printf("\nLALALA\n");
				char 	*j = s;

                printf("P = [%p]\n", j);
                ft_printf("P = [%p]\n", j);
                printf("\n");
                   printf("P 15 = [%15p] yo\n", s);
                ft_printf("P 15 = [%15p] yo\n", s);
                printf("\n");
        
                printf("P 015  = [%015p] yo\n", s);
                ft_printf("P 015  = [%015p] yo\n", s);//!!!!!!!!!!!!!!!!!!!!!!
                printf("\n");
                printf("P -30.15 = [%-30.15p] yo\n", s);
                ft_printf("P -30.15 = [%-30.15p] yo\n", s);
                printf("\n");
                printf("P .15  = [%.15p] yo\n", s);
                ft_printf("P .15  = [%.15p] yo\n", s);
                printf("\n");
                printf("P 015 = [%015p] yo\n", s);
                ft_printf("P 015 = [%015p] yo\n", s);
                printf("\n");
                printf("P -.015 = [%.-015p] yo\n", s);
                ft_printf("P -.015 = [%.-015p] yo\n", s);
                printf("\n");
                printf("P=0 %%p    = [%p] yo\n", 0);
                ft_printf("P=0 %%p = [%p] yo\n", 0);
                printf("\n");
                printf("P=0 %%.p   = [%.p] yo\n", 0);
                ft_printf("P=0 %%.p = [%.p] yo\n", 0);
                printf("\n");
                printf("P=0 %%.0p    = [%.0p] yo\n", 0);
                ft_printf("P=0 %%.0p = [%.0p] yo\n", 0);
                printf("\n");
                printf("P=0 %%0p    = [%0p] yo\n", 0);
                ft_printf("P=0 %%0p = [%0p] yo\n", 0);
                printf("\n");
                printf("M = %#.p yo\n\n", s);
                ft_printf("M = %#.p yo\n\n", s);




                printf("\n\n");
                printf("%-.30p yo\n", s);
                ft_printf("%-.30p yo\n", s);
                ft_printf("%46.30p yo\n", s);
                printf("%46.30p yo\n", s);
                ft_printf("%-46.30p yo\n", s);
                printf("%-46.30p yo\n", s);
                ft_printf("%4.3p yo\n", s);
                printf("%4.3p yo\n", s);
                ft_printf("%.3p yo\n", s);
                printf("%.3p yo\n", s);

                ft_printf("%p\n", 0);
                printf("%p\n", 0);
                ft_printf("%#x\n", 0);
                printf("%#x\n", 0);
                ft_printf("%.10p\n", 0);
                printf("%.10p\n", 0);
                ft_printf("%0.10p\n", 0);
                printf("%0.10p\n", 0);
                ft_printf("\n\nTEST : %p", NULL - 1);
                printf("\n\nTEST : %p", NULL - 1);
                // ***************************** % FLOAT% *****************************************
				//
       
       printf("\n----------------------------------------------\n------------------FLOATS-----------------------\n\n");
       float b1 = -4531.4900;
        long double a = 1411.48911;


        printf("P = [%.15f]\n", b1);
        ft_printf("M = [%.15f]\n", b1);
        printf("P = [%.15Lf]\n", a);
        ft_printf("M = [%.15Lf]\n", a);
        printf("----------------\n");
        printf("P = [%.f]\n",b1);
        ft_printf("M = [%.f]\n", b1);
        printf("P = [%.Lf]\n", a);
        ft_printf("M = [%.Lf]\n", a);
        printf("----------------\n");
        printf("P = [%.0f]\n", b1);
        ft_printf("M = [%.0f]\n", b1);
        printf("P = [%.0Lf]\n", a);
        ft_printf("M = [%.0Lf]\n", a);
        printf("-----------------\n");

        printf("P = [%.0f]\n", b1);
        ft_printf("M = [%.0f]\n", b1);
        printf("P = [%.Lf]\n", a);
        ft_printf("M = [%.Lf]\n", a);
        printf("------------------\n");
        printf("P = [%#.5f]\n", b1);
        ft_printf("M = [%#.5f]\n", b1);
        printf("P = [%#.15Lf]\n", a);
        ft_printf("M = [%#.15Lf]\n", a);
        printf("------------------\n");

        printf("------------------\n");

        ft_printf ("[%f]\n", (float)1.3);
        printf ("[%f]\n", (float)1.3);
        ft_printf ("\t ici [%.4lf]\n", (double) 124.999999);
        printf ("\t ici [%.4lf]\n",    (double) 124.999999);

        ft_printf ("[%Lf]\n", (long double)1.3);
        printf ("[%Lf]\n", (long double)1.3);
        ft_printf ("[%.100f]\n", (float)1.3);
        printf ("[%.100f]\n", (float)1.3);
        ft_printf ("[%.100lf]\n", (double)1.3);
        printf ("[%.100lf]\n", (double)1.3);
        ft_printf ("[%.15Lf]\n", (long double)1.3);
        printf ("[%.15Lf]\n", (long double)1.3);
        ft_printf ("[%.20Lf]\n", (long double)1.3);
        printf ("[%.20Lf]\n", (long double)1.3);

        ft_printf ("[%.20Lf]\n", (long double)1/3);
        printf ("[%.20Lf]\n", (long double)1/3);
        ft_printf ("\n[%.200Lf]\n", (long double)1/3);
        printf ("[%.200Lf]\n\n", (long double)1/3);
        ft_printf ("[%40.20Lf]\n", (long double)1/3);
        printf ("[%40.20Lf]\n", (long double)1/3);
        ft_printf ("[%20.20Lf]\n", (long double)1/3);
        printf ("[%20.20Lf]\n", (long double)1/3);

        ft_printf ("[%80.20f]\n", (float)0);
        printf ("[%80.20f]\n", (float)0);
        ft_printf ("[%-80.20Lf]\n", (long double)0);
        printf ("[%-80.20Lf]\n", (long double)0);

        ft_printf ("[%80.20f]\n", (float)1/3);
        printf ("[%80.20f]\n", (float)1/3);
        ft_printf ("[%-80.20f]\n", (float)1/3);
        printf ("[%-80.20f]\n", (float)1/3);
        ft_printf ("[%-80.0Lf]\n", (long double)0);
        printf ("[%-80.0Lf]\n", (long double)0);
        ft_printf ("[%-80.0Lf]\n", (long double)4/3);
        printf ("[%-80.0Lf]\n", (long double)4/3);
        ft_printf ("[%080Lf]\n", (long double)4/3);
        printf ("[%080Lf]\n", (long double)4/3);
        ft_printf ("[%-80.0Lf]\n", (long double)4/3);
        printf ("[%-80.0Lf]\n", (long double)4/3);

        ft_printf ("[%#080.0Lf]\n", (long double)4/3);
        printf ("[%#080.0Lf]\n", (long double)4/3);
        ft_printf ("[%#080.Lf]\n", (long double)4/3);
        printf ("[%#080.Lf]\n", (long double)4/3);
        ft_printf ("[%#80.Lf]\n", (long double)4/3);
        printf ("[%#80.Lf]\n", (long double)4/3);
        ft_printf ("[%#.Lf]\n", (long double)4/3);
        printf ("[%#.Lf]\n", (long double)4/3);
        ft_printf ("[%#.Lf]\n", (long double)1.33);
        printf ("[%#.Lf]\n", (long double)1.33);
        ft_printf ("[%#.f]\n", (double)1.33);
        printf ("[%#.f]\n", (double)1.33);

printf("\n \t la \n");
        ft_printf ("[%#080Lf]\n", (long double)4/3);
        printf ("[%#080Lf]\n", (long double)4/3);
        ft_printf ("la [%#-080Lf]\n", (long double)-4/3);
        printf ("la [%#-080Lf]\n", (long double)-4/3);
        ft_printf ("la [%#-080Lf]\n", (long double)4/3);
        printf ("la [%#-080Lf]\n", (long double)4/3);

        ft_printf ("[%#+80Lf]\n", (long double)-4/3);
        printf ("[%#+80Lf]\n", (long double)-4/3);
        ft_printf ("[%#+080Lf]\n", (long double)-4/3);
        printf ("[%#+080Lf]\n", (long double)-4/3);
        ft_printf ("[%#+-080Lf]\n", (long double)-4/3);
        printf ("[%#+-080Lf]\n", (long double)-4/3);

        ft_printf ("[%#+.80Lf]\n", (long double)4/3);
        printf ("[%#+.80Lf]\n", (long double)4/3);
        ft_printf ("[%#+80Lf]\n", (long double)4/3);
        printf ("[%#+80Lf]\n", (long double)4/3);
        ft_printf ("[%.80Lf]\n", (long double)1.1);
        printf ("[%.80Lf]\n", (long double)1.1);



        ft_printf("%.40f, %.40lf\n", (double)1.1,(double)1.1);
        printf("%.40f, %.40lf\n", (double)1.1,(double)1.1);

		
		ft_printf("%-d\n", -557112);
		printf("%-d\n", -557112);

        ////////////////////else/////////////////////

        char    c2 = 'c';
        m = 0;
        p = 0;
        ft_printf("%d\n", p);
        m = printf("bonjour %c %%\n", c2);
        p = ft_printf("bonjour %c %%\n", c2);
        printf("m = [%d]   p = [%d]\n\n", m, p);
        printf("bonjour %c %10%\n", c2);
        ft_printf("bonjour %c %10%\n", c2);
        printf("m = [%d]   p = [%d]\n\n", m, p);
        printf("bonjour %c %-10%\n", c2);
        ft_printf("bonjour %c %-10%\n", c2);
        printf("m = [%d]   p = [%d]\n\n", m, p);
        printf("bonjour %c %010%\n", c2);
        ft_printf("bonjour %c %010%\n", c2);
        printf("m = [%d]   p = [%d]\n\n", m ,p);



        /// ******************* %o ********************
        //
printf("\n------------------%%O-----------------------\n");
		int lala = 135743;
        ft_printf("M = [%#20.15o]\n", lala);
        printf("P = [%#20.15o]\n", lala);
        ft_printf("M = [%#.15o]\n", lala);
        printf("P = [%#.15o]\n", lala);
        ft_printf("M = [%#20o]\n", lala);
        printf("P = [%#20o]\n", lala);
        ft_printf("M = [%o]\n", lala);
        printf("P = [%o]\n", lala);
        
                   ft_printf("M = [%#o]\n", 0);
                   printf("P = [%#o]\n", 0);
                   ft_printf("M = [%#.0o]\n", 0);
                   printf("P = [%#.0o]\n", 0);

                   printf(" 1 [%-o]\n", i);
                   ft_printf("   [%-o]\n", i);
                   printf(" 2 [%-.4o]\n", i);
                   ft_printf("   [%-.4o]\n", i);
                   printf(" 3 [%-#.4o]\n", i);
                   ft_printf("   [%-#.4o]\n", i);
                   printf(" 4 [%-#o]\n", i);
                   ft_printf("   [%-#o]\n", i);
                   printf(" 5 [%-#10o]\n", i);
                   ft_printf("   [%-#10o]\n", i);
                   printf(" 6 [%-#10o]\n", i);
                   ft_printf("   [%-#10o]\n", i);
                   printf(" 7 [%-.3o]\n", i);
                   ft_printf("   [%-.3o]\n", i);
                   printf(" 8 [%-#.3o]\n", i);
                   ft_printf("   [%-#.3o]\n", i);
                   printf(" 9 [%-#10.3o]\n", i);
                   ft_printf("   [%-#10.3o]\n", i);
                   printf(" 10 [%-#010.3o]\n", i);
                   ft_printf("    [%-#010.3o]\n", i);
                   printf(" 11  [%-#010o]\n", i);
                   ft_printf("     [%-#010o]\n", i);
                   printf("12  [%-.o]\n", 0);
                   ft_printf("12  [%-.o]\n", 0); // !!!!!!!!!!!!!!!1!!!!!!!!!!!!

printf("\n------------------%%s-----------------------\n");
                // ******************* %c ********************
                printf("\n \t\t %%s \nn\n");

                s = "hello wo";
                printf("P = [%030s]\n", s);
                ft_printf("M = [%030s]\n", s);
                printf("\n");
                printf("P = [%s]\n", s);
                ft_printf("m = [%s]\n", s);

                printf("P = [%-30.s]\n", s);
                ft_printf("M = [%-30.s]\n", s);
                printf("\n");
                printf("P = [%-.1s]\n", s);
                ft_printf("M = [%-.1s]\n", s);
                printf("\n");

                printf("P = [%-10.50s]\n", s);
                ft_printf("M = [%-10.50s]\n", s);
                printf("\n");
                printf("P = [%-10.2s]\n", s);
                ft_printf("M = [%-10.2s]\n", s);
                printf("\n");
                printf("P = [%-10s]\n", s);
                ft_printf("M = [%-10s]\n", s);
                printf("\n");
                printf("P = [%-.10s]\n", s);
                ft_printf("M = [%-.10s]\n", s);
                printf("\n");
                printf("P = [%-.5s]\n", s);
                ft_printf("M = [%-.5s]\n", s);


                printf("P = [%-10s]\n", s);
                ft_printf("M = [%-10s]\n", s);


                printf("P = [%010s]\n", s);
        ft_printf("M = [%010s]\n", s);


        printf("P = [%0s]\n", s);
        ft_printf("M = [%0s]\n", s);


        printf("P = [% 10s]\n", s);
        ft_printf("M = [% 10s]\n", s);


        printf("P = [%10.5s]\n", s);
        ft_printf("M = [%10.5s]\n", s);

        printf("\n\n\n\n\n");
        // *     ******************* %C ******************* *
printf("\n------------------%%c-----------------------\n");
        printf("\n \t\t %%c \nn\n");

        printf("F = [%c]\n", c);
        ft_printf("M = [%c]\n", c);
        printf("F = [%10c]\n", c);
        ft_printf("M = [%10c]\n", c);
        printf("F = [%-10c]\n", c);
        ft_printf("M = [%-10c]\n", c);
        printf("F = [%010c]\n", c);
        ft_printf("M = [%010c]\n", c);
        printf("F = [%.5c]\n", c);
        ft_printf("M = [%.5c]\n", c);
        printf("F = [% c]\n", c);
        ft_printf("M = [% c]\n", c);
        printf("F = [%10.5c]\n", c);
        ft_printf("M = [%10.5c]\n", c);
        printf("F = [%+5c]\n", c);
        ft_printf("M = [%+5c]\n", c);
        printf("F = [%+c]\n", c);
        ft_printf("M = [%+c]\n", c);
        printf("F = [%#c]\n", c);
        ft_printf("M = [%#c]\n", c);

        printf("\n------------------%%x-----------------------\n");
		// **************************** %x **********************
 	printf("P = 0  %%.0x  [%.0x]\n", 0);
     ft_printf("M = 0  %%.0x  [%.0x]\n\n", 0);
	
	printf("P = 0  %%.x    [%.x]\n", 0);
	ft_printf("P = 0  %%.x    [%.x]\n", 0);


	printf("P = 1  %%.x  [%.x]\n", 1);
	ft_printf("M = 1  %%.x  [%.x]\n\n", 1);

	printf("P = 0  %%0x  [%0x]\n", 2487);
	ft_printf("M = 0  %%0x  [%0x]\n\n", 2487);


	printf("P = 0 %%.0x  [%#.0x]\n", 0);
	ft_printf("M = 0 %%.0x  [%#.0x]\n\n", 0);
	
	printf("P = 0  %%.x  [%#.x]\n", 2487);
	ft_printf("M = 0  %%.x  [%#.x]\n\n", 2487);


	printf("P = 1  %%.x  [%#.x]\n", 1534);
	ft_printf("M = 1 %%.x  [%#.x]\n\n", 1534);

	   printf("P = 0 %%0x   [%#0x]\n", 345);
	ft_printf("M = 0 %%0x   [%#0x]\n", 345);

        printf("\n------------------%%D-----------------------\n");
        //      ******************* %D ********************
        int z = 2121347;
        int l = -9841;
        int     k = b + l;
        ft_printf("M = [%05.2d]\n", z);
        printf("P = [%05.2d]\n", z);
        ft_printf("M = [%05.2lld]\n", l);
        printf("P = [%05.2lld]\n", l);
        ft_printf("M = [%05.2lld]\n", k);
        printf("P = [%05.2lld]\n", k);
        ft_printf("[%016.5d]\n", 36);
        printf("[%016.5d]\n", 36);
        ft_printf("[%016.d]\n", 123456789);
        printf("[%016.d]\n", 123456789);
        ft_printf("LA: %hhd\n", 0);
        printf("LA: %hhd\n", 0);
      ft_printf("\n[%-10d % d %+d %010d %hhd]\n", 3, 3, 3, 1, 0);
        printf("\[%-10d % d %+d %010d %hhd]\n", 3, 3, 3, 1, 0);
        ft_printf("\n[%llda]\n", 18446744065119617025LL);
        printf("\[%llda]\n", 18446744065119617025LL);
        ft_printf("[%10.8lld]\n", 100LL);
        printf("\[%10.8lld]\n", 100LL);
        ft_printf("[%#25.22llda]\n", -1LL);
        printf("\[%#25.22llda]\n", -1LL);
        ft_printf("[%#-+ 08.5llda]\n", 100LL);
        printf("[%#-+ 08.5llda]\n", 100LL);
        ft_printf("[% .40d]\n", 1);
        printf("[% .40d]\n", 1);
        ft_printf("[% 10.40d]\n", 10);
        printf("\[% 10.40d]\n", 10);
        ft_printf("[% 10.40d]\n", -10);
        printf("\[% 10.40d]\n", -10);
        printf ("[%d] [%d]\n", m, p);
        m = ft_printf("\n\033[0;33mYOUR>\t\033[0m[%4.5d]\n", 42);
        p = printf("\033[0;31mREAL>\t\033[0m[%4.5d]\n", 42);
        printf ("[%d] [%d]\n", m, p);
        ft_printf("\[-%.4jd-%.4jd-%.jd-%.0jd-]\n", 7, 12345, 1, 9);
        printf("[-%.4jd-%.4jd-%.jd-%.0jd-]\n", 7, 12345, 1, 9);
        ft_printf("[-%d-%.0jd-%.8d-%8.0zd-%8.8d-]\n", 0, 0, 0, 0, 0);
        printf("\[-%d-%.0jd-%.8d-%8.0zd-%8.8d-]\n", 0, 0, 0, 0, 0);
        printf("[%d %d %+d %+d % d % d %+ d %+ d % +d % +d]\n", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7);
       ft_printf("[%d %d %+d %+d % d % d %+ d %+ d % +d % +d]\n", 7, -7, 7, -7, 7, -7, 7, -7, 7, -7);
	  /*
        printf("\n\n\n\n---------\n\n\n");
        printf("The number of bits in a byte %d\n", CHAR_BIT);
        printf("SIGNED CHAR BYTE SIZE = %lu\n", sizeof(char));
        printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
        printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
        printf("UNSIGNED CHAR BYTE SIZE = %lu\n", sizeof(unsigned char));
        printf("The max+imum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);
        printf("\n");
        printf("SHORT  INT BYTE SIZE = %lu\n", sizeof(short int));
        printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
        printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);
        printf("The maximum value of SHORT U INT = %d\n", USHRT_MAX);
        printf("\n");
        printf("INT BYTE SIZE = %lu\n", sizeof(int));
        printf("The minimum value of INT = %d\n", INT_MIN);
        printf("The maximum value of INT = %d\n", INT_MAX);
        printf("The maximum value of U INT = %u\n", UINT_MAX);
        printf("\n");
        printf("CHAR BYTE SIZE = %lu\n", sizeof(char));
        printf("The minimum value of CHAR = %d\n", CHAR_MIN);
        printf("The maximum value of CHAR = %d\n", CHAR_MAX);
        printf("\n");
        printf("LONG BYTE SIZE = %lu\n", sizeof(long));
        printf("The minimum value of LONG = %ld\n", LONG_MIN);
        printf("The maximum value of LONG = %ld\n", LONG_MAX);
        printf("The maximum value of U LONG = %lud\n", ULONG_MAX);
        printf("LONG LONG BYTE SIZE = %lu\n\n", sizeof(long long));
        printf("the minimum value of long long = %lld\n", llong_min);
        printf("the maximum value of long long = %lld\n", LLONG_MAX);
        printf("u long long byte size = %lu\n", sizeof(ullong_max));
        printf("the maximum value of u long = %llu\n", ullong_max);
        printf("FLOAT BYTE SIZE = %lu\n", sizeof(float));
        printf("The minimum value of FLOAT = %f\n", FLT_MIN);
        printf("The maximum value of FLOAT = %f\n", FLT_MAX);
        printf("DOUBLE byte size = %lu\n", sizeof(double));
//                printf("long DOUBLE byte size = %lu\n", sizeof(long double));
             //      printf("The minimum value of LONG DOUBLE = %Lf\n", LDBL_MIN);
        //      printf("The maximum value of LONG DOUBLE = %Lf\n", LDBL_MAX);
		//      */
        return (0);
}
