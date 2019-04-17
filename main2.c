/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:47:25 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/17 17:37:37 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"



int	main()
{
	char s1[12] = "2" ;
	char s2[12] = "1";
	char ret[15];
	char carry = 0;
	

	carry = ft_addchar(s1, s2, ret, carry);

	ft_putchar(carry + '0');
	ft_putendl("return below");
	ft_putchar(*ret);
	
	return(0);
}
