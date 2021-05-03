/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:01:47 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 15:58:51 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (ft_strlen(src) < ft_strlen(dst))
	{
		while (i < ft_strlen(dst))
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
