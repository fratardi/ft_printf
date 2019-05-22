/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/05/20 10:29:37 by tpacaud          ###   ########.fr       */
=======
/*   Updated: 2019/05/23 01:15:48 by tpacaud          ###   ########.fr       */
>>>>>>> 7b7a9ee322c505b1f3258d2f50bf9bb094c8ba7f
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
	changer retour de la fonction :	
	printf("m |%zu|\n", ft_printf("", s));
	printf("r |%d|\n", printf("%s", s));  	

	ft_printf("m |%%%p|\n", &s);  	
	printf("r |%%%p|\n", &s);  	

<<<<<<< HEAD
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
=======
	ft_printf("m |%.p|\n",&s);  	
	printf("r |%.p|\n", &s);  	

	ft_printf("m |%#0.0X|\n", 842);  	
	printf("r |%#0.0X|\n", 842);  	

	ft_printf("m |%# 10b|\n", 8750);  	
	printf("r |%# 10b|\n", 8750);  	

*/
/* int main(void)
{
	double nb;

	nb = 0;
	
	ft_printf("test basique:\n");
    ft_printf("Plus + prec / petite:%+.0f\n", nb);
>>>>>>> 7b7a9ee322c505b1f3258d2f50bf9bb094c8ba7f

	printf("\n\nREAL\n\n");
    printf("Plus + prec / petite:%+.0f\n", nb);
	
	return (0);
} */

int main(void)
{
	long int nb = 2147483648;

	ft_printf("%b", nb);

	return (0);
}
