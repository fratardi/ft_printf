
char	*ft_mantissabin(float d)
{
	unsigned int *temp;
	char *f;
	unsigned int i;
	unsigned int pos;
	unsigned int mask;

	i = -1;
	f = (char *)malloc(sizeof(char) * 33);
	mask = 0x80000000;
	temp = (unsigned int *)&d;
	pos = 0;
	while (++i < 32)
	{
		if (i >= 9)
			f[pos++] = ((*temp / mask) ? '1' : '0');
		*temp = *temp % mask;
		mask = mask >> 1;
	}
	return (f);
}

int ft_expfloat(float a)
{
	unsigned int *b;
	b = (unsigned int *)&a;
	*b = (*b & 0x7f800000) >> 23;
	/* ft_printf("%x -- Exp\n", *b); */
	//ft_printf("%d -- Exp\n", (*b - 127));
	//	return ((int)(*b) - 127);
	//	}
	//
	//	unsigned int ft_get_sig(float d)
	//	{
	//		return (d ? (((unsigned int)d & (0x00000001 << 31)) >> 31) : 0);
	//		}
	//
	//
