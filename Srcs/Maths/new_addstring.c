#include "../../Includes/ft_printf.h"

void    ft_addstrings_stack(char *assign, char *base, size_t po_assig, size_t po_base)
{

//printf( "po_assign>>%zu<<assign>>%s<<\npo_base >>%zu<<base>>%s<<\n", po_assig ,  &assign[po_assig],po_base, &base[po_base] );
	/*if(!assign[po_assig]|| !base[po_base])
		{
			ft_putendl("return sale ...");
			return ;
		}*/
	if(!po_assig || !po_base)
		{
			printf("ENDADD\n");
			return;
		}
	printf("\nENTREE ADDSTRING po_base>%zu<< po_assign>>%zu<< assig s>>%s<< base s >>%s<< basec >>%c<< assigc >>%c<<\n", po_base, po_assig, base, assign, base[po_base], assign[po_assig -1 ] );
	if((((assign[po_assig-1]) - '0' + (base[po_base-1] - '0'))< 9))
	{
	printf("NoCarry before po_base>%zu<< po_assign>>%zu<< assig s>>%s<< base s >>%s<< basec >>%c<< assigc >>%c<<\n", po_base, po_assig, base, assign, base[po_base], assign[po_assig] );
		assign[po_assig - 1] = /*assign[po_assig] + '0' +*/ (base[po_base-1] /*- '0'*/);
	printf("NoCarry after  po_base>%zu<< po_assign>>%zu<< assig s>>%s<< base s >>%s<< basec >>%c<< assigc >>%c<<\n", po_base, po_assig, base, assign, base[po_base], assign[po_assig] );

		ft_addstrings_stack(assign, base, --po_assig , --po_base);
	}
	else
	{
		printf( "OK carry  assign>>%s<<base>>%s<<\n" ,assign, base);
		assign[po_assig] = assign[po_assig] - (base[po_base] + '0');
		printf( "OK carry  after assig c assig c>>%s<<base >>%s<<\n" , &assign[po_assig], assign);
		assign[po_assig - 1]++;

		ft_addstrings_stack(assign, base, --po_assig , --po_base);
	
	}
	ft_putendl(base);
	return ;
}

/*
void	ft_init_basex(t_list *base)
{
	base->content = ft_strdup("5");
	base->content_size = 1;
	base->next = NULL;
}
*/


void	ft_neg_pow_of_two(t_list *base, size_t po)
{
	char	*assign;
	size_t	i;
	size_t	j;

	i = base->content_size;
//	ft_init_basex(base);
	if(!po || po < i || !(assign = /*(char *)*/ft_memaset('0', po )))
	{
		printf("PASSE ICI 1?\n");
		return ;
	}
	base->content_size = po;
     
	while(i++ < po)
	{
		j = 0;
		while (++j <= 5)
			{
				ft_addstrings_stack(assign ,base->content, po  , base->content_size);
				printf("PASSED    maddtring stack result? basecontent >>%s<< assig >>%s<<\n",base->content, assign);
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
	//static t_list base = ft_init_basex(&base);
	//if (ex == 0)
	//return (ft_strdup("1"));
	//revoir le return
	//if((ex > 0))
	//return (ft_pow2c(ex)); 
	ft_neg_pow_of_two(base, (size_t)ex);
	return(base->content);

}