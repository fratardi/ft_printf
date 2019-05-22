/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/22 22:14:51 by tpacaud          ###   ########.fr       */
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

	printf("\n\nREAL\n\n");
    printf("Plus + prec / petite:%+.0f\n", nb);
	
	return (0);
} */

int main(void)
{
	int nb = 0;

/* 		ft_printf("space% d ", nb);
	ft_printf("plus:%+d ", nb);
	ft_printf("precision:%.5d ", nb);
	ft_printf("space + prec:% .5d ", nb);
	ft_printf("Plus + prec / grande:%+.5d ", nb);
	ft_printf("Prec + 0:%0.5d ", nb);
	ft_printf("Prec + minus:%-.5d ", nb);
	ft_printf("size:%5d ", nb);
	ft_printf("size + space:% 5d ", nb);
	ft_printf("size + plus:%+5d ", nb);
	ft_printf("size + minus:%-5d ", nb);
	ft_printf("size + 0:%05d ", nb);
	ft_printf("size + 0 + plus:%+05d ", nb);
	ft_printf("size + 0 + plus:%0+5d ", nb);
	ft_printf("size + 0 + prec:%05.3d ", nb);
	ft_printf("size + minus + prec:%-5.3d ", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d ", nb);
	ft_printf("size + espace + zero + prec:%0 5.3d ", nb);
	ft_printf("size + espace + zero + prec:% 05.3d ", nb);
	ft_printf("size + minus + plus + prec:%-+5.3d ", nb); */

	printf("space% d ", nb);
	printf("plus:%+d ", nb);
	printf("precision:%.5d ", nb);
	printf("space + prec:% .5d ", nb);
	printf("Plus + prec / grande:%+.5d ", nb);
	printf("Prec + 0:%0.5d ", nb);
	printf("Prec + minus:%-.5d ", nb);
	printf("size:%5d ", nb);
	printf("size + space:% 5d ", nb);
	printf("size + plus:%+5d ", nb);
	printf("size + minus:%-5d ", nb);
	printf("size + 0:%05d ", nb);
	printf("size + 0 + plus:%+05d ", nb);
	printf("size + 0 + plus:%0+5d ", nb);
	printf("size + 0 + prec:%05.3d ", nb);
	printf("size + minus + prec:%-5.3d ", nb);
	printf("size + plus + 0 + prec:%+05.3d ", nb);
	printf("size + espace + zero + prec:%0 5.3d ", nb);
	printf("size + espace + zero + prec:% 05.3d ", nb);
	printf("size + minus + plus + prec:%-+5.3d ", nb);


	return (0);
}
