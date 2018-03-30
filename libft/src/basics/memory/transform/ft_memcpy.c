/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:46 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:50:45 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = (char *)dst;
	sp = (const char *)src;
	while (n--)
		*dp++ = *sp++;
	return (dst);
}
