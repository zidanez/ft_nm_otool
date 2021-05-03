/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:23:08 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:03:43 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle,
							size_t len)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	if (!(*needle))
		return ((char *)haystack);
	while (i++ < (int)len && haystack[i])
	{
		if (needle[0] == haystack[i])
		{
			j = i;
			k = 0;
			while (needle[k] == haystack[i] && i < (int)len && needle[k])
			{
				i++;
				k++;
			}
			if (needle[k] == '\0')
				return ((char *)&haystack[j]);
			else
				i = j;
		}
	}
	return (NULL);
}
