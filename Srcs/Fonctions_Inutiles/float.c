/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:44:00 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/14 17:26:01 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printhexafloat(float a)
{
	float *ptr;

	ptr = NULL;
	*ptr = a;
	ft_hexfloat(ptr, sizeof(float));
}

void	ft_display_binary_float_content(float d)
{
	unsigned int *temp;
	unsigned int i;
	unsigned int mask;

	i = -1;
	mask = 0x80000000;
	temp = (unsigned int *)&d;
	
	while(++i < 32)
	{
		write( 1, ((*temp/mask))? "1" : "0" ,1);
		*temp = *temp%mask;
		mask = mask >> 1;
		ft_putchar((i == 0 || i == 8) ? '-' : 0);
		ft_putchar((i % 4 == 0 && i != 8 && i) ? ' ' : 0);
	}
	ft_putchar('\n');
}

void	ft_mantifloat(float a)
{
	unsigned int *b;

	b = (unsigned int *)&a;
	*b = *b & 0x7fffff;
	ft_printf("%x -- Mantissa\n", *b);
	ft_printf("%d -- Mantissa\n", *b);
}

/* void	ft_printbits(float a)
{
	int *b;
	int pos;
	int temp;

	pos = 32;
	b = &a;
	while (pos)
	{
		temp = *b & 1 << (pos - 1);
		if (!temp)
			ft_putstr("0");
		else
			ft_putstr("1");
		if (pos == 32 || pos == 24)
			ft_putchar(' ');
		pos--;
	}
} */

char *ft_fenttoa(float a)
{
	char *mantissa;
	int i;
	int ex;
	unsigned long long int temp;
	char *ret;

	if ((unsigned int)a == 0)
		return ("0");
	mantissa = ft_mantissabin(a);
	ex = ft_expfloat(a);
	i = 0;
	temp = ft_pow2(ex--);
	while (mantissa[i] && ex != -1)
	{
		if (mantissa[i] == '1')
			temp += ft_pow2(ex);
		i++;
		ex--;
	}
	ret = ft_ullitoa(temp);
	return (ret);
}

int print128(__uint128_t n)
{
	char str[40] = {0};
	char *s = str + sizeof(str) - 1;

	if (n == 0)
		return printf("0\n");
	while (n != 0)
	{
		if (s == str)
			return -1;

		*--s = "0123456789"[n % 10];
		n /= 10;
	}
	return printf("%s\n", s);
}

unsigned long long int ft_hexadump(float a)
{
	char *mantissa;
	int i;
	int ex;
	__uint128_t temp;
	size_t b;
	char *ret;

	mantissa = ft_mantissabin(a);
	ex = ft_expfloat(a);
	printf("ex = %d - Man = %s\n", ex, mantissa);
	i = 0;
	b = -ex / 32 + 1;
	while (mantissa[i] && ex > -1)
	{
		i++;
		ex--;
	}
	temp = (i == 0) ? 1E16 / ft_pow2(-ex) : 0;
	temp = temp * 1000000;
	ex = (i == 0) ? -ex + 1 : 1;
	i -= (i != 0) ? 1 : 0;
	while (mantissa[i] != 0)
	{
		temp += (mantissa[i] == '1') ? 1E16 / ft_pow2(ex) : 0;
		i++;
		ex++;
	}
	print128(temp);
	return ((unsigned long long int)temp);
}

unsigned int	count_trail_z(unsigned int d)
{
	unsigned int mask;
	unsigned int n;

	n = 0;
	mask = 0x00000001;
	if(!d)
		return(32);
	while(!(d & mask))
	{
		mask = (mask << 1);
		n++;
	}
	return(n);
}

unsigned int	count_lead_z(unsigned int d)	
{
	unsigned int n;
	unsigned int mask;

	mask = 0x80000000;
	n = 0;
	if(!d)
		return(32);
	while(!(d & mask))
	{
		mask = (mask >> 1);
		n++;
	}
	return(n);
}

unsigned int	ft_get_sigi(unsigned int d)
{
	return((d & 0x80000000) ? 1 : 0);
}

unsigned int	ft_get_exp(unsigned int d)
{
	unsigned int truc;

	truc = d;
	return (((unsigned int)truc & 0x7F800000) >> 23);
}

unsigned int	ft_get_mantissa(unsigned int d)
{
	return( (d) & 0x007FFFFF); 
}
