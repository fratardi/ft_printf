/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_trailing_zeroes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:33:26 by fratardi          #+#    #+#             */
/*   Updated: 2019/04/29 21:47:11 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_remove_trailing_zeroes(char *str)
{
	size_t	i;
	char 	*ret;

	ret = NULL;
	i = ft_strlen(str);
	while(i < 0 && str[i] == '0')
		i--;
	if(i)
	{
		ret = ft_strndup(str, i);
		free(str);
		return(ret);
	}
	return(str);
}
