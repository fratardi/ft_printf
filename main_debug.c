/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 01:14:10 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/26 06:52:43 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
	char *flags;
	char *ret;
	int flags_num = 0;
	int flags_cpy = 0;
	char *type = "f";
	// unsigned int arg = 42;
	float arg;
	int i;
	int random_h;
	int random_l;

	i = 5;
	ret = ft_memaset(0, 1024);
	flags = ft_strdup(" +-#0");
	srand(time(NULL));
	arg = (float)rand()/((float)RAND_MAX/123.91);
	while (flags_num < 5)
	{
		// arg = (float)rand()/((float)RAND_MAX/123.91);
		ft_memset(ret, 0, 1024);
		ret[0] = '%';
		if (i == 20)
		{
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
		random_l = 0;
		random_h = 0;
		if (i == 1 || i == 3)
			random_l = rand() % (2 + 1 - 0) + 0;
		if (i == 2 || i == 3)
			random_h = rand() % (2 + 1 - 0) + 0;
		if (random_l)
		{
			if (random_l == 2 && ft_strcmp("f", type) == 0)
				ft_strcat(ret, "L");
			else
				ft_strncat(ret, "ll", random_l);
		}
		if (random_h)
			ft_strncat(ret, "hh", random_h);
		ft_strcat(ret, type);
		ft_strcat(ret, "\n");
		printf("arg = %f et FORMAT = %s", ret, arg);
		if (ret[ft_strlen(ret) - 1] == 'L')
		{
			ft_printf(ret, (long double)arg);
			printf(ret, (long double)arg);
		}
		else
		{
			ft_printf(ret, arg);
			printf(ret, arg);
		}
		getchar();
		i++;
		// printf("%d", rand() % (10 + 1 - 1) + 1);    
	}
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