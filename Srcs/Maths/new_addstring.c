#include "../../Includes/ft_printf.h"

//fonction qui ecrit dans base de content  
void    ft_addstrings(char *assign, char *base, size_t po_assig, size_t po_base)
{
    if(!assign[po_assig]|| !base[po_base])
        return ;
    if(((assign[po_assig] - '0') + (base[po_base] - '0') < 9))
    {

        assign[po_assig] = assign[po_assig] + (base[po_base] - '0');
        ft_addstrings(assign, base, --po_assig , --po_base);
    }
    else
    {
        assign[po_assig] = assign[po_assig] - (base[po_base] - '0');
        assign[po_assig - 1]++;
        ft_addstrings(assign, base, --po_assig , --po_base);
    }
    return ;
}

void    ft_neg_pow_of_two(t_list *base, size_t po)
{
    char *assign;
    size_t  i;
    size_t  j;

    i = base->content_size;
    if( !po || po <= i || !(assign = (char *)ft_memaset('0', po)))
        return ;
    while(i++ < po)
    {
        j = 0;
        while (++j <= 5)
            ft_addstrings(assign ,base->content, po, base->content_size);
    }
    free (base->content);
    base->content = assign;
    return ;
}
