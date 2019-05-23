/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/23 03:21:29 by tpacaud          ###   ########.fr       */
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

		ft_printf("test basique:\n");
    ft_printf("Plus + prec / petite:%+.0f\n", nb);

	printf("\n\nREAL\n\n");
    printf("Plus + prec / petite:%+.0f\n", nb);
*/

int main(void)
{
	int nb = 0;

	ft_printf("%b", nb);


	return (0);
}
