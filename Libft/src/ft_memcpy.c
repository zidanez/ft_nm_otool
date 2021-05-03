/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:08:11 by fnancy            #+#    #+#             */
/*   Updated: 2019/04/07 20:08:11 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*dst_help;
	unsigned char	*src_help;

	dst_help = (unsigned char *)dst;
	src_help = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_help[i] = src_help[i];
		i++;
	}
	return (dst_help);
}
