/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:07:09 by fnancy            #+#    #+#             */
/*   Updated: 2021/05/03 16:02:29 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*s1_beg;

	s1_beg = s1;
	while (*s1)
		s1++;
	while (*s2 && n != 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	*s1 = '\0';
	return (s1_beg);
}
