#include "./Includes/ft_printf.h"

int main(void)
{
    long double		nb;

	ft_printf("n$ - inverse = %2$s %1$s\n", "1st_String", "2nd_String");
	ft_printf("Scientific = %Ef\n", 1.234567E-100);
	ft_printf("Binary (int) = %b\n", 1);
	ft_printf("Binary (str){hello} = %B\n", "hello");
	ft_printf("Octal Upper = %O\n", 42);
	ft_printf("Unsigned Upper = %U\n", 42);
	ft_printf("size_t = %zu\n", (size_t)42);
	ft_printf("Unicodes = 𝟜𝟚 et %s\n", "😀");
    ft_printf("\nFloats_excepion >> Real After\n\n");
	nb = 1.0L/0.0L;
	ft_printf("%5.9Lf\n", nb);
	printf("%5.9Lf\n", nb);
    nb = -1.0/0.0;
	ft_printf("%-12Lf\n", nb);
	printf("%-12Lf\n", nb);
	nb = 0.0L/0.0L;
	ft_printf("%12Lf\n", nb);
	printf("%12Lf\n", nb);
	nb = -0.0L;
	ft_printf("%Lf\n", nb);
	printf("%Lf", nb);
	ft_printf("\n\nFLOATS\n");
	ft_printf("YOUR >> %.200f\n", 1.3E-140);
	printf("REAL >> %.200f\n", 1.3E-140);
    return(0);
}