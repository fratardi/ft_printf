#include "libft.h"
void	*ft_memaset(int c, size_t n)
{
	unsigned char *ret;

	if(!(ret = (unsigned char *)ft_memalloc(n + 1)))
		return(NULL);
	return(ret = ft_memset(ret, c, n));
}
