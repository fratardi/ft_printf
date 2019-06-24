#include "includes/ft_printf.h"

int main(void)
{
	char *nb = "testing";

	ft_printf("size + minus + prec:%-15.1p|\n", nb);
	printf("size + minus + prec:%-15.1p|\n", nb);
	return (0);
}
