#include "../includes/ft_printf.h"
#include <float.h>

int main(void)
{
	ft_printf("R> %b\n", 3.75L);
	// ft_printf("%.2147483647Ef\n", 3.75);
	// long double b = 3.75L;
	// ft_displaybin(&b, 10);
/* 	char *nb = "testing"
	ft_printf("size + minus + prec:%-15.1p|\n", nb);
	printf("size + minus + prec:%-15.1p|\n", nb); */
	return (0);
}
