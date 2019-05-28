#include "../../Includes/ft_printf.h"

void    ft_addstrings_stack(char *assign, char *base, size_t po_assig, size_t po_base)
{
	printf( "CALL addstring po_assign >>%zu<< po_base >>%zu<<base[pobase]>>%c<<assign[poassign]>>%c<<   \n", po_assig, po_base , base[po_base - 1] , assign[po_assig]);
	/*if(!assign[po_assig]|| !base[po_base])
		{
			ft_putendl("return sale ...");
			return ;
		}*/
	if(!po_assig || !po_base)
		{
			printf("finstack\n");
			return;
		}
	if((((assign[po_assig]) - '0' + (base[po_base - 1] - '0'))< 9))
	{
		printf( "NO CARRY before assig    >>%s<<<<   base >>%s<<\n" ,assign, base);
		assign[po_assig] = assign[po_assig]  + (base[po_base - 1] - '0');
		printf( "NO CARRY after assign    >>%s<<     base >>%s<<\n", assign , base);
		ft_addstrings_stack(assign, base, --po_assig , --po_base);
	}
	else
	{
		printf( "CARRY before assig    >>%s<<<<   base >>%s<<\n" ,assign, base);
		 // fix condition below
		printf("diff rez  carry val  >>%zu<< char >>%c<<\n" ,(size_t)(assign[po_assig] + (base[po_base - 1] - 10 - '0')), (assign[po_assig] + (base[po_base - 1] - 10 - '0')));
		assign[po_assig] = assign[po_assig] + base[po_base - 1] - 10 - '0';

		assign[po_assig - 1]++;
			printf( "CARRY after assign    >>%s<<     base >>%s<<\n", assign , base);
		
	
		///
		//assign[po_assig - 1]++;



		ft_addstrings_stack(assign, base, --po_assig , --po_base);
	
	}
	ft_putendl(base);
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
	char	*assign;
	size_t	i;
	size_t	j;

	i = base->content_size;
	ft_init_basex(base);
	if(!po || po < i || !(assign = /*(char *)*/ft_memaset('0', po )))
	{
		printf("PASSE ICI ?\n");
		return ;
	}
//	base->content_size = po;
     
	while(i++ < po)
	{
		j = 0;
		while (++j <= 5)
			{
				ft_addstrings_stack(assign ,base->content, ft_strlen(assign) - 1 , ft_strlen(base->content));
				base->content_size = po;
			}
			free (base->content);
				base->content = assign;
	}
//	free (base->content);

	return ;
}

char	*ft_pow2str_stack(int ex, t_list *base)
{
	// comment initialiser la sequence ???? 
//	static t_list base = ft_init_basex(&base);
	//if (ex == 0)
	//	return (ft_strdup("1"));
	//revoir le return
	//if((ex > 0))
	//	return (ft_pow2c(ex)); 
	ft_neg_pow_of_two(base, (size_t)ex);
	return(base->content);

}