#include "../../Includes/ft_printf.h"

//fonction qui ecrit dans base de content  
void    ft_addstrings(char *assign, char *base, size_t po_assig, size_t po_base)
{
    if(!assign[po_assig]|| !base[po_base])
        return ;
    if( ((assign[po_assig] - '0') + (base[po_base] - '0') < 9))
    {

        assign[po_assig] = assign[po_assig] + base[po_base] - '0';
        ft_addstrings(assign, base, --po_assig , --po_base);
    }
    else
    {
        assign[po_assig] = assign[po_assig] - base[po_base] - '0';
        assign[po_assig - 1]++;
        ft_addstrings(assign, base, --po_assig , --po_base);
    }
    return ;
}

void    ft_neg_pow_of_two(t_list *base, size_t po)
{
    char *assign;
    size_t  i;

    i = 0;
    if( po || po <= base->content_size)
        return ;
    if(!(assign = (char *)ft_memaset('0', po)))
        return ;
    while(po < base->content_size) // fonction pour reach la power 
    {
        while (++i <= 5)
            ft_addstrings(assign ,base->content ,po, base->content_size);
        i = 0;
        po++;
    }
    free (base->content);
    base->content = assign

}


