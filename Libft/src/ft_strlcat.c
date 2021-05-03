/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:32:32 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:01:16 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst,
						const char *restrict src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	len;

	size_dst = ft_strlen(dst);
	i = 0;
	len = 0;
	while (dst[len] && len < size)
		len++;
	if (!(len < size))
		return (ft_strlen(src) + size);
	while (src[i] && i < (size - size_dst - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
