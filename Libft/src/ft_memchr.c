/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:39:00 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 15:57:01 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = NULL;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			res = &((unsigned char *)s)[i];
			return (res);
		}
		i++;
	}
	return (NULL);
}
