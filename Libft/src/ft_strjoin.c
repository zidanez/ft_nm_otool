/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:12:26 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:01:06 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	if (s1 && s2)
	{
		i = -1;
		res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!res)
			return (NULL);
		else
		{
			while (++i < (int)ft_strlen(s1))
				res[i] = s1[i];
			while (*s2)
			{
				res[i] = *s2;
				i++;
				s2++;
			}
			res[i] = '\0';
			return (res);
		}
	}
	return (NULL);
}
