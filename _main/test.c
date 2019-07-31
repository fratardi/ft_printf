#include "./Includes/ft_printf.h"

int			ft_init_sequence(char *str, t_no_syntax *content)
{
	int i;

	content->extra = 0;
	content->left = 0;
	i = 1;
	while (ft_strchr("-+ 0#", str[i]) && str[i])
	{
		(str[i] == '-') ? (content->left = 1) : 0;
		(str[i] == '0') ? (content->extra = 1) : 0;
		i++;
	}
	content->width = ft_atoi((str + i));
	content->width -= (content->width) ? 1 : 0;
	return (i);
}

size_t		ft_sequence(char *str, int *open, char *s1)
{
	size_t		ret;
	char		*temp;
	char		*pad;
	int			i;
	t_no_syntax	content;

	ret = 0;
	i = ft_init_sequence(str, &content);
	while (ft_strchr(".1234567890", str[i]) && str[i])
		i++;
	if ((s1 && s1[0]) || str[i])
		temp = (str[i]) ? ft_strdup(&str[i]) : ft_memaset(s1[0], 1);
	else
		temp = ft_strdup("");
	!str[i] ? (*open = 0) : 0;
	if (content.width)
		pad = ft_memaset((content.extra) ? '0' : ' ', content.width);
	else
		pad = ft_strdup("");
	temp = (content.left) ? ft_joinfree(temp, pad) : ft_joinfree(pad, temp);
	temp ? (ret += ft_print_uni_str(temp)) : 0;
	(!str[i] && s1 && s1[0]) ? (ret += ft_print_uni_str(&s1[1])) : 0;
	free(temp);
	return (ret);
}

int main(void)
{
	ft_sequence(ft_strdup("%5"), 1, ft_strdup("%"));
	return (0);
}