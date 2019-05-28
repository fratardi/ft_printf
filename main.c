/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:41:15 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/29 00:22:10 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/ft_printf.h"

int main(void)
{
	unsigned char	nb;
	nb = 255;
	ft_printf("%hhx\n", nb);
	ft_printf("test X:%hhx\n", nb);
	ft_printf("Hash:%#hhx\n", nb);
	ft_printf("prec / grande:%.5hhx\n", nb);
	ft_printf("hash + prec / grande:%#.5hhx\n", nb);
	ft_printf("hash + prec / petite:%#.1hhx\n", nb);
	ft_printf("prec + 0: %0.5hhx\n", nb);
	ft_printf("Prec + minus:%-.5hhx\n", nb);
	ft_printf("size:%5hhx\n", nb);
	ft_printf("size + prec:%7.3hhx\n", nb);
	ft_printf("size + mminus:%-5hhx\n", nb);
	ft_printf("size + 0:%05hhx\n", nb);
	ft_printf("size + 0 + hash:%#05hhx\n", nb);
	ft_printf("size + 0 + prec:%05.3hhx\n", nb);
	ft_printf("size + minus + prec:%-5.3hhx\n", nb);
	ft_printf("size + hash + 0 + prec:%#05.3hhx\n", nb);
	ft_printf("size + hash + 0 + prec:%0#5.3hhx\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3hhx\n", nb);

	printf("%hhx\n", nb);
	printf("test X:%hhx\n", nb);
	printf("Hash:%#hhx\n", nb);
	printf("prec / grande:%.5hhx\n", nb);
	printf("hash + prec / grande:%#.5hhx\n", nb);
	printf("hash + prec / petite:%#.1hhx\n", nb);
	printf("prec + 0: %0.5hhx\n", nb);
	printf("Prec + minus:%-.5hhx\n", nb);
	printf("size:%5hhx\n", nb);
	printf("size + prec:%7.3hhx\n", nb);
	printf("size + mminus:%-5hhx\n", nb);
	printf("size + 0:%05hhx\n", nb);
	printf("size + 0 + hash:%#05hhx\n", nb);
	printf("size + 0 + prec:%05.3hhx\n", nb);
	printf("size + minus + prec:%-5.3hhx\n", nb);
	printf("size + hash + 0 + prec:%#05.3hhx\n", nb);
	printf("size + hash + 0 + prec:%0#5.3hhx\n", nb);
	printf("size + hash + minus + prec:%-#7.3hhx\n", nb);

/* 	printf("%hx\n\n", nb);
	printf("test X:%hx\n\n", nb);
	printf("Hash:%#hx\n\n", nb);
	printf("prec / grande:%.5hx\n\n", nb);
	printf("hash + prec / grande:%#.5hx\n\n", nb);
	printf("hash + prec / petite:%#.1hx\n\n", nb);
	printf("prec + 0: %0.5hx\n\n", nb);
	printf("Prec + minus:%-.5hx\n\n", nb);
	printf("size:%5hx\n\n", nb);
	printf("size + prec:%7.3hx\n\n", nb);
	printf("size + mminus:%-5hx\n\n", nb);
	printf("size + 0:%05hx\n\n", nb);
	printf("size + 0 + hash:%#05hx\n\n", nb);
	printf("size + 0 + prec:%05.3hx\n\n", nb);
	printf("size + minus + prec:%-5.3hx\n\n", nb);
	printf("size + hash + 0 + prec:%#05.3hx\n\n", nb);
	printf("size + hash + 0 + prec:%0#5.3hx\n\n", nb);
	printf("size + hash + minus + prec:%-#7.3hx\n\n", nb); */
	return (0);
}
