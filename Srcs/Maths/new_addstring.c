#include "../../Includes/ft_printf.h"

void    ft_addstrings_stack(char *assign, char *base, int po_assig, int po_base)
{
	po_assig -= (!assign[po_assig]) ? 1 : 0;
	po_base -= (!base[po_base]) ? 1 : 0;
	//printf( "CALL addstring po_assign >>%zu<< po_base >>%zu<<base[pobase]>>%c<<assign[poassign]>>%c<<   \n", po_assig, po_base , base[po_base - 1] , assign[po_assig]);
	/*if(!assign[po_assig]|| !base[po_base])
		{
			ft_putendl("return sale ...");
			return ;
		}*/
	if(po_assig < 0 || po_base < 0)
		{
			// printf("finstack %s\n", assign);
			return;
		}
	if((((assign[po_assig]) - '0' + (base[po_base] - '0'))<= 9))
	{
	// printf( "NO CARRY before assig	>>%s<<	base >>%s<<\n" ,assign, base);
		assign[po_assig] = assign[po_assig]  + (base[po_base] - '0');
	//printf( "NO CARRY after assign	>>%s<<	base >>%s<<\n", assign , base);
		ft_addstrings_stack(assign, base, --po_assig , --po_base);
	}
	else
	{
	//printf( "CARRY before assig	>>%s<<<<   base >>%s<<\n" ,assign, base);
		 // fix condition below
	// printf("CARRY DIFF diff rez carry val	>>%zu<< char >>%c<<\n" ,(size_t)(assign[po_assig] + (base[po_base - 1] - 10 - '0')), (assign[po_assig] + (base[po_base - 1] - 10 - '0')));
		assign[po_assig] = assign[po_assig] + base[po_base] - 10 - '0';
		assign[po_assig - 1]++;
	//printf( "CARRY after assign	>>%s<<     base >>%s<<\n", assign , base);
		///
		//assign[po_assig - 1]++;
		ft_addstrings_stack(assign, base, --po_assig , --po_base);
	}
	//ft_putendl(base);
	return ;
}


void	ft_init_basex(t_list *base)
{
	base->content = ft_strdup("5");
	base->content_size = 1;
	base->next = NULL;
}


void	ft_neg_pow_of_two(t_list *base, size_t po)
{
	char	*assign = NULL;
	static int last = 1;
	size_t	i;
	size_t	j;

	i = base->content_size;
	if(!po || po < i)
	{
		// printf("PASSE ICI ?\n");
		if (!po)
			base->content = ft_strdup("0");
		return ;
	}
	if (last == 1)
	{
		assign = /*(char *)*/ft_memaset('0', po);
	}
	else
		assign = ft_joinfree(ft_memaset('0', po - last), assign);
	printf("pow == %zu et i == %zu\n", po, i);
//	base->content_size = po;
     
	while(i++ < po)
	{

		if(base->content_size > 1)
			j = 1;
		else
			j = 0;
		
		while (j++ <= 4)
			{
	//			printf("before add string po val %zu   val j>>%zu<<\n", po, j);
	//			printf("\nassignp assign >>%s<<base >>%s<<\n", assign, base->content);
				// printf("base->content>>%s<<\n", base->content);
				ft_addstrings_stack(assign , base->content, ft_strlen(assign) , ft_strlen(base->content));
				printf("base->content = %s\n", assign);
				base->content_size = po;
			}

			free (base->content);
			base->content = ft_strdup(assign);

	}
//	free (base->content);

	last = po;
	return ;
}

char	*ft_pow2str_stack(int ex, t_list *base)
{
	static int last = 1;

	if (last == 1)
		ft_init_basex(base);
	// comment initialiser la sequence ???? 
//	static t_list base = ft_init_basex(&base);
	//if (ex == 0)
	//	return (ft_strdup("1"));
	//revoir le return
	//if((ex > 0))
	//	return (ft_pow2c(ex)); 
	last = ex;
	printf("power = %i et exbase = %s\n", ex, base->content);
	// ft_neg_pow_of_two(base, (size_t)ex);
	// ft_pow_negativ(ex, ft_strdup(base->content), base);
	printf("base = %s\n", base->content);
	return(base->content);

}