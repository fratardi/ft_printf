/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/28 21:38:28 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
	int nb = 56432;
/* 	ft_printf("space:% d\n", nb);
    ft_printf("plus:%+d\n", nb);
    ft_printf("hash:%#d\n", nb);
    ft_printf("precision:%.2d\n", nb);
    ft_printf("big prec:%.14d\n", nb);
    ft_printf("precision + hash:%#.0d\n", nb);
    ft_printf("space + prec:% .5d\n", nb);
    ft_printf("space + prec + hash:%# .0d\n", nb);
    ft_printf("space + prec + hash:% #.0d\n", nb);
    ft_printf("Plus + prec / grande:%+.5d\n", nb);
    ft_printf("Plus + prec / petite:%+.0d\n", nb);
    ft_printf("Plus + prec + hash:%#+.0d\n", nb);
    ft_printf("Prec + 0:%0.5d\n", nb);
    ft_printf("Prec + minus:%-.5d\n", nb);
    ft_printf("size:%5d\n", nb);
    ft_printf("size + space:% 5d\n", nb);
    ft_printf("size + plus:%+5d\n", nb);
    ft_printf("size + space:%# 5d\n", nb);
    ft_printf("size + plus:%#+5d\n", nb);
    ft_printf("size + minus:%-5d\n", nb);
    ft_printf("size + 0:%05d\n", nb);
    ft_printf("size + 0 + plus:%+05d\n", nb);
    ft_printf("size + 0 + plus:%0+5d\n", nb);
    ft_printf("size + 0 + prec:%05.3d\n", nb);
    ft_printf("size + 0 + prec + hash:%0#5.0d\n", nb);
    ft_printf("size + minus + prec:%-5.3d\n", nb);
    ft_printf("size + minus + prec + hash:%-#5.0d\n", nb);
    ft_printf("size + plus + 0 + prec:%+05.3d\n", nb);
    ft_printf("size + plus + 0 + prec + hash:%0+#5.0d\n", nb);
    ft_printf("size + espace + zero + prec:%0 5.3d\n", nb);
    ft_printf("size + espace + zero + prec:% 05.3d\n", nb);
    ft_printf("size + espace + zero + prec + hash:%#0 5.0d\n", nb);
    ft_printf("size + minus + plus + prec:%-+5.3d\n", nb);
    ft_printf("size + minus + plus + prec + hash:%-#+5.0d\n", nb);  */
	
	printf("space:% d\n", nb);
    printf("plus:%+d\n", nb);
    printf("hash:%#d\n", nb);
    printf("precision:%.2d\n", nb);
    printf("big prec:%.14d\n", nb);
    printf("precision + hash:%#.0d\n", nb);
    printf("space + prec:% .5d\n", nb);
    printf("space + prec + hash:%# .0d\n", nb);
    printf("space + prec + hash:% #.0d\n", nb);
    printf("Plus + prec / grande:%+.5d\n", nb);
    printf("Plus + prec / petite:%+.0d\n", nb);
    printf("Plus + prec + hash:%#+.0d\n", nb);
    printf("Prec + 0:%0.5d\n", nb);
    printf("Prec + minus:%-.5d\n", nb);
    printf("size:%5d\n", nb);
    printf("size + space:% 5d\n", nb);
    printf("size + plus:%+5d\n", nb);
    printf("size + space:%# 5d\n", nb);
    printf("size + plus:%#+5d\n", nb);
    printf("size + minus:%-5d\n", nb);
    printf("size + 0:%05d\n", nb);
    printf("size + 0 + plus:%+05d\n", nb);
    printf("size + 0 + plus:%0+5d\n", nb);
    printf("size + 0 + prec:%05.3d\n", nb);
    printf("size + 0 + prec + hash:%0#5.0d\n", nb);
    printf("size + minus + prec:%-5.3d\n", nb);
    printf("size + minus + prec + hash:%-#5.0d\n", nb);
    printf("size + plus + 0 + prec:%+05.3d\n", nb);
    printf("size + plus + 0 + prec + hash:%0+#5.0d\n", nb);
    printf("size + espace + zero + prec:%0 5.3d\n", nb);
    printf("size + espace + zero + prec:% 05.3d\n", nb);
    printf("size + espace + zero + prec + hash:%#0 5.0d\n", nb);
    printf("size + minus + plus + prec:%-+5.3d\n", nb);
    printf("size + minus + plus + prec + hash:%-#+5.0d\n", nb);
	return (0);
}
