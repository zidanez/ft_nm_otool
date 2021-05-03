/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:19:25 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:02:51 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptrdst;

	ptrdst = dst;
	while (*src && len)
	{
		*(ptrdst++) = *(src++);
		len--;
	}
	while (len)
	{
		*(ptrdst++) = 0;
		len--;
	}
	return (dst);
}
