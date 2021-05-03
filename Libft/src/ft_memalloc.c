/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:20:41 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:07:16 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;

	res = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!res)
		return (NULL);
	else
	{
		while (size != 0)
		{
			res[size] = (unsigned char)0;
			size--;
		}
		res[size] = (unsigned char)0;
		return ((void *)res);
	}
}
