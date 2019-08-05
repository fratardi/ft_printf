/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_preset_buf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:07:36 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/05 01:44:00 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

/* int	ft_print_preset_buf(unsigned char c, int n)
{
	static char		lign[BUFF_SIZE];
	int				i;

	i = 0;
	if (n == 0)
		return (0);
	ft_memset(lign, c, BUFF_SIZE);
	while (i < n)
	{
		if ((n - i) > BUFF_SIZE)
			i += (int)write(1, lign, BUFF_SIZE);
		if ((n - i) <= BUFF_SIZE)
			i += (int)write(1, lign, n - i);
	}
	return (i);
}
 */
int			ft_print_preset_buf(unsigned char c, int n)
{
    static  char *buff[BUFF_SIZE + 1];
    int ret;

    
    if((ret = n ) <= 0)
        return(0);
    ft_bzero(buff, BUFF_SIZE + 1);
    ft_memset(buff, c, BUFF_SIZE >= n ? n : BUFF_SIZE);
    while(n > 0)
    {
        write(1, buff,  n <= BUFF_SIZE ? n : BUFF_SIZE);
        n -= BUFF_SIZE;
    }
    ft_bzero(buff, BUFF_SIZE);
    return(ret);
}