

void ft_padding_digit(t_printinfo *list)
{
	int width;
	int prec;
	int len;

	if (list->showsign && list->buf[0] != '-')
		list->buf = ft_strjoinfree(ft_strdup("+"), list->buf);
	else if (list->space && list->buf[0] != '-')
	{
		list->buf = ft_strjoinfree(ft_strdup(" "), list->buf);
		list->width--;
	}
	len = (int)ft_strlen(list->buf);
	prec = list->prec;
	if (prec < len)
	{
		list->buf[list->prec] = 0;
		len = (int)ft_strlen(list->buf);
	}
	width = list->width - len - 1;
	while (width >= 0 && !list->left)
	{
		list->buf = ft_strjoinfree(ft_strdup(list->extra ? "0" : " "), list->buf);
		width--;
	}
	while (width >= 0 && list->left)
	{
		list->buf = ft_strjoinfree(list->buf, ft_strdup(" "));
		width--;
	}
}
