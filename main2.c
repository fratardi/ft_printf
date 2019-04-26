/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:47:25 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/26 18:46:46 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

void ft_displaybin(void *content, size_t n)
{
		
	unsigned char *tmp;
	unsigned int mask;

	tmp = (unsigned char *)content + n - 1;
	while(n--)
	{
		mask = 0x100;	
		while((mask = mask >> 1))
			(*tmp & mask) ? ft_putchar('1') :ft_putchar('0');
		tmp--;
	}
}

int	main()
{

//	float *newval; 
//	*newval = -3.75;
//int *truc;
//*truc = 0x80008000;
//
//	float *newval2;



//	*newval2 = -3.75;
	char *str;

	str = ft_strdup("0");

		ft_displaybin(str, ft_strlen(str));
		ft_putchar('\n');
//		ft_hexfloat(&*newval, sizeof(float));
		/*
newval2 = 3.0;
ft_print_uni_str("🤡  ");

ft_hexfloat(&*newval, sizeof(long double));
ft_putendl("\n\nlong double above\n");
ft_hexfloat(&*newval, sizeof(double));
ft_putendl("\ndouble above\n");
ft_hexfloat(&*newval, sizeof(float));
ft_putendl("\nfloat above\n");
*/
ft_putchar('\n');/*
*/
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
