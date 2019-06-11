/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 23:49:09 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/11 02:06:50 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"



char     *ft_round_ent(char *str)
{
    return(ft_new_addstrings(str, "1"));
}

char     *ft_round_dec(char *str, int prec, int *round_ent)
{
	int		i;
	char	*tmp;
	char	*temp;

    i = prec - 1;
	// printf("str = %s et prec = %d\n", str, prec);
    if (prec > (int)ft_strlen(str))
	{
		while (prec > (int)ft_strlen(str))
			str = ft_joinfree(str, ft_strdup("0"));
		*round_ent = 0;
        return (str);
	}
	// if (prec == 0)
		// return(ft_prec_zero_float(str));
    if (str[i] == '9' && str[i + 1] >= '5' && str[0] == '9')
    {
        while(i > 0 && str[i] == '9')
            i--;
        // printf("i == %d\n", i);
        if (i == 0)
        {
            // printf("ok");
            // free(str);
            str = ft_memaset('0', prec);
            *round_ent = 1;
            return (str);
        }
        // printf("dec = .%s\n", str);
    }
	i = prec;
	if (str[i] == '5' && ((str[i - 1] - 48) % 2 != 0 || str[i + 1] > '5'))
	{
		str[i] = 0;
		tmp = ft_strdup("1");
		temp = ft_new_addstrings(str, tmp);
		// free(str);
		str = temp;
        free(tmp);
	}
    else if (str[i] >='5' && (str[i+1])  )
	{
		str[i] = 0;
		tmp = ft_strdup("1");
		temp = ft_new_addstrings(str, tmp);
		//free(str);
		str = temp;
        free(tmp);
    }
	str[prec] = 0;
	*round_ent = 0;
    return (str);
}

t_double ft_rounding_float(t_double dble, int prec)
{
    int rounding;

    rounding = 0;
    if(prec == -2)
        prec = 6;
    dble.dec = ft_round_dec(dble.dec, prec, &rounding); 
    if(rounding)
    {
        dble.ent = ft_round_ent(dble.ent);
        return(dble);
    }
    return(dble);
}