/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:47:25 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/24 17:25:49 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"




float *ft_floatocaster(float d)
{
	float *ret;

	ret = &d;
	return(ret);
}

int	ft_getsexpld(long double val)
{
	return((int)val);
}

void ft_displaybin(void *content, size_t n)
{
		
	unsigned char *tmp;
	unsigned char mask;
	int i = 0;

	mask = 0x80;
	tmp = (unsigned char *)content;

	while(n--)
	{
		mask = 0x80;	
		while(mask)
		{
			(*tmp & mask) ? ft_putchar('1') :ft_putchar('0');
			mask = mask >> 1;
			i++;
			if(i % 4 == 0)
				ft_putchar(' ');
		}
//	ft_putchar(' ');
//		ft_putchar(*tmp);
//		ft_putchar(' ');
		tmp++;
//		ft_putchar('\n');
	}
}

int	main()
{

double *newval; 
	*newval = 0x3FD5555555555555L;

	float newval2;

newval2 = 3.0;
ft_print_uni_str("🤡  ");

ft_hexfloat(&*newval, sizeof(long double));
ft_putendl("\n\nlong double above\n");
ft_hexfloat(&*newval, sizeof(double));
ft_putendl("\ndouble above\n");
ft_hexfloat(&*newval, sizeof(float));
ft_putendl("\nfloat above\n");

ft_putchar('\n');

//ft_displaybin(ft_floatocaster(newval2), sizeof(long double));
/*newval = -*newval;
*/
//ft_hexfloat(&*ft_floatocaster(newval2), sizeof(int));
//ft_putchar('\n');
	printf("%zu %zu %zu", sizeof(float), sizeof(double), sizeof(long double));
/**newval = -*newval;
ft_hexfloat(*&newval, sizeof(long double));*/
//ft_putchar('\n');
return(0);
}
