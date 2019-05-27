#include "../../Includes/ft_printf.h"

void    ft_addstrings_stack(char *assign, char *base, size_t po_assig, size_t po_base)
{

	printf( "po_assign >>%zu  \n  po_base >>%zu\n", po_assig, po_base );
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
	if((((assign[po_assig]) - '0' + (base[po_base] - '0'))< 9))
	{
		printf( "no carry before assig c >>>%s<<<<   base >>>%s<<<< \n" ,assign, base);
		assign[po_assig] = assign[po_assig] + '0' + (base[po_base] - '0');

		printf( "\n %d no carry after assig c >> assig c >>>%s<<<<   base >>>%s<<<< \n" ,  (int)assign[po_assig]       ,assign, base);

		ft_addstrings_stack(assign, base, --po_assig , --po_base);
	}
	else
	{

		
			printf( "\ncarry before  assig c >>>%s<<<<   base >>>%s<<<<" ,assign, base);
		assign[po_assig] = assign[po_assig] - (base[po_base] + '0');
					printf( "\ncarry  after assig c >>>%s<<<<   base >>>%s<<<< \n" ,assign, base);
		assign[po_assig - 1]++;



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
	base->content_size = po;
     
	while(i++ < po)
	{
		j = 0;
		while (++j <= 5)
			{
				ft_addstrings_stack(assign ,base->content, po  , base->content_size - 1);
				base->content_size = po;
			}
	}
	free (base->content);
	base->content = assign;
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