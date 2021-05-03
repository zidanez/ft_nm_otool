/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:31:48 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:01:46 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*r;

	if (s && f)
	{
		res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!res)
			return (NULL);
		else
		{
			r = res;
			while (*s)
			{
				*res = f(*s);
				s++;
				res++;
			}
			*res = '\0';
		}
		return (r);
	}
	return (NULL);
}
