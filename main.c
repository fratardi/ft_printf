#include "./Includes/ft_printf.h"

int ft_orig(char *format)
{
	printf("orig>");
    int i = printf(format);
    return(i);
}

int ft_copy(char *format)
{
	ft_putstr("copy>");
    int i = ft_printf(format);
    return(i);
}   
int     ft_compare(char *format, int nb)
{
    	printf("\n\nstring to assert %s\n" , format);
    int i = ft_orig(format);

    int j = ft_copy(format);
	ft_putchar('\n');
    if( i != j)
    {
        printf("\nFAIL test no %d orig  = %05d  copy = %05d", nb , i , j);	
        return(1);
    }
        printf("\nSuccess test no %d orig  = %05d  copy = %05d", nb , i , j);

    return(0);
}

void	ft_classictests()
{

	int nb = 14;
	int i = 0;
	int k;
	k = 0;
	char *tab[125];

	tab[0] = "%";
	tab[1] = "%%";
	tab[2] = "%res";
	tab[3] = "%res%res";
	tab[4] = "%res%%res";
	tab[5] = "%%res%res";
	tab[6] = "%%res%%res";
	tab[7] = "%%%";
	tab[8] = "%%%%";
	tab[9] = "%5%truc";
	tab[10] = "%%5truc";
	tab[11] = "truc%%5";
	tab[12] = "5%5%5";
	tab[13] = "%5%5%5	";
	tab[14] = "%";


	while(i <= nb )
	 {
		if( ft_compare(tab[i] , i))
			k++;
			i++;
	}
		printf(  "%d  failed tests out of %d\n",k, i    );
}

int        ft_testleaks(void)
{

/*     ft_printf("%5.1d\n", -52);
    ft_printf("%5.1d\n", -52);

    ft_printf("%#02x\n", 0);
    ft_printf("%#02x\n", 0);

    ft_printf("%d\n",-1);
    ft_printf("%d\n",-1);

    ft_printf("#02o\n", 5);
    ft_printf("#02o\n", 5);
    ft_printf("\n");
    ft_printf("Ycc%#.4X et %#0012x %#04X !!\n", 0xaef, 0xe, (unsigned short)0);
    printf("Occ%#.4X et %#0012x %#05X !!\n", 0xaef, 0xe, (unsigned short)0);
 */
	// ft_printf("%+-0# 12.5d", 13, "", L"〻");
	// printf("test %-7C %007d%-10.2ls!!", 0xd777, "", L"〻");
	// printf(">>%-+-12.7Dt%i %04.2% et %lc titi\n", 124, 124, 256);
	ft_printf(">>%-+-12.7Dt%0 4i %04.2% et %lc titi\n", 124, 124, 256);

	// while(1);
    return(0);
}

int main(void)
{
	//ft_printf("%s", "bonjour" );
//  ft_classictests();
    // ft_compare("%", 1);
	// ft_testleaks();
	ft_printf("\\!/%0#28.2zo\\!/", 0);
	printf("\\!/%0#28.2zo\\!/", 0);
	// printf("!% 012zd!\n", 0);
	return(0);
}