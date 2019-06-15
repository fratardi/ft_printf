#include <stdio.h>
#include "Includes/ft_printf.h" 

int main(void)
{
	char *str = "ici c'est la lune";
//	ft_printf("mine % z%%s\n", "cou");
//	printf("real % z%%s\n", "cou");
//	ft_printf("mine %.f\n", 87514.4555458);
//	printf("real %.f\n", 87514.4555458);
	int pint = 42;

	ft_printf("%c %p, %c\n, %c", &pint, "coucou", "", '');
	printf("%c %p, %c\n, %c", &pint, "coucou", "", '');

	return (0);
}
