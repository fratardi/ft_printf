#include  "../Includes/ft_printf.h"

void	ft_debugf(void)
{
	//printf("% +5.1f\n", -42.3);
	ft_printf("test >> %-+7.1f\n", -42.3);

	printf("vrai >> %-+7.1f\n", -42.3);

	// ft_putendl("orig below");
	/*ft_putendl(ft_itoa(*//*))*/
	// ft_putendl("\ncopy below");
	/*ft_putendl(ft_itoa(*//*))*/
/*	ft_putendl("debut du test");
	
	ft_putendl("orig below");

	ft_putendl(ft_itoa(printf("\n%#012x\n" ,4242)));
	ft_putendl(ft_itoa(ft_printf("\n%#012x\n", 4242)));
	ft_putendl(ft_itoa(ft_printf("\n%#12x\n", 4242)));

	ft_putendl("orig below");
	ft_putendl(ft_itoa(printf("\n%#12x\n", 4242)));
	ft_putendl(ft_itoa(ft_printf("\n%#012x\n", 4242)));	
	ft_putendl("orig below");
	ft_putendl(ft_itoa(printf("\n%#012x\n", 4242)));
*/
}
