/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 01:14:10 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/28 18:59:20 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#ifndef LEAKS
#define LEAKS while(1);
#endif

void	bonus(void)
{
    long double		nb;

	printf("============== NDOL & WILDCARD ===================\n\n");
	ft_printf("Y> n$ - inverse = %2$s %1$s\n", "1st_String", "2nd_String");
	printf("R> n$ - inverse = %2$s %1$s\n", "1st_String", "2nd_String");
	ft_printf("Y> wildcard = %*.*f\n", 26, 18, 123.4f);
	printf("R> wildcard = %*.*f\n", 26, 18, 123.4f);

	printf("\n\n============== PERSONNAL ===================\n\n");	
	ft_printf("Unicodes = 4️⃣ 2️⃣  et %s\n", "😀 😝 🖥  🖱 ");
	ft_printf("Scientific = %Ef\n", 1.234567E-100);
	ft_printf("Binary int - %b\n", 1);
	ft_printf("Binary int - %b\n", 2147483647);
	ft_printf("Binary Sting - %B\n", "2147483647");

	printf("\n\n============== More specifier & converter ===================\n\n");	
	ft_printf("Y> Octal Upper = %O\n", 42);
	printf("R> Octal Upper = %O\n", 42);
	ft_printf("Y> Unsigned Upper = %U\n", 42);
	printf("R> Unsigned Upper = %U\n", 42);
	printf("Y> size_t = %zu\n", (size_t)42);
	ft_printf("R> size_t = %zu\n", (size_t)42);

	printf("\n\n============== Float Precision ===================\n\n");	
	ft_printf("Your >> %.900Lf\n", 123.456E-250L);
	printf("Real >> %.900Lf\n\n", 123.456E-250L);
	ft_printf("Your >> %.20Lf\n", 111111111111111111111111111111111111.22222222222222222222222222222222L);
	printf("Real >> %.20Lf\n", 111111111111111111111111111111111111.22222222222222222222222222222222L);

	printf("\n\n============== Float Exception ===================\n\n");	
	nb = 1.0L/0.0L;
	ft_printf("Y> %5.9Lf\n", nb);
	printf("R> %5.9Lf\n", nb);
    nb = -1.0/0.0;
	ft_printf("Y> %-12Lf\n", nb);
	printf("R> %-12Lf\n", nb);
	nb = 0.0L/0.0L;
	ft_printf("Y> %12Lf\n", nb);
	printf("R> %12Lf\n", nb);
	nb = -0.0L;
	ft_printf("Y> %Lf\n", nb);
	printf("R> %Lf\n", nb);

	printf("\n\n\n\n============== UNDEFINED ===================\n\n");
	ft_printf("Y> %88-d\n", 12);
	printf("R> %88-d\n", 12);
	ft_printf("Y> %18.12.13.17f\n", 123.4);	
	printf("R> %18.12.13.17f\n", 123.4);
	ft_printf("Y> %019+#X\n", 256);	
	printf("R> %019+#X\n", 256);	
}

