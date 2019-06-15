#include "./Includes/ft_printf.h"

int main(void)
{
	char *nb = "testing";

	ft_printf("size + minus + prec:%-15.11p|\n", nb);
	printf("size + minus + prec:%-15.11p|\n", nb);
	return (0);
}
