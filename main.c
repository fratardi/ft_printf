#include "./Includes/ft_printf.h"
#include <stdio.h>

/* Main de tests - Tout les commentaires sont a implémenter, ils segfaults ou ne fontionnent pas */

int main(void)
{
	char *s1;
	char *s2;

	//ft_printf("%s + %s = %s\n", s1, s2, ft_addstrings(s1, s2));
	int i = 1;

/* 	while (i++ != 30)
	{
		s1 = ft_strdup("2147483647");
		s2 = ft_ullitoa(i);
		ft_adjustpospo(&s1, &s2);
		ft_printf("{%s + %s} = ", s1, s2);
		ft_putendl(ft_addstrings(s1, s2));
	} */
	//ft_floatt(1.1754945E-38);
	//ft_double(1.1754945E-38);
	printf("Vrai__>> %.250f\n", 1.1754945E-38);

	//ft_printf("%s __ %u\n", ft_mantissaldouble(1.1754945E-38),ft_strlen(ft_mantissaldouble(1.1754945E-38)));
	//ft_hexfloat(&a, sizeof(long double));
	//printf("exp_ldouble %d\n", ft_expldouble((long double)2.1));
	//ft_ldouble(1.17549);
	ft_printf("Nous__>> %Lf\n", 1.1754945E-38L);
//	ft_floatEdisp("0.0000000541", 2);
	//ft_printf("Bin double >> %s\n", ft_mantissadouble((double)1.1754945E-38));
	//ft_printf("Rounding for %d__%s\n", 2, ft_rounding(ft_floatt(1.5656), 2));
	//ft_printf("Bin = %s\n", ft_bin(2147483647, 64));
	return (0);
}


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

		/* Fonction de DEBUG */
	//ft_debug("Something Happen %d %d %d\n", 11, 10, 9);
