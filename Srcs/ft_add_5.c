/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:45:37 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/13 15:52:35 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char    *ft_add_5(char *str)
{
    int    pos;
    int carry;

    carry = 0;
    pos = ft_strlen(str) - 1;
    while( carry != -1 && pos >= 0)
    {
        if(str[pos] <= '4'    && carry == 0)
        {
            str[pos] = str[pos] + 5;
            return(str);
        }
        if(str[pos] >= '5' && carry == 0)
        {
            str[pos]  = str[pos] - 5;
            carry = 1;
            pos--;
        }
        if(str[pos] < '9' && carry == 1)
        {
            str[pos] = str[pos] + 1;
            return(str);
        }
        if (str[pos] == '9' && carry == 1)
        {
            str[pos] = '0';
		}
		if (pos == 0)
				str = ft_strjoin("1", str);
        pos--;
    }
    return(str);
}