/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 00:43:26 by fratardi          #+#    #+#             */
/*   Updated: 2019/03/26 01:05:21 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FT_FLOAT_H
# define	FT_FLOAT_H

typedef struct		s_float64
{
	char 			sig;		/* 8  bits  should hold 1 */
	unsigned short	exp;		/* 16 bits should hold 11 */
	long long		mantissa;	/* 64 bits should hold 53 */
}					t_float64;

typedef	struct		s_float32
{
	char			sig; 		/* 4  bits should hold 1  */
	signed char		exp; 		/* 8  bits should hold 8  */
	int				mantissa; 	/* 32 bits should hold 53 */
}				t_float32;

# endif
