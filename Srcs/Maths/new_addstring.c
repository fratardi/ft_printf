#include "../../Includes/ft_printf.h"

void	ft_addstrings_stack(char *assign, char *base, int po_assig, int po_base)
{
	po_assig -= (!assign[po_assig]) ? 1 : 0;
	po_base -= (!base[po_base]) ? 1 : 0;
	if (po_assig < 0 || po_base < 0)
		return ;
	if ((((assign[po_assig]) - '0' + (base[po_base] - '0')) <= 9))
	{
		assign[po_assig] = assign[po_assig] + (base[po_base] - '0');
		ft_addstrings_stack(assign, base, --po_assig, --po_base);
	}
	else
	{
		assign[po_assig] = assign[po_assig] + base[po_base] - 10 - '0';
		assign[po_assig - 1]++;
		ft_addstrings_stack(assign, base, --po_assig, --po_base);
	}
	return ;
}

void	ft_init_basex(t_list *base)
{
	base->content = ft_strdup("5");
	base->content_size = 1;
	base->next = NULL;
}

char	*ft_pow2str_stack(int ex, t_list *base)
{
	static int last = 1;

	if (last == 1)
		ft_init_basex(base);
	last = ex;
	return (base->content);
}
