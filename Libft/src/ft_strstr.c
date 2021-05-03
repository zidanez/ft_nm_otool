/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:59:23 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:04:53 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*res;
	const char	*s;

	if ((!(*needle)) || (haystack == needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (needle[0] == *haystack)
		{
			res = needle;
			s = haystack;
			while (*(++needle) == *(++haystack) && *needle && *haystack)
			{
			}
			if (*needle == '\0')
				return ((char *)s);
			else
			{
				needle = res;
				haystack = s;
			}
		}
		haystack++;
	}
	return (NULL);
}
