/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:36:25 by tpacaud           #+#    #+#             */
/*   Updated: 2019/05/23 03:22:56 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

char   *ft_of(char *name)
{
    int         fd;
    static char buf[2049];
    char        *ret;

    ret = NULL;
    if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
    ft_bzero(buf, 2048);
    if (read(fd, buf, 2048))
        ret = ft_strdup(buf);
    ft_bzero(buf, 2048);
    while (read(fd, buf, 2048))
    {
        ret = ft_joinfree(ret, ft_strdup(buf));
        ft_bzero(buf, 2048);
    }
    close(fd);
    return (ret);
}