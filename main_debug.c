/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 01:14:10 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/28 04:13:29 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#ifndef LEAKS
#define LEAKS while(1);
#endif

void ft_brute_force_ldble(long double ref)
{
	char *flags;
	char *ret;
	int flags_num = 0;
	int flags_cpy = 0;
	long double flt;
	// unsigned int arg = 42;
	char *type = "Lf";
	void *arg;
	int i;
	int c, o;
	int random;

	flt = ref;
	printf("===================== TESTING TYPE > %s ====================\n", type);
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
		getchar();
		i++;
		// printf("%d", rand() % (10 + 1 - 1) + 1);
	}
}

void ft_brute_force(char *type)
{
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

	printf("===================== TESTING TYPE > %s ====================\n", type);
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
		getchar();
		i++;
		// printf("%d", rand() % (10 + 1 - 1) + 1);
	}
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