void ft_brute_force_ldble(long double ref)
{
	int		next = 0;
	char *flags;
	char *ret;
	int flags_num = 0;
	int flags_cpy = 0;
	long double flt;
	char *type = "Lf";
	void *arg;
	int i;
	int c, o;
	int random;

	flt = ref;
	printf("\n\033[35m==================== TESTING SPECIFIER {%s} ================\033[0m\n", type);
	i = 5;
	ret = ft_memaset(0, 1024);
	flags = ft_strdup(" +-#0");
	srand(time(NULL));
	// arg = (void *)42;
	while (flags_num < 5)
	{
		ft_memset(ret, 0, 1024);
		ret[0] = '%';
		if (i == 20)
		{
			// if (flags_num == 3)
				// flt = flt /214748.0L;
			if (flags_num % 2 == 0)
				flt = flt / 8.24L;
			else
				flt = flt * 1.34L;
			flags_num++;
			i = 0;
		}
		if (i % 3)
			flt = -flt;
		flags_cpy = flags_num;
		while (flags_cpy)
		{
			ft_strncat(ret, &flags[rand() % (4 + 1 - 0) + 0], 1);
			flags_cpy--;
		}
		ft_strcat(ret, ft_ullitoa(rand() % (50 + 1 - 0) + 0));
		ft_strcat(ret, ".");
		ft_strcat(ret, ft_ullitoa(rand() % (50 + 1 - 0) + 0));
		ft_strcat(ret, type);
		ft_strcat(ret, "|\n");
		printf("float = %Lf et FORMAT = %s", flt, ret);
		c = ft_printf(ret, flt);
		o = printf(ret, flt);
		printf("DIFF >> %s\n", (c == o) ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m");
		if (next == 0 && getchar() == 'n')
			next = 1;
		if (next == 1 && flags_num >= 5 && getchar())
			next = 0;
		i++;
	}
}

void ft_brute_force(char *type)
{
	int		next = 0;
	char *flags;
	char *ret;
	int flags_num = 0;
	int flags_cpy = 0;
	float flt = 0.0f;
	// unsigned int arg = 42;
	void *arg;
	int i;
	int c, o;
	int random;

	printf("\n\033[35m==================== TESTING SPECIFIER {%s} ================\033[0m\n", type);
	i = 5;
	ret = ft_memaset(0, 1024);
	flags = ft_strdup(" +-#0");
	srand(time(NULL));
	if (!ft_strcmp("s", type) || !ft_strcmp("p", type))
		arg = "chaine_test";
	if (ft_strchr("diouxX", type[ft_strlen(type) - 1]))
	{
		random = rand() % (INT_MAX + 1 - 0) - INT_MIN;
		arg = &random;
	}
	if (!ft_strcmp("c", type))
	{
		random = rand() % (126 + 1 - 32) + 32;
		arg = &random;
	}
	if (!ft_strcmp("f", type))
		flt = (float)rand() / ((float)RAND_MAX / 2.0000087688f);
	while (flags_num < 5)
	{
		ft_memset(ret, 0, 1024);
		ret[0] = '%';
		if (i == 20)
		{
			if (ft_strchr("diouxX", type[ft_strlen(type) - 1]))
			{
				random = rand() % (INT_MAX + 1 - 0) + INT_MIN;
				arg = &random;
			}
			if (!ft_strcmp("c", type))
			{
				random = rand() % (126 + 1 - 32) + 32;
				arg = &random;
			}
			if (flags_num % 2 == 0)
				flt = (float)rand() / ((float)RAND_MAX / 2.0087688f);
			else
				flt = (float)rand() / ((float)RAND_MAX / 20489.087688f);
			flags_num++;
			i = 0;
		}
		flags_cpy = flags_num;
		while (flags_cpy)
		{
			ft_strncat(ret, &flags[rand() % (4 + 1 - 0) + 0], 1);
			flags_cpy--;
		}
		ft_strcat(ret, ft_ullitoa(rand() % (50 + 1 - 0) + 0));
		ft_strcat(ret, ".");
		ft_strcat(ret, ft_ullitoa(rand() % (50 + 1 - 0) + 0));
		ft_strcat(ret, type);
		ft_strcat(ret, "|\n");
		if (!ft_strcmp(type, "f"))
		{
			printf("float = %f et FORMAT = %s", flt, ret);
			c = ft_printf(ret, flt);
			o = printf(ret, flt);
			printf("DIFF >> %s\n", (c == o) ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m");
		}
		else if (!ft_strcmp(type, "c"))
		{
			printf("arg = %c et FORMAT = %s", random, ret);
			c = ft_printf(ret, random);
			o = printf(ret, random);
			printf("DIFF >> %s\n", (c == o) ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m");
		}
		else if (!ft_strcmp(type, "s"))
		{
			printf("arg = %d et FORMAT = %s", arg, ret);
			c = ft_printf(ret, arg);
			o = printf(ret, arg);
			printf("DIFF >> %s\n", (c == o) ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m");
		}
		else
		{
			if (ft_strchr("ouxX", type[ft_strlen(type) - 1]))
				printf("unsigned = %u et FORMAT = %s", (unsigned int)random, ret);
			else
				printf("arg = %d et FORMAT = %s", random, ret);
			c = ft_printf(ret, random);
			o = printf(ret, random);
			printf("DIFF >> %s\n", (c == o) ? "\033[32mOK\033[0m" : "\033[31mKO\033[0m");
		}
		if (next == 0 && getchar() == 'n')
			next = 1;
		if (next == 1 && flags_num >= 5 && getchar())
			next = 0;
		i++;
		// printf("%d", rand() % (10 + 1 - 1) + 1);
	}
	// getchar();
}

int main(void)
{
	ft_brute_force_ldble((long double)((float)rand() / ((float)RAND_MAX / 222222.0f)));
	ft_brute_force("f");
	ft_brute_force("i");
	ft_brute_force("d");
	ft_brute_force("hd");
	ft_brute_force("hhd");
	ft_brute_force("u");
	ft_brute_force("hu");
	ft_brute_force("hhu");
	ft_brute_force("o");
	ft_brute_force("ho");
	ft_brute_force("hho");
	ft_brute_force("x");
	ft_brute_force("hx");
	ft_brute_force("hhx");
	ft_brute_force("X");
	ft_brute_force("hX");
	ft_brute_force("hhX");
	ft_brute_force("c");
	ft_brute_force("p");
	ft_brute_force("s");
	printf("\n\n\n\n\033[35m=============== BONUS ===========\033[0m\n\n\n");
	getchar();
	getchar();
	bonus();	
	// ft_printf("%Lf\n", 0.01/1.0L);
	// ft_printf("%Lf\n", 0.01/1.0L);
	// double a = 123.4;
	// ft_printf("%1.5.2lf\n", a);
	// printf("%1.5.2lf\n", a);
	// ft_printf("%2$s %1$s\n", "1", "2");
	// ft_printf("%1.16f\n", 123.456f);
	// ft_printf("%#0 -+3.5hf\n", -111111111111111.2222222222222L);
	return (0);
}