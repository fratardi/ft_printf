#include "../../Includes/ft_printf.h"


int    ft_print_preset_buf(unsigned char c, int n)
{
    static char     lign[BUFF_SIZE];
    int          i;

    i = 0;
	if(n == 0)
		return(0);
    ft_memset(lign, c, BUFF_SIZE);
    while(i < n)
    {
        if((n - i) > BUFF_SIZE)
        {
			//ft_putendl("\nla");
			write( 1, lign, BUFF_SIZE);
			i+= BUFF_SIZE; 
		}
        if((n - i)  <=  BUFF_SIZE)
        {
		//	ft_putendl("\nici");
			write(1,  lign, n - i );
			i += (n - i);
        }
    }
return(i);
}