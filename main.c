#include "./Includes/ft_printf.h"
#include <stdio.h>

/* Main de tests - Tout les commentaires sont a implémenter, ils segfaults ou ne fontionnent pas */

int main(void)
{
	/* Fonction de DEBUG */
	//ft_debug("Something Happen %d %d %d\n", 11, 10, 9);

	//ft_printf("TEST = %d %d\n", 12, 11, 88, 110);
	

	char *s1 = ft_strdup("333");
	char *s2 = ft_strdup("9");
	int po;

/* 	while (po != 500)
	{
		printf("%s + %s = ", s1, s2);
		printf("%s = ", ft_addstrings(s1, s2));
		printf("%s + %s\n", s1, s2);
		po++;
	} */
	printf("addstrings = %s et s1 = %s s2 = %s\n", ft_addstrings(s1, s2), s1, s2);
	printf("pow2neg = 0.%s\n", ft_pow2neg(11));	
/* 	while (po != 50)
	{
		//ft_printf("pow5 = %s\n", ft_pow5(po));
		//ft_printf("pow2neg = 0.%s\n", ft_pow2neg(po));
		po++;
	} */
/* 	printf(".%s _ NOUS\n", ft_floatt(3.1));
	printf("%.80f _ VRAI\n", 3.1); */

	/*ft_fillbig(s1, s2);
	printf("add - {%s}\n", ft_addstrings(s1, s2)); */
/* 	int pow = 11;
	
	ft_putendl(ft_addstrings(s1, s2));
	printf("pow = 0.%s\n",ft_decimal(15.4375)); */

	/* Fichier TESTS */
	/* 	ft_putendl("\n\n\nTESTS COMPLET - <Return>");
	getchar();
	tests(); */
	//while(1);
	return (0);
}
