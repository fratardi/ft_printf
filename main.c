/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:07:31 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/07 21:08:43 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"
#include <stdio.h>

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


*/
int main(void)
{

	 //ft_printf("%#s%c\n %o%#x%#X%lld%f%Lf%#Lf", "test", '*', 41, 40, 39, 38, 12.5, 1.3L, 123.456L);
	   
	 ft_putendl((char *)ft_memaset('b',32));
	 //printf("%#s\n%c\n%#o\n%#x\n%#X\n%lld\n%f\n%Lf\n%#LF\n", "test", '*', 41, 40, 39, 38, 12.5, 1.3L, 123.456L);
//	printf("\n%#x\n", 123.456);

	return (0);
}
