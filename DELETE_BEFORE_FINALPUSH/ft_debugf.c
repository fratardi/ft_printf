#include  "../Includes/ft_printf.h"

void	ft_debugf(void)
{
	ft_putendl("orig below");
	/*ft_putendl(ft_itoa(*/printf("%.1s","bon")/*))*/;
	ft_putendl("\ncopy below");
	/*ft_putendl(ft_itoa(*/ft_printf("%.1s", "bon")/*))*/;
